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
#include <string>


Mesh::Mesh(){}

Mesh::~Mesh(){}

void Mesh::load(const char* path){
	std::ifstream inputFile;
	std::string line;


	inputFile.open(path);
	if(!inputFile){
		return;
	}
	while(getline(inputFile,line)){
		switch(line[0])
		{
		case '#':			// Line is a comment
			break;
		case 'v':			// Line is a vertex...
			if(line[1] == ' '){		// ...coordinate
				vertices.push_back(glm::vec4());
			}
			else if(line[1] == 't'){// ...texture coordinate
				textures.push_back(glm::vec3());
			}
			else if(line[1] == 'n'){// ...normal coordinate
				normals.push_back(glm::vec3());
			}
			break;
		case 'g':			// Line is a group of vertex
			break;
		case 'f':			// Line is an element
			elements.push_back(GLushort(0));
			break;
		default:
			break;

		}
	}

	std::cout << vertices.size() << std::endl;
	std::cout << normals.size() << std::endl;
	std::cout << textures.size() << std::endl;
	std::cout << elements.size() << std::endl;


	normals.resize(vertices.size(), glm::vec3(0.0, 0.0, 0.0));
	for (unsigned int i = 0; i < elements.size(); i+=3) {
		GLushort ia = elements[i];
		GLushort ib = elements[i+1];
		GLushort ic = elements[i+2];
		glm::vec3 normal = glm::normalize(glm::cross(
				glm::vec3(vertices[ib]) - glm::vec3(vertices[ia]),
				glm::vec3(vertices[ic]) - glm::vec3(vertices[ia])));
		normals[ia] = normals[ib] = normals[ic] = normal;
	}

	inputFile.close();
}
