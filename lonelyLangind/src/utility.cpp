/*
 * utility.cpp
 *
 *  Created on: 2014-05-13
 *  \author: Adam B.-Bolduc
 */

#include "utility.h"
#include <GLFW/glfw3.h>
#include <iostream>

void util::error_callback(int error,const char* description){
	std::cerr << description ;
}


bool util::initGLFW(){

	glfwSetErrorCallback(util::error_callback);
	if(!glfwInit()){
		return false;
	}



	return true;
}




