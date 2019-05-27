/*
 * cscreenmanager.cpp
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


#include "cscreenmanager.h"
#include <iostream>
using namespace std;

CScreenManager* CScreenManager::m_instance = new CScreenManager();

CScreenManager* CScreenManager::GetInstance()
{
    return m_instance;
}
CScreenManager::CScreenManager():
m_pMainWin(NULL)
{
	cout<<"CScreenManager"<<endl;
}


CScreenManager::~CScreenManager()
{
	cout<<"~CScreenManager"<<endl;
}
int CScreenManager::Init()
{
	cout<<"CScreenManager Init"<<endl;
	if(m_pMainWin == NULL)
	{
		m_pMainWin=new CMainWindow();
	}
	
	return 0;
}
int CScreenManager::Create()
{
	cout<<"CScreenManager Create"<<endl;
	if(m_pMainWin!=NULL)
	{
		
		m_pMainWin->CreateMainWin();
	}
	
	return 0;
}
int CScreenManager::Run()
{
	cout<<"CScreenManager Run"<<endl;
	if(m_pMainWin!=NULL)
	{
		m_pMainWin->Run();
	}
	return 0;
}
int CScreenManager::Destroy()
{
	cout<<"CScreenManager Destroy"<<endl;
	if(m_pMainWin !=NULL)
	{
		delete m_pMainWin;
		m_pMainWin = NULL;
	}
	return 0;
}
