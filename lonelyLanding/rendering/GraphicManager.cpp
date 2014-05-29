/*
 * GraphicManager.cpp
 *
 *  Created on: 2014-05-28
 *      Author: Adam
 */

#include "GraphicManager.h"







bool GraphicManager::init(){
	glfwSetErrorCallback(util::error_callback);
	if(!glfwInit()){

		return false;
	}
	return true;
}

void GraphicManager::shutdown(){
	glfwTerminate();
}
