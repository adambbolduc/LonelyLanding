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

	program.bindAttribLocation(0,"gl_Vertex");
	program.bindAttribLocation(1,"gl_Color");
	program.bindAttribLocation(2,"gl_ModelViewMatrix");
	program.bindAttribLocation(6,"gl_ProjectionMatrix");

	program.link();


	Camera camera;
	camera.setProjectionMatrix(1.22,800.0/600.0,0.1,100.0);

	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// An array of 3 vectors which represents 3 vertices
	// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
	// A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
	static const GLfloat g_vertex_buffer_data[] = {
	    -1.0f,-1.0f,-1.0f, // triangle 1 : begin
	    -1.0f,-1.0f, 1.0f,
	    -1.0f, 1.0f, 1.0f, // triangle 1 : end
	    1.0f, 1.0f,-1.0f, // triangle 2 : begin
	    -1.0f,-1.0f,-1.0f,
	    -1.0f, 1.0f,-1.0f, // triangle 2 : end
	    1.0f,-1.0f, 1.0f,
	    -1.0f,-1.0f,-1.0f,
	    1.0f,-1.0f,-1.0f,
	    1.0f, 1.0f,-1.0f,
	    1.0f,-1.0f,-1.0f,
	    -1.0f,-1.0f,-1.0f,
	    -1.0f,-1.0f,-1.0f,
	    -1.0f, 1.0f, 1.0f,
	    -1.0f, 1.0f,-1.0f,
	    1.0f,-1.0f, 1.0f,
	    -1.0f,-1.0f, 1.0f,
	    -1.0f,-1.0f,-1.0f,
	    -1.0f, 1.0f, 1.0f,
	    -1.0f,-1.0f, 1.0f,
	    1.0f,-1.0f, 1.0f,
	    1.0f, 1.0f, 1.0f,
	    1.0f,-1.0f,-1.0f,
	    1.0f, 1.0f,-1.0f,
	    1.0f,-1.0f,-1.0f,
	    1.0f, 1.0f, 1.0f,
	    1.0f,-1.0f, 1.0f,
	    1.0f, 1.0f, 1.0f,
	    1.0f, 1.0f,-1.0f,
	    -1.0f, 1.0f,-1.0f,
	    1.0f, 1.0f, 1.0f,
	    -1.0f, 1.0f,-1.0f,
	    -1.0f, 1.0f, 1.0f,
	    1.0f, 1.0f, 1.0f,
	    -1.0f, 1.0f, 1.0f,
	    1.0f,-1.0f, 1.0f
	};
	// This will identify our vertex buffer
	GLuint vertexbuffer;

	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);

	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);



	Mesh test;
	test.load("resources/meshes/model.obj");




	// One color for each vertex. They were generated randomly.
	static const GLfloat g_color_buffer_data[] = {
	    0.583f,  0.771f,  0.014f,
	    0.609f,  0.115f,  0.436f,
	    0.327f,  0.483f,  0.844f,
	    0.822f,  0.569f,  0.201f,
	    0.435f,  0.602f,  0.223f,
	    0.310f,  0.747f,  0.185f,
	    0.597f,  0.770f,  0.761f,
	    0.559f,  0.436f,  0.730f,
	    0.359f,  0.583f,  0.152f,
	    0.483f,  0.596f,  0.789f,
	    0.559f,  0.861f,  0.639f,
	    0.195f,  0.548f,  0.859f,
	    0.014f,  0.184f,  0.576f,
	    0.771f,  0.328f,  0.970f,
	    0.406f,  0.615f,  0.116f,
	    0.676f,  0.977f,  0.133f,
	    0.971f,  0.572f,  0.833f,
	    0.140f,  0.616f,  0.489f,
	    0.997f,  0.513f,  0.064f,
	    0.945f,  0.719f,  0.592f,
	    0.543f,  0.021f,  0.978f,
	    0.279f,  0.317f,  0.505f,
	    0.167f,  0.620f,  0.077f,
	    0.347f,  0.857f,  0.137f,
	    0.055f,  0.953f,  0.042f,
	    0.714f,  0.505f,  0.345f,
	    0.783f,  0.290f,  0.734f,
	    0.722f,  0.645f,  0.174f,
	    0.302f,  0.455f,  0.848f,
	    0.225f,  0.587f,  0.040f,
	    0.517f,  0.713f,  0.338f,
	    0.053f,  0.959f,  0.120f,
	    0.393f,  0.621f,  0.362f,
	    0.673f,  0.211f,  0.457f,
	    0.820f,  0.883f,  0.371f,
	    0.982f,  0.099f,  0.879f
	};

	GLuint colorbuffer;
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);





	camera.setPos(glm::vec3(-3,0,0));
	camera.setOrientation(0,0);
	camera.setViewMatrix();
	// Model matrix : an identity matrix (model will be at the origin)
	// Our ModelViewProjection : multiplication of our 3 matrices
	glm::mat4 MVP;


	// Get a handle for our "MVP" uniform.
	// Only at initialisation time.
	GLuint MatrixID = glGetUniformLocation(program.getID(), "MVP");

	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	// For each model you render, since the MVP will be different (at least the M part)


	InputEvent* event;
	// engine loop
	while(!WindowManager::windowShouldClose()){

		// setting the camera
		MVP = camera.getMatrix(); // Remember, matrix multiplication is the other way around
		camera.move(glm::vec3(-dx,-dy,-dz));
		camera.rotate(dT,dP);
		camera.setViewMatrix();


		glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT);


		//drawing the cube
		glUseProgram(program.getID());

		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
		   0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		   3,                  // size
		   GL_FLOAT,           // type
		   GL_FALSE,           // normalized?
		   0,                  // stride
		   (void*)0            // array buffer offset
		);

		//2nd attribute buffer : colors
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
		glVertexAttribPointer(
		   1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
		    3,                                // size
		    GL_FLOAT,                         // type
		    GL_FALSE,                         // normalized?
		    0,                                // stride
		    (void*)0                          // array buffer offset
		);



		// Draw the triangle !


		for(int i = 0 ; i < 12 ; i++){
			glDrawArrays(GL_LINE_LOOP, 3*i, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
		}

		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(0);
		glUseProgram(0);





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
		x+=dx;
		y+=dy;
		z+=dz;


		Sleep(1000/60);

	}

	WindowManager::destroyWindow();
	RenderManager::shutdown();
	cout << "Program ended correctly" << endl;

	return 0;
}
