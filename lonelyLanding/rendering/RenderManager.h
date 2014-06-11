/*
 * RenderManager.h
 *
 *  Created on: 2014-05-26
 *      Author: Adam
 */

#ifndef RENDERMANAGER_H_
#define RENDERMANAGER_H_

#include <GL/glew.h>

#include "Mesh.h"
#include "Program.h"
#include "Camera.h"
#include <glm.hpp>

class RenderManager {

public:
	static bool init();
	static void shutdown();
	static void render(const Mesh& model, Program program, const Camera& camera);
	static void createVBO(Mesh& model);
	static void createVAO(Mesh& model);

};

#endif /* RENDERMANAGER_H_ */
