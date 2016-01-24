cmake_minimum_required (VERSION 2.6)
project (MyNavi)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# does this system provide the log and exp functions?
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/Config.h.in"
  "${PROJECT_BINARY_DIR}/Config.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories ("${PROJECT_BINARY_DIR}")

# add the MathFunctions library?
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif ()

# add the executable
add_executable (MyNavi main.cpp)
target_link_libraries (MyNavi  ${EXTRA_LIBS})

# add the install targets
install (TARGETS MyNavi DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/Config.h"
  DESTINATION include)

# enable testing
enable_testing ()

# does the application run
add_test (Runs MyNavi 25)

# does the usage message work?
add_test (Usage MyNavi)
set_tests_properties (Usage
  PROPERTIES
  PASS_REGULAR_EXPRESSION "Usage:.*number"
  )

#define a macro to simplify adding tests
macro (do_test arg result)
  add_test (Comp${arg} MyNavi ${arg})
  set_tests_properties (Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endmacro ()

# do a bunch of result based tests
do_test (25 "25 is 5")
do_test (-25 "-25 is 0")
do_test (0.0001 "0.0001 is 0.01")

