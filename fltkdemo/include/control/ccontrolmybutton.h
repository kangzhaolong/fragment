/*
 * ccontrolmybutton.h
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


#ifndef CCONTROLMYBUTTON_H
#define CCONTROLMYBUTTON_H


#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/names.h>


class CControlMyButton: public Fl_Widget
{
	public:
		CControlMyButton(int x, int y, int w, int h, const char *label);
		virtual ~CControlMyButton();
		virtual void draw();
		//virtual void redraw();
		virtual int handle (int event);
		static void static_slider_cb(Fl_Widget* v, void *);
		void slider_cb() ;
		
		
		
	private:
		/* add your private declarations */
		bool m_bActive;
		Fl_Button* btn;
		
};

#endif /* CCONTROLMYBUTTON_H */ 
