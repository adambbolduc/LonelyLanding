/*
 * MouseManager.cpp
 *
 *  Created on: 2014-05-20
 *      Author: Adam
 */

#include "MouseManager.h"
#include <iostream>

MouseManager::MouseManager(){
	m_buttonActivated = std::set<int>();
}

bool MouseManager::init(){
	m_buttonActivated.clear();
	return true;
}

void MouseManager::buttonClicked(int button){
	m_buttonActivated.insert(button);
}

void MouseManager::buttonReleased(int button){
	m_buttonActivated.erase(button);
}

MouseManager& MouseManager::operator=(const MouseManager &mm2){
	if(!m_buttonActivated.empty()){
		m_buttonActivated.clear();
	}

	std::set<int>::const_iterator it = mm2.m_buttonActivated.begin();

	while(it != mm2.m_buttonActivated.end()){
		m_buttonActivated.insert(*it++);
	}
	return *this;
}

void MouseManager::printButtonActivated() const{
	std::set<int>::const_iterator it = m_buttonActivated.begin();

	while(it != m_buttonActivated.end()){
		std::cout << *it++ << std::endl;
	}
}
