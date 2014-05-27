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

class Mesh {

public:
	Mesh();
	~Mesh();
	void load(const char* path);

private:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec3> textures;

};

#endif /* MESH_H_ */
