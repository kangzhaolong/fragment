/*
 * cscreenmanager.h
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


#ifndef CSCREENMANAGER_H
#define CSCREENMANAGER_H

#include "cmainwindow.h"

class CMainWindow;

class CScreenManager
{
	private:
        static CScreenManager* m_instance;
        
        CMainWindow* m_pMainWin;
        
	public:
		
		virtual ~CScreenManager();
		
		 static CScreenManager* GetInstance();

		virtual int Init();
		virtual int Create();
		virtual int Run();
		virtual int Destroy();
		
	
	private:
		/* add your private declarations */
		CScreenManager();
		CScreenManager(const CScreenManager&);
};

#endif /* CSCREENMANAGER_H */ 
