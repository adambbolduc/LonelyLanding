//============================================================================
// Name        : lonelyLangind.cpp
// Author      : Adam B.-Bolduc
// Version     : 0.0
// Copyright   : 
// Description : Lonely Landing
//============================================================================

#include <GL/glew.h>
#include <GLFW/glfw3.h>



#include <iostream>
#include "../eventsHandler/InputManager.h"
#include "../eventsHandler/KeyManager.h"

#include "../eventsHandler/WindowManager.h"
#include "../rendering/RenderManager.h"
#include "../rendering/Shader.h"
#include "../rendering/Mesh.h"
#include "../rendering/GraphicManager.h"

#include <windows.h>




#define WIDTH	800
#define HEIGHT	600
#define FPS		60






using namespace std;
using namespace util;



int main() {

	// Principalement l'initialisation de glfw
	GraphicManager::init();
	// Principalement l'initialisation de glew
	RenderManager::init();

	InputManager::init();

	// Création de la fenêtre a l'aide de glfw
	WindowManager::createWindow(WIDTH,HEIGHT);
	WindowManager::setKeyCallback(InputManager::key_callback);
	WindowManager::setMouseButtonCallback(InputManager::mouseButton_callback);


	Mesh altair;

	altair.load("resources/meshes/suzanne.obj");

	// engine loop
	while(!WindowManager::windowShouldClose()){

		InputManager::pollEvents();
		WindowManager::swapBuffer();



		while(!InputManager::noEvent()){
			(InputManager::getNextEvent())->printEvent();

		}
		Sleep(1000/60);

	}

	WindowManager::destroyWindow();
	RenderManager::shutdown();
	cout << "Program ended correctly" << endl;

	return 0;
}
