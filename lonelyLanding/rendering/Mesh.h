/*
 * Mesh.h
 *
 *  Created on: 2014-05-26
 *      Author: Adam
 */

#ifndef MESH_H_
#define MESH_H_

#include <gl/glew.h>

#include <vector>
#include <glm.hpp>
#include <GLFW/glfw3.h>

class Mesh {

public:
	Mesh();
	~Mesh();
	void load(const char* path);
	void setVertexBufferID(unsigned int dataType, GLuint id);
	void setBufferArrayID(GLuint id);
	const float* getVertPtr() const;
	const float* getNormPtr() const;
	unsigned int getNbFace() const;
	const GLuint* getBuffersID() const;
	GLuint getVAO() const;
	void printNormals() const;

private:
	std::vector<float> m_vertices;
	std::vector<float> m_textures;
	std::vector<float> m_normals;
	GLuint buffersID[3],
		   vertexArray;

	unsigned int 	m_nbFace,
					m_nbVertices,
					m_nbTextures,
					m_nbNormals;


	//GLuint colorBuffer;

};

#endif /* MESH_H_ */
