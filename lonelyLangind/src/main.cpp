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
#include "utility.h"
#include "Game.h"
#include "../eventsHandler/InputManager.h"
#include "../eventsHandler/KeyManager.h"



#define WIDTH	800
#define HEIGHT	600
#define FPS		60






using namespace std;
using namespace util;


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	if( action == GLFW_PRESS ){
		InputManager::keyPressed(key);
		if( key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(window,GL_TRUE);
	}
	else if ( action == GLFW_RELEASE ){
		InputManager::keyReleased(key);
	}
}

void mouseButton_callback(GLFWwindow* window, int button, int action, int mods){
	if( action == GLFW_PRESS ){
		InputManager::buttonClicked(button);
	}
	else if ( action == GLFW_RELEASE ){
		InputManager::buttonReleased(button);
	}
}

int main() {
	util::initGLFW();

	GLFWwindow* mainWindow;

	mainWindow = glfwCreateWindow(WIDTH,HEIGHT,"Lonely Landing", NULL, NULL);

	if(mainWindow == NULL){
		std::cerr << "Failed to create window" ;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(mainWindow);
	glfwSwapInterval(1);
	glfwSetKeyCallback(mainWindow,key_callback);
	glfwSetMouseButtonCallback(mainWindow,mouseButton_callback);
	// Initialisation de la bibliothèque GLEW ( OpenGL Extension Wrangler )

	GLenum err = glewInit();
	if ( err != GLEW_OK){
		return -1;
	}


	if(
	   !(GLEW_ARB_shading_language_420pack ||
		 GLEW_ARB_shader_objects ||
		 GLEW_ARB_vertex_shader ||
		 GLEW_ARB_fragment_shader)
	){
		std::cerr << "Cannot use extensions" ;
		return -1;
	}



	Game* game = new Game();




	// Game Loop
	while(!glfwWindowShouldClose(mainWindow)){

		game->update();
		game->render();

		glfwPollEvents();
		glfwSwapBuffers(mainWindow);
	}






	// Fermer la fenêtre principale
	glfwDestroyWindow(mainWindow);

	// Fermer la bibliothèque GLFW
	glfwTerminate();


	delete game;
	cout << "Côliss ca marche" << endl;

	return 0;
}
