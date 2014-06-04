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

Mesh::Mesh() : vertexBuffer(0){}

Mesh::~Mesh(){}

void Mesh::load(const char* path){
	std::ifstream inputFile;
	std::string line;
	inputFile.open(path);


	inputFile.close();
}
