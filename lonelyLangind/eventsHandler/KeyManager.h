/*
 * KeyManager.h
 *
 *  Created on: 2014-05-16
 *      Author: Adam
 */



#ifndef KEYMANAGER_H_
#define KEYMANAGER_H_

#include <set>


class EventManager;

class KeyManager{
	friend class InputManager;

private:
	KeyManager();
	void keyPressed(int key);
	void keyReleased(int key);
	KeyManager& operator=(const KeyManager &km2);
	void printKeyActivated() const;


	std::set<int> m_keyActivated;
};



#endif
