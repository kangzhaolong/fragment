// generated by Fast Light User Interface Designer (fluid) version 1.0305

#ifndef CKeyBoard_h
#define CKeyBoard_h
#include <FL/Fl.H>
int main(int args,char** argv);
#include <FL/Fl_Double_Window.H>
#include <dbus/dbus.h>
#include <stdio.h>
#include <stdlib.h>
#include <FL/Fl_Input.H>
#include <FL/Fl_Pack.H>
#include <FL/Fl_Button.H>

class CVKeyBoard : public Fl_Double_Window {
  void _CVKeyBoard();
public:
  CVKeyBoard(int X, int Y, int W, int H, const char *L = 0);
  CVKeyBoard(int W, int H, const char *L = 0);
  CVKeyBoard();
  Fl_Input *m_Lable;
private:
  inline void cb_UP_i(Fl_Button*, void*);
  static void cb_UP(Fl_Button*, void*);
  inline void cb_LEFT_i(Fl_Button*, void*);
  static void cb_LEFT(Fl_Button*, void*);
  inline void cb_RIGHT_i(Fl_Button*, void*);
  static void cb_RIGHT(Fl_Button*, void*);
  inline void cb_DOWN_i(Fl_Button*, void*);
  static void cb_DOWN(Fl_Button*, void*);
  inline void cb_A_i(Fl_Button*, void*);
  static void cb_A(Fl_Button*, void*);
  inline void cb_B_i(Fl_Button*, void*);
  static void cb_B(Fl_Button*, void*);
  inline void cb_C_i(Fl_Button*, void*);
  static void cb_C(Fl_Button*, void*);
  inline void cb_D_i(Fl_Button*, void*);
  static void cb_D(Fl_Button*, void*);
  inline void cb_E_i(Fl_Button*, void*);
  static void cb_E(Fl_Button*, void*);
};
#endif
