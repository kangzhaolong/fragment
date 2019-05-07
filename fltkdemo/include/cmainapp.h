/*
 * cmainapp.h
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


#ifndef CMAINAPP_H
#define CMAINAPP_H

//class MainWindow;
class CScreenManager;
class CLayerManager;

class CMainApp
{
	private:
        static CMainApp* m_instance;
	protected:
      //  MainWindow* m_pWin;
        CScreenManager* m_pScreenMgr;
        CLayerManager* m_pLayerMgr;
	private:
		/* add your private declarations */
	private:
        CMainApp(const CMainApp&);
       // CMainApp& operator=(const MainApp&);//禁止赋值
        CMainApp();
public:
    virtual ~CMainApp();
    static CMainApp* GetInstance();

    virtual int Init();
    virtual int Create();
    virtual int Destroy();
    virtual int Run();
    CScreenManager* GetScreenManager();
	

};

#endif /* CMAINAPP_H */ 
