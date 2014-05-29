/*
 * WindowManager.cpp
 *
 *  Created on: 2014-05-27
 *      Author: Adam
 */

#include "WindowManager.h"
#include <iostream>

GLFWwindow* WindowManager::window;// a retirer probablement.

bool WindowManager::createWindow(int width, int height){

	WindowManager::window = glfwCreateWindow(width,height,"gameENGINE", NULL, NULL);

	if(WindowManager::window == NULL){
		std::cerr << "Failed to create window" ;
		return false;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	return true;
}

void WindowManager::setKeyCallback(void(* GLFWkeyfun)(GLFWwindow *, int, int, int, int)){
	glfwSetKeyCallback(window,GLFWkeyfun);
}

void WindowManager::setMouseButtonCallback(void(* GLFWmousebuttonfun)(GLFWwindow *, int, int, int)){
	glfwSetMouseButtonCallback(window,GLFWmousebuttonfun);
}


void WindowManager::destroyWindow(){
	if(WindowManager::window != NULL){
		glfwDestroyWindow(WindowManager::window);
	}
}

bool WindowManager::windowShouldClose(){
	return glfwWindowShouldClose(window);
}

void WindowManager::swapBuffer(){
	glfwSwapBuffers(window);
}
