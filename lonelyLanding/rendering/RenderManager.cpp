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

void RenderManager::render(Mesh model, Program program){

}
