/*
 * Mesh.cpp
 *
 *  Created on: 2014-05-26
 *      Author: Adam
 */

#include "Mesh.h"
#include "../src/utility.h"
#include <iostream>

Mesh::Mesh(){}

Mesh::~Mesh(){}

void Mesh::load(const char* path){

	const char* src = util::LoadSource(path);
	std::cout << src << std::endl;
}
