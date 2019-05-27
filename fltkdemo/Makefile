

 
VPATH := ./src: ./include: ./src/screen : ./include/screen: ./src/control: ./include/control: ./src/utility: ./include/utility

 
vpath *.cpp .
vpath *.cpp ./src 
vpath *.cpp ./src/screen
vpath *.cpp ./src/control
vpath *.cpp ./src/utility
vpath *.h .
vpath *.h ./include 
vpath *.h ./include/screen
vpath *.h ./include/control
vpath *.h ./include/utility
 
SRC+=$(shell ls *.cpp)
SRC+=$(shell ls ./src/*.cpp)
SRC+=$(shell ls ./src/screen/*.cpp)
SRC+=$(shell ls ./src/control/*.cpp)
SRC+=$(shell ls ./src/utility/*.cpp)
 
OBJS=$(patsubst %.cpp,%.o, $(SRC))

DEVICE=
ifdef DEVICE
ROOTFS=/opt/Rasp/rootfs
TOOLCHAIN=/opt/workspace/Raspberry/raspberry_chaintool/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin

CROSS_COMPILE	  =$(TOOLCHAIN)/arm-linux-gnueabihf-
CC				  =$(CROSS_COMPILE)gcc
CXX				  =$(CROSS_COMPILE)g++
AR                =$(CROSS_COMPILE)ar cqs
OBJCOPY           =$(CROSS_COMPILE)objcopy
NM                =$(CROSS_COMPILE)nm -P
STRIP             =$(CROSS_COMPILE)strip
LD				  =$(CROSS_COMPILE)ld


CXXFLAGS +=  -I . -I ./include -I ./include/screen -I ./include/control -I ./include/utility\
			-I$(ROOTFS)/usr/include/arm-linux-gnueabihf\
			-I$(ROOTFS)/usr/include \
			-I$(ROOTFS)/usr/include/libpng16 \
			-I$(ROOTFS)/usr/include/freetype2 \
			-D_LARGEFILE_SOURCE \
			-D_LARGEFILE64_SOURCE \
			-D_FILE_OFFSET_BITS=64 \
			-D_THREAD_SAFE -D_REENTRANT\
			-I/opt/Rasp/cross_FLTK/include
CXXLIBS += 	-L . -L ./lib\
			-L$(ROOTFS)/lib/arm-linux-gnueabihf \
			-L$(ROOTFS)/usr/lib/arm-linux-gnueabihf \
			-L/opt/Rasp/cross_FLTK/lib  \
			-ldbus-1 \
			-lfltk -lxcb -lXfixes -lXext -lXau -lXdmcp -lbsd -lpthread -ldl -lm -lX11 -lfltk_forms  -lfltk_images -lfltk_jpeg -lstdc++
else
CXXFLAGS += -I . -I ./include -I ./include/screen -I ./include/control -I ./include/utility\
			-I/usr/include/dbus-1.0\
			-I/usr/lib/x86_64-linux-gnu/dbus-1.0/include \
			-I/opt/Rasp/UbuntuHost/FLTK/usr/local/include\
			-I/usr/include/freetype2 -I/usr/include/libpng16 -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_THREAD_SAFE -D_REENTRANT
CXXLIBS +=	-L . -L ./lib\
			-L/opt/Rasp/UbuntuHost/FLTK/usr/local/lib \
			-ldbus-1 \
			-lfltk -lXrender -lXcursor -lXfixes -lXext -lXinerama -lpthread -ldl -lm -lX11 -lfltk_forms -lfltk_gl -lfltk_images -lfltk_jpeg -lstdc++ 
endif






.PHONY: all clean run fluid keyboard




all: $(OBJS)
	$(CXX) -o ./bin/$@  $^ ${CXXFLAGS}  ${CXXLIBS}
	echo $(OBJS)
clean:
	$(RM) -rf *.o
	$(RM) -rf ./bin/*
	$(RM) -rf ./src/*.o
	$(RM) -rf ./src/screen/*.o
	$(MAKE) -C ./VControlPanel  clean
run:
	./bin/all

keyboard:
	$(MAKE) -C ./VControlPanel  vk

fluid:CButton_Custom.fl CButton_Custom.fl CButton_Custom.fl
	fluid  -o src/screen/CMainScreen.cpp -h include/screen/CMainScreen.h  -c src/screen/CMainScreen.fl
	fluid  -o src/screen/CButton_Custom.cpp -h include/screen/CButton_Custom.h -c src/screen/CButton_Custom.fl
	fluid  -o src/screen/CSettingScreen.cpp -h include/screen/CSettingScreen.h -c src/screen/CSettingScreen.fl
	fluid  -o src/control/CControlList.cpp -h include/control/CControlList.h -c src/control/CControlList.fl
	fluid  -o src/control/CControlButton.cpp -h include/control/CControlButton.h -c src/control/CControlButton.fl
	//  fluid  -o ../src/control/resource.cpp -h ../include/control/resource.h -c resource.fl


%.o: %.cpp
	$(CXX) -o $@ -c $<  ${CXXFLAGS}  ${CXXLIBS}
	


