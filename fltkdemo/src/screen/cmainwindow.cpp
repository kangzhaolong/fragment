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
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

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
	Fl_Window *window = new Fl_Window(1280,720);
	Fl_Box *box = new Fl_Box(20,40,300,100,"Hello, World!");
	box->box(FL_UP_BOX);
	box->labelfont(FL_BOLD+FL_ITALIC);
	box->labelsize(36);
	box->labeltype(FL_SHADOW_LABEL);
	
	Fl_Box *box1 = new Fl_Box(24,80,300,100," World!");
	//Fl_Widget* w = new Fl_Widget(400, 150, 400, 100, "widget");
	box1->box(FL_NO_BOX);
	box1->labelfont(FL_BOLD+FL_ITALIC);
	box1->labelsize(36);
	box1->labeltype(FL_SHADOW_LABEL);
	
	window->end();
	window->show(0, NULL);
	Fl::run();
}
int CMainWindow::Run()
{
	
}
