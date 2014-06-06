/*
 * Mesh.cpp
 *
 *  Created on: 2014-05-26
 *      Author: Adam
 */

#include "Mesh.h"
#include "../src/utility.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

Mesh::Mesh() : 	m_vertices(),
				m_textures(),
				m_normals(),
				vertexBuffer(0),
				m_nbFace(0),
				m_nbVertices(0),
				m_nbTextures(0),
				m_nbNormals(0){}

Mesh::~Mesh(){
	glDeleteBuffers(1, &vertexBuffer);
}

void Mesh::load(const char* path){
	std::vector<glm::vec3> vert_temp;
	std::vector<glm::vec3> text_temp;
	std::vector<glm::vec3> norm_temp;
	std::ifstream inputFile;
	std::string line;
	inputFile.open(path);
	std::vector<std::string> token;
	while(getline(inputFile,line)){
		line = util::doubleSlash(line);
		line = util::slash_to_space(line);
		token = util::splitStringIntoToken(line);

		if( token[0] == "#" ){continue;} 	// This line is a comment do nothing
		else if( token[0] == "v" ){			// This line is a vertex coordinate
			vert_temp.push_back(glm::vec3(
					atof(token[1].c_str()),
					atof(token[2].c_str()),
					atof(token[3].c_str()))
			);


		}
		else if( token[0] == "vt" ){		// This line is a texture coordinate
			text_temp.push_back(glm::vec3(
					atof(token[1].c_str()),
					atof(token[2].c_str()),
					atof(token[3].c_str()))
			);
		}
		else if( token[0] == "vn" ){		// This line is a normal coordinate
			norm_temp.push_back(glm::vec3(
					atof(token[1].c_str()),
					atof(token[2].c_str()),
					atof(token[3].c_str()))
			);
		}
		else if( token[0] == "g" ){			// This line is a group

		}
		else if( token[0] == "f" ){			// This line is a face
			m_vertices.push_back(vert_temp[atoi(token[1].c_str()) - 1].x);
			m_vertices.push_back(vert_temp[atoi(token[1].c_str()) - 1].y);
			m_vertices.push_back(vert_temp[atoi(token[1].c_str()) - 1].z);

			m_textures.push_back(vert_temp[atoi(token[2].c_str()) - 1].x);
			m_textures.push_back(vert_temp[atoi(token[2].c_str()) - 1].y);
			m_textures.push_back(vert_temp[atoi(token[2].c_str()) - 1].z);

			m_normals.push_back(vert_temp[atoi(token[3].c_str()) - 1].x);
			m_normals.push_back(vert_temp[atoi(token[3].c_str()) - 1].y);
			m_normals.push_back(vert_temp[atoi(token[3].c_str()) - 1].z);

			m_vertices.push_back(vert_temp[atoi(token[4].c_str()) - 1].x);
			m_vertices.push_back(vert_temp[atoi(token[4].c_str()) - 1].y);
			m_vertices.push_back(vert_temp[atoi(token[4].c_str()) - 1].z);

			m_textures.push_back(vert_temp[atoi(token[5].c_str()) - 1].x);
			m_textures.push_back(vert_temp[atoi(token[5].c_str()) - 1].y);
			m_textures.push_back(vert_temp[atoi(token[5].c_str()) - 1].z);

			m_normals.push_back(vert_temp[atoi(token[6].c_str()) - 1].x);
			m_normals.push_back(vert_temp[atoi(token[6].c_str()) - 1].y);
			m_normals.push_back(vert_temp[atoi(token[6].c_str()) - 1].z);

			m_vertices.push_back(vert_temp[atoi(token[7].c_str()) - 1].x);
			m_vertices.push_back(vert_temp[atoi(token[7].c_str()) - 1].y);
			m_vertices.push_back(vert_temp[atoi(token[7].c_str()) - 1].z);

			m_textures.push_back(vert_temp[atoi(token[8].c_str()) - 1].x);
			m_textures.push_back(vert_temp[atoi(token[8].c_str()) - 1].y);
			m_textures.push_back(vert_temp[atoi(token[8].c_str()) - 1].z);

			m_normals.push_back(vert_temp[atoi(token[9].c_str()) - 1].x);
			m_normals.push_back(vert_temp[atoi(token[9].c_str()) - 1].y);
			m_normals.push_back(vert_temp[atoi(token[9].c_str()) - 1].z);

		}
	}
	inputFile.close();

	m_nbFace = m_vertices.size()/9;
	m_nbVertices = m_vertices.size();
	m_nbTextures = m_textures.size();
	m_nbNormals = m_normals.size();


	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size()*4, m_vertices.data(), GL_STATIC_DRAW);
}

const float* Mesh::getVertPtr() const{
	return m_vertices.data();
}

GLuint Mesh::getVertexBufferID() const{
	return vertexBuffer;
}

unsigned int Mesh::getNbFace() const{
	return m_nbFace;
}
