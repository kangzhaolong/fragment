/*
 * cdbus.cpp
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


#include "cdbus.h"


CDBus::CDBus():
m_connection_client(NULL),
m_connection_server(NULL)
{
	
}


DBusConnection* CDBus::init_bus_client()
{
	dbus_error_init(&m_err_client);
	m_connection_client = dbus_bus_get(DBUS_BUS_SESSION,&m_err_client);
	if(dbus_error_is_set(&m_err_client))
	{
		printf("connection error(client): %s -- %s\n",m_err_client.name,m_err_client.message);
		dbus_error_free(&m_err_client);
		return NULL;
	}
	ret_client = dbus_bus_request_name(m_connection_client,"com.example.test", DBUS_NAME_FLAG_REPLACE_EXISTING, &m_err_client);
	if(dbus_error_is_set(&m_err_client))
	{
		printf("connection error(client): %s -- %s\n",m_err_client.name,m_err_client.message);
		dbus_error_free(&m_err_client);
		return NULL;
	}
	if(ret_client != DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER)
	{
		return NULL;
	}
	return m_connection_client;
}
void CDBus::send_signal()
{
	DBusMessage *msg = NULL;
	DBusMessageIter arg;
	char *str = "Hello world!";
	
	if((msg = dbus_message_new signal("/hello","aa,bb,cc","alarm_test")) == NULL)
	{
		printf("message is NULL\n");
		return ;
	}
	#if 0
		if(!dbus_message_set_destination(msg,"Hello,world.Service"))
		{
			printf("memory error \n");
		}
	#endif
	dbus_message_iter_init_append(msg,&arg);
	dbus_message_iter_append_basic(&arg,DBUS_TYPE_STRING,&str);
	dbus_connection_send(m_connection_client,msg,NULL);
	dbus_connection_flush(m_connection_client);
	dbus_message_unref(msg);
	return;
}
void CDBus::send_method_call()
{
	
	DBusMessage *msg; 
	DBusMessageIter arg; 
	DBusPendingCall *pending; 
	int a = 100; 
	int b = 99; 
	int sum; 
	msg = dbus_message_new_method_call("hello.world.service", "/hello/world","hello.world", "add"); 
	if(msg == NULL) 
	{ 
		printf("no memory\n"); 
		return; 
	} 
	dbus_message_iter_init_append(msg, &arg); 
	if(!dbus_message_iter_append_basic (&arg, DBUS_TYPE_INT32,&a))
	{ 
		printf("no memory!"); 
		dbus_message_unref(msg); 
		return; 
	}
	 if(!dbus_message_iter_append_basic (&arg, DBUS_TYPE_INT32,&b))
	 { 
		 printf("no memory!"); 
		 dbus_message_unref(msg); 
		 return; 
	} 
	//入队message,等待回复 //param1: 连接描述符 //param2:　message //param3: 相当于一个回调的一个描述符，为了获了返回的消息 //param4:　超时间．　-１代表无限 
	if(!dbus_connection_send_with_reply (m_connection_client, msg, &pending, -1))
	{ 
		printf("no memeory!");
		dbus_message_unref(msg); 
		return; 
	} 
	if(pending == NULL)
	{ 
		printf("Pending is NULL, may be disconnect...\n"); 
		dbus_message_unref(msg); 
		return; 
	} 
		//send 
	dbus_connection_flush(m_connection_client); 
	dbus_message_unref(msg); 
	//阻塞，直到接收到一个响应． 
	dbus_pending_call_block (pending); 
	msg = dbus_pending_call_steal_reply (pending); 
	if (msg == NULL) 
	{ 
		printf("reply is null. error\n"); 
		return; 
	} 
	//释放pending内存 
	dbus_pending_call_unref(pending); 
	//解析参数 
	if (!dbus_message_iter_init(msg, &arg)) 
		printf("no argument, error\n"); 
	if(dbus_message_iter_get_arg_type(&arg) != DBUS_TYPE_INT32) 
	{ 
		printf("paramter type error\n");
	}
	dbus_message_iter_get_basic(&arg, &sum);
	printf(" a(%d) + b(%d) = %d\n",a, b, sum); 
	dbus_message_unref(msg); 
	return;

}
DBusConnection* CDBus::init_bus_server()
{
	
	dbus_error_init(&m_err_server); 
	//与session dbus 建立连接 
	//param１：bus type = {DBUS_BUS_SESSION, DBUS_BUS_SYSTEM} 一个系统dbus, 一个普通用户dbus 
	//param２：错误信息，包括错误名与错误信息． 
	connection = dbus_bus_get(DBUS_BUS_SESSION, &err); 
	if(dbus_error_is_set(&err)) 
	{ 
		printf("Connection Error: %s--%s\n", err.name, err.message); 
		dbus_error_free(&err); 
		return NULL; 
	} 
	//为连接设置一个bus name: bus_name; 
	//param 1: 连接描述符 
	//param 2: 请求bus要分配的bus name(逻辑上讲，bus name可以是任何字符串，只要符合命名规则) 
	//param 3:　flags ={DBUS_NAME_FLAG_REPLACE_EXISTING, 
	//					DBUS_NAME_FLAG_ALLOW_REPLACEMENT, 
	//					DBUS_NAME_FLAG_DO_NOT_QUEUE 
	//					 } 
	//param 4: err info 
	ret = dbus_bus_request_name(connection, "hello.world.service", DBUS_NAME_FLAG_REPLACE_EXISTING, &err); 
	if(dbus_error_is_set(&err)) 
	{ 
		printf("Name Error: %s--%s\n", err.name, err.message); 
		dbus_error_free(&err); 
		return NULL; 
	} 
	if(ret != DBUS_REQUEST_NAME_REPLY_PRIMARY_OWNER) 
	return NULL; 
	//注册感兴趣的signal: 来自接口dbus.test.signal.sender 
	//param1: 连接描述符 
	//param2: match rule　（常用的类型：　sender= 
	//									interface= 
	//									type= 
	//									member= ） 
	//param3: err info 
	//只设置一个type = signal,表示所有信号都接受．也可以加上接口，发送者bus_name dbus_bus_add_match(connection, "type='signal'", &err); 
	//阻塞，直到消息发送成功． 
	dbus_connection_flush(connection); 
	if(dbus_error_is_set(&err)) 
	{ 
		printf("add Match Error %s--%s\n", err.name, err.message); 
		dbus_error_free(&err); 
		return connection; 
	} 
	return connection;

}
void CDBus::handle_message(DBusConnection *connection)
{
	DBusMessage *msg; 
	DBusMessageIter arg; 
	char *str; 
	while(1) 
	{ 
		//param1: 连接描述符 
		//param2: 超时时间，　-1无限超时时间 dbus_connection_read_write(connection, 0); 
		//从队列中取出一条消息 
		msg = dbus_connection_pop_message(connection); 
		if(msg == NULL) 
		{ 
			sleep(1); 
			continue; 
		} 
		//这里应该过滤path，暂且不做 
		//打印出消息对象路径
		printf("path: %s\n", dbus_message_get_path (msg)); 
		//param1: message 
		//param2: interface 这个名字必须与发送那个接口一样．才能处理 
		//param3: singal name 方法名也必须一样． 
		if(dbus_message_is_signal(msg, "aa.bb.cc", "alarm_test")) 
		{ 
			//解析message 参数，０为无参数． 
			if(!dbus_message_iter_init(msg, &arg)) 
			{ 
				printf("no argument\n"); 
			} 
			//获取第一个参数类型 
			if(dbus_message_iter_get_arg_type(&arg) != DBUS_TYPE_INVALID) 
			{ 
				//获取参数的值 
				dbus_message_iter_get_basic(&arg,&str); 
				printf("recv param --: %s\n", str); 
			} 
		} 
		else if(dbus_message_is_method_call(msg, "hello.world", "add")) 
		{
			/////处理 add　远程调用． 
			DBusMessage *rp; 
			DBusMessageIter r_arg; 
			int a = 0; 
			int b = 0; 
			int sum = 0; 
			printf("service: add  function\n"); 
			if(!dbus_message_iter_init(msg, &arg)) 
			{ 
				printf("no argument!\n"); 
				goto out; 
			} 
			if(dbus_message_iter_get_arg_type(&arg) != DBUS_TYPE_INT32)
			{ 
				printf("argument error\n"); 
				goto out; 
			} 
			dbus_message_iter_get_basic(&arg, &a); 
			if(!dbus_message_iter_next(&arg)) 
			{ 
				printf("too few argument!\n"); 
				goto out; 
			}
			//check argument type.... 
			dbus_message_iter_get_basic(&arg, &b); 
			sum = a + b; out: 
			//new 一个回应对象
			rp = dbus_message_new_method_return(msg); 
			dbus_message_iter_init_append(rp, &r_arg); 
			if(!dbus_message_iter_append_basic(&r_arg, DBUS_TYPE_INT32, &sum))
			{ 
				printf("no memory!!\n"); 
				return;
				
			} 
			//param3: 这个跟消息序列有关 
			if(!dbus_connection_send(connection, rp, NULL)) 
			{ 
				printf("no memory!!\n"); 
				return; 
			} 
			dbus_connection_flush(connection); 
			dbus_message_unref(rp);
		} 
		//释放空间 dbus_message_unref(msg); } 
		//dbus_bus_remove_match();

}
