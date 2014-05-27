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
		case '#':
			std::cout << line.substr(1,line.size()) << std::endl;
			break;
		case 'v':
			std::cout << line.substr(1,line.size()) << std::endl;
			break;
		default:
			break;


		}

	}

	inputFile.close();


}
