//============================================================================
// Name        : lonelyLangind.cpp
// Author      : Adam B.-Bolduc
// Version     : 0.0
// Copyright   : 
// Description : Lonely Landing
//============================================================================

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS

#include <glm.hpp>
#include <gtx/transform.hpp>
#include <gtc/type_ptr.hpp>

#include <iostream>
#include <vector>
#include "../eventsHandler/InputManager.h"
#include "../eventsHandler/KeyManager.h"

#include "../eventsHandler/WindowManager.h"
#include "../rendering/RenderManager.h"
#include "../rendering/Shader.h"
#include "../rendering/Mesh.h"
#include "../rendering/GraphicManager.h"
#include "../rendering/Camera.h"


#include <windows.h>




#define WIDTH	800
#define HEIGHT	600
#define FPS		60






using namespace std;
using namespace util;
using namespace glm;


int main() {

	float x=0,y=0,z=3;
	float dx=0,dy=0,dz=0;
	float dP=0,dT=0;

	// Principalement l'initialisation de glfw
	if(!GraphicManager::init()){
		return -1;
	}


	if(!InputManager::init()){
		return -1;
	}

	// Création de la fenêtre a l'aide de glfw
	WindowManager::createWindow(WIDTH,HEIGHT);
	WindowManager::setKeyCallback(InputManager::key_callback);
	WindowManager::setMouseButtonCallback(InputManager::mouseButton_callback);

	// Initialisation de glew
	if(!RenderManager::init()){
		return -1;
	}
	Shader vertShader(GL_VERTEX_SHADER);
	Shader fragShader(GL_FRAGMENT_SHADER);

	vertShader.load("c:/users/Adam/Documents/GitHub/LonelyLanding/lonelyLanding/resources/shaders/vertexShader.vert");
	if(!vertShader.compile()){
		vertShader.printCompileInfo();
	}

	fragShader.load("c:/users/Adam/Documents/GitHub/LonelyLanding/lonelyLanding/resources/shaders/fragmentShader.sh");

	fragShader.compile();

	Program program;
	program.attachShader(vertShader);
	program.attachShader(fragShader);

	glBindAttribLocation(program.getID(),0,"vertexCoord");
	glBindAttribLocation(program.getID(),1,"normalCoord");


	program.link();


	program.getUniformLocation();

	Camera camera;
	camera.setProjectionMatrix(1.22,800.0/600.0,0.1,100.0);


	// This will identify our vertex buffer
	Mesh perso;
	perso.load("resources/meshes/dante_naked.obj");
	RenderManager::createVBO(perso);
	RenderManager::createVAO(perso);

	camera.setPos(glm::vec3(-3,0,0));
	camera.setOrientation(0,0);
	camera.setViewMatrix();



	InputEvent* event;
	// engine loop
	while(!WindowManager::windowShouldClose()){

		// setting the camera
		camera.move(glm::vec3(-dx,-dy,-dz));
		camera.rotate(dT,dP);
		camera.setViewMatrix();


		//camera.printCoord();
		glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);

		RenderManager::render(perso,program,camera);
		InputManager::pollEvents();
		WindowManager::swapBuffer();





		while(!InputManager::noEvent()){
			// if its a key_event
			if( (event = InputManager::getNextEvent())->getType() == GE_KEY_EVENT ){
				// if key is pressed
				int key =((InputKeyEvent *) event)->getKey();
				if( ((InputKeyEvent *) event)->getAction() == GE_KEY_PRESS ){
					switch(key){
					case 'A' :
						dy -= 0.1;
						break;
					case 'W' :
						dx -= 0.1;
						break;
					case 'D' :
						dy += 0.1;
						break;
					case 'S' :
						dx += 0.1;
						break;
					case GLFW_KEY_LEFT :
						dP += 0.1;
						break;
					case GLFW_KEY_RIGHT :
						dP -= 0.1;
						break;
					case GLFW_KEY_UP :
						dT += 0.1;
						break;
					case GLFW_KEY_DOWN :
						dT -= 0.1;
						break;
					default :
						break;
					}
				}
				else if( ((InputKeyEvent *) event)->getAction() == GE_KEY_RELEASE ){
					switch(key){
					case 'A' :
						dy += 0.1;
						break;
					case 'W' :
						dx += 0.1;
						break;
					case 'D' :
						dy -= 0.1;
						break;
					case 'S' :
						dx -= 0.1;
						break;
					case GLFW_KEY_LEFT :
						dP -= 0.1;
						break;
					case GLFW_KEY_RIGHT :
						dP += 0.1;
						break;
					case GLFW_KEY_UP :
						dT -= 0.1;
						break;
					case GLFW_KEY_DOWN :
						dT += 0.1;
						break;
					default :
						break;
					}
				}
			}
		}

		Sleep(1000/60);

	}



	WindowManager::destroyWindow();
	RenderManager::shutdown();
	cout << "Program ended correctly" << endl;

	return 0;
}
