/*
 * EventManager.cpp
 *
 *  Created on: 2014-05-17
 *      Author: Adam
 */

#include "InputManager.h"
#include "InputEvent.h"
#include <iostream>
#include <queue>


KeyManager InputManager::keyManager = KeyManager();
MouseManager InputManager::mouseManager = MouseManager();
std::queue<InputEvent*> InputManager::inputEventQueue = std::queue<InputEvent*>();



bool InputManager::init(){

	while(	!InputManager::inputEventQueue.empty() ){
		delete InputManager::inputEventQueue.front();
		InputManager::inputEventQueue.pop();
	}
	InputManager::keyManager.init();
	InputManager::mouseManager.init();
	return true;
}



void InputManager::keyPressed(int key){
	keyManager.keyPressed(key);
	InputManager::inputEventQueue.push(new InputKeyEvent(key,GE_KEY_PRESS));
}

void InputManager::keyReleased(int key){
	keyManager.keyReleased(key);
	InputManager::inputEventQueue.push(new InputKeyEvent(key,GE_KEY_RELEASE));
}

void InputManager::printKeyActivated(){
	keyManager.printKeyActivated();
}

void InputManager::buttonClicked(int button){
	mouseManager.buttonClicked(button);
//	InputManager::inputEventQueue.push(new InputMouseEvent(button,GE_MOUSE_PRESS,x,y));
}

void InputManager::buttonReleased(int button){
	mouseManager.buttonReleased(button);
}

void InputManager::printButtonActivated(){
	mouseManager.printButtonActivated();
}

void InputManager::pollEvents(){
	glfwPollEvents();

}
bool InputManager::noEvent(){
	return InputManager::inputEventQueue.empty();
}


InputEvent* InputManager::getNextEvent(){
	if(InputManager::noEvent()){
		return NULL;
	}
	InputEvent* temp = InputManager::inputEventQueue.front();
	InputManager::inputEventQueue.pop();
	return temp;
}


void InputManager::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	if( action == GLFW_PRESS ){
		InputManager::keyPressed(key);
		if( key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(window,GL_TRUE);
	}
	else if ( action == GLFW_RELEASE ){
		InputManager::keyReleased(key);
	}
}

void InputManager::mouseButton_callback(GLFWwindow* window, int button, int action, int mods){
	if( action == GLFW_PRESS){
		InputManager::buttonClicked(button);
	}
	else if( action == GLFW_RELEASE ){
		InputManager::buttonReleased(button);
	}
}






