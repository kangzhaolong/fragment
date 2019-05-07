/*
 * clayermanager.cpp
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


#include "clayermanager.h"

#include <iostream>
using namespace std;

CLayerManager* CLayerManager::m_instance = new CLayerManager();

CLayerManager* CLayerManager::GetInstance()
{
    return m_instance;
}
CLayerManager::CLayerManager()
{
	cout<<"CLayerManager"<<endl;
}


CLayerManager::~CLayerManager()
{
	cout<<"~CLayerManager"<<endl;
}
int CLayerManager::Init()
{
	cout<<"CLayerManager Init"<<endl;
	
	
	return 0;
}
int CLayerManager::Create()
{
	cout<<"CLayerManager Create"<<endl;
	
	
	
	
	
	return 0;
}
int CLayerManager::Destroy()
{
	cout<<"CLayerManager Destroy"<<endl;
	
	return 0;
}
