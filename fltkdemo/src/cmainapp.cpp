/*
 * cmainapp.cpp
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


#include "cmainapp.h"
//#include "mainwindow.h"
#include "cscreenmanager.h"
#include "clayermanager.h"

#include <iostream>
using namespace std;


CMainApp* CMainApp::m_instance = new CMainApp();

CMainApp::CMainApp():
 //   m_pWin(NULL),
	m_pScreenMgr(NULL),
	m_pLayerMgr(NULL)
{
	}
//CMainApp::CMainApp(const MainApp&){};
//CMainApp& CMainApp::operator=(const MainApp&){};//禁止赋值
CMainApp::~CMainApp()
{

}
CMainApp* CMainApp::GetInstance()
{
    return m_instance;
}
int CMainApp::Init()
{
    cout << "MainApp::Init!"<< endl;

    if(m_pLayerMgr == NULL)
    {
       m_pLayerMgr  = CLayerManager::GetInstance();
       m_pLayerMgr->Init();

    }
    if(m_pScreenMgr == NULL)
    {
       m_pScreenMgr  =  CScreenManager::GetInstance();
       m_pScreenMgr->Init();

    }
   /* if(m_pWin == NULL)
    {
        m_pWin = new MainWindow(m_pLayerMgr,m_pScreenMgr,NULL);
    }*/
    return 0;
}
int CMainApp::Create()
{   cout << "MainApp::Create!" << endl;

   /* if(m_pLayerMgr!=NULL)
    {
        m_pLayerMgr->Create();
    }*/
    if(m_pScreenMgr!=NULL)
    {
        m_pScreenMgr->Create();
    }
    //m_pWin->show();
    return 0;
}
int CMainApp::Destroy()
{
    cout << "MainApp::Destory!" << endl;
   if(m_pScreenMgr!=NULL)
    {
        m_pScreenMgr->Destroy();
        delete m_pScreenMgr;
        m_pScreenMgr = NULL;
    }
    if(m_pLayerMgr!=NULL)
    {
        m_pLayerMgr->Destroy();
        delete m_pLayerMgr;
        m_pLayerMgr = NULL;
    }
   /* if(m_pWin!=NULL)
    {
        delete m_pWin;
        m_pWin = NULL;
    }
*/
    return 0;
}
int CMainApp::Run()
{
    cout << "MainApp::Run!" << endl;
    return 0;
}

CScreenManager* CMainApp::GetScreenManager()
{
    return m_pScreenMgr;
}

