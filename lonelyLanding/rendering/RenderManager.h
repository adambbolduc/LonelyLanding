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

class RenderManager {

public:
	static bool init();
	static void shutdown();
	static void render(Mesh model, Program program);

private:
};

#endif /* RENDERMANAGER_H_ */
