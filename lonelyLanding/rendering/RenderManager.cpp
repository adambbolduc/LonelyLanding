/*
 * RenderManager.cpp
 *
 *  Created on: 2014-05-26
 *      Author: Adam
 */

#include "RenderManager.h"


#include <iostream>



bool RenderManager::init(){

	// glew initialization
	GLenum err = glewInit();
	if ( err != GLEW_OK){
		std::cerr << glewGetErrorString(err) << std::endl;
		return false;
	}


	// List of extensions
	if(
			!(GLEW_ARB_shading_language_420pack ||
			  GLEW_ARB_shader_objects 			||
			  GLEW_ARB_vertex_shader 			||
			  GLEW_ARB_fragment_shader			)
	){
		std::cerr << "Cannot use extensions" ;
		return false;
	}

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClearColor(0.4,0.4,0.4,1);

	return true;
}

void RenderManager::shutdown() {}

void RenderManager::render(const Mesh& model, Program program, const Camera& camera){

	glm::mat4 MVP = camera.getMatrix(); // Remember, matrix multiplication is the other way around

	glUseProgram(program.getID());

	glUniformMatrix4fv(0, 1, GL_FALSE, &MVP[0][0]);


	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, model.getVertexBufferID());
	glVertexAttribPointer(
	   0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
	   3,                  // size
	   GL_FLOAT,           // type
	   GL_FALSE,           // normalized?
	   0,                  // stride
	   (void*)0            // array buffer offset
	);
	for(unsigned int i = 0 ; i < model.getNbFace() ; i++){
		glDrawArrays(GL_LINE_LOOP, 3*i, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
	}

	glDisableVertexAttribArray(0);
	glUseProgram(0);
}
