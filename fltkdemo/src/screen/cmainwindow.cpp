/*
 * cmainwindow.cpp
 * 
 * Copyright 2019 kalong <kalong@EE>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include "cmainwindow.h"
#include <iostream>

#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include "CMainScreen.h"
#include "CSettingScreen.h"
#include "CButton_Custom.h"
#include "ccontrolmybutton.h"
#include  <FL/fl_draw.H>
#include <FL/x.H>

//#define FL_FLAT_BOX FL_FREE_BOXTYPE

void xyz_draw(int x, int y, int w, int h, Fl_Color c) {
	fl_color(0x373737);
	fl_rectf(x, y, w, h);
	//fl_color(0x00FF00);
	//fl_rect(x, y, w, h);
}


using namespace std;
CMainWindow::CMainWindow()
{
	
}


CMainWindow::~CMainWindow()
{
	
}
void CMainWindow::CreateMainWin()
{
	cout<<"CMainWindow::CreateMainWin"<<endl;
	Fl::set_boxtype(FL_FLAT_BOX, xyz_draw, 1, 1, 2, 2);
	
	
	
	Fl_Window *window = new Fl_Double_Window(1080,600);
	
	CMainScreen* mainscreen = new CMainScreen(0,0,1920,720);
	
	CSettingScreen* settingscreen = new CSettingScreen(0,0,1920,720);
	settingscreen->hide();
	//CMyButton* mybtn = new CMyButton(500,400,300,300,"Button 1");
	//Fl_Button* btn = new Fl_Button(0,0,100,50,"show");
	
	CControlMyButton* mybutton = new CControlMyButton(0,100,100,50,"MyButton");
	
	
	window->end();
	
	
	
	
	window->show(0, NULL);
	
	
}
int CMainWindow::Run()
{
	Fl::run();
	return 0;
}
