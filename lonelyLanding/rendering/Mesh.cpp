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
				m_nbFace(0),
				m_nbVertices(0),
				m_nbTextures(0),
				m_nbNormals(0){}

Mesh::~Mesh(){
	glDeleteBuffers(3,buffersID);
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
					atof(token[1].c_str())/20,
					atof(token[2].c_str())/20,
					atof(token[3].c_str())/20)
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

}

void Mesh::setVertexBufferID(unsigned int dataType, GLuint id){
	buffersID[dataType] = id;
}

void Mesh::setBufferArrayID(GLuint id){
	vertexArray = id;
}

const float* Mesh::getVertPtr() const{
	return m_vertices.data();
}

unsigned int Mesh::getNbFace() const{
	return m_nbFace;
}

const GLuint* Mesh::getBuffersID() const{
	return buffersID;
}

GLuint Mesh::getVAO() const{
	return vertexArray;
}

