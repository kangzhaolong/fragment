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
	Fl_Window *window = new Fl_Double_Window(1920,720);
	
	
	
	MainScreen* mainscreen = new MainScreen(0,0,1920,720);
	window->end();
	
	
	
	
	window->show(0, NULL);
	
	Fl::run();
}
int CMainWindow::Run()
{
	
}
