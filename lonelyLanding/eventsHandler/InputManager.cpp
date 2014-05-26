/*
 * EventManager.cpp
 *
 *  Created on: 2014-05-17
 *      Author: Adam
 */

#include "InputManager.h"
#include <iostream>


KeyManager InputManager::keyManager = KeyManager();
MouseManager InputManager::mouseManager = MouseManager();

void InputManager::keyPressed(int key){
	keyManager.keyPressed(key);
}

void InputManager::keyReleased(int key){
	keyManager.keyReleased(key);
}

void InputManager::printKeyActivated(){
	keyManager.printKeyActivated();
}

void InputManager::buttonClicked(int button){
	mouseManager.buttonClicked(button);
}

void InputManager::buttonReleased(int button){
	mouseManager.buttonReleased(button);
}

void InputManager::printButtonActivated(){
	mouseManager.printButtonActivated();
}
