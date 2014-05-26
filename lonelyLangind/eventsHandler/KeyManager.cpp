/*
 * KeyManager.cpp
 *
 *  Created on: 2014-05-16
 *      Author: Adam
 */

#include "KeyManager.h"
#include <iostream>



KeyManager::KeyManager(){
	m_keyActivated = std::set<int>();
}

void KeyManager::keyPressed(int key){
	m_keyActivated.insert(key);

}

void KeyManager::keyReleased(int key){
	m_keyActivated.erase(key);
}

KeyManager& KeyManager::operator=(const KeyManager &km2){
	if(!m_keyActivated.empty()){
		m_keyActivated.clear();
	}

	std::set<int>::const_iterator it = km2.m_keyActivated.begin();

	while(it != km2.m_keyActivated.end()){
		m_keyActivated.insert(*it++);
	}
	return *this;
}

void KeyManager::printKeyActivated() const{
	std::set<int>::const_iterator it = m_keyActivated.begin();

	while(it != m_keyActivated.end()){
		std::cout << *it++ << std::endl;
	}
}


