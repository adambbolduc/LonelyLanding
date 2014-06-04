/*
 * Mesh.h
 *
 *  Created on: 2014-05-26
 *      Author: Adam
 */

#ifndef MESH_H_
#define MESH_H_

#include <vector>
#include <glm.hpp>
#include <GLFW/glfw3.h>

class Mesh {

public:
	Mesh();
	~Mesh();
	void load(const char* path);

private:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> textures;
	std::vector<glm::vec3> normals;
	std::vector<GLushort> elements;
	GLuint vertexBuffer;
	//GLuint colorBuffer;

};

#endif /* MESH_H_ */
