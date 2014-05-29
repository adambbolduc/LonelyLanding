/*
 * GameEvent.cpp
 *
 *  Created on: 2014-05-21
 *      Author: Adam
 */

#include "InputEvent.h"
#include <iostream>

//constructor
InputEvent::InputEvent(int type) : m_type(type) {}
//destryuctor
InputEvent::~InputEvent() {}

//Key constructor
InputKeyEvent::InputKeyEvent(int key, int action) : InputEvent(GE_KEY_EVENT), m_key(key), m_action(action) {}

//Mouse Event constructor
InputMouseEvent::InputMouseEvent(int button, int action, double x, double y) :
		InputEvent(GE_MOUSE_EVENT),
		m_button(button),
		m_action(action),
		m_x(x),
		m_y(y){

}

void InputKeyEvent::printEvent(){
	std::cout << m_type << "\t" << m_key << std::endl;
}

void InputMouseEvent::printEvent(){
	std::cout << m_type << "\t" << m_button << "\t" << m_x <<"\t" << m_y << std::endl;
}
