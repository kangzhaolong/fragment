/*
 * cdbus.h
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


#ifndef CDBUS_H
#define CDBUS_H
#include <dbus/dbus.h>
#include <stdio.h>
#include <stdlib.h>


class CDBus
{
	public:
		CDBus();
		//Client
		DBusConnection* init_bus_client();
		void send_signal();
		void send_method_call(DBusConnection *connection);
		
		//Server
		DBusConnection* init_bus_server();
		void handle_message(DBusConnection *connection);
			
	private:
		/* add your private declarations */
		
		DBusConnection* m_connection_client;
		DBusError m_err_client;
		int ret_client;
		
		DBusConnection *m_connection_server;
		DBusError m_err_server;
		int ret_server = 0;
};

#endif /* CDBUS_H */ 
