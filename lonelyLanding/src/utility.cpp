/*
 * utility.cpp
 *
 *  Created on: 2014-05-13
 *  \author: Adam B.-Bolduc
 */

#include "utility.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

void util::error_callback(int error,const char* description){
	std::cerr << description ;
}

char* util::LoadSource(const char* filename){
	ifstream file;
	char* src;
	long size;

	file.open(filename);
	if(!file){
		std::cout << "Can't open file " << filename << std::endl;
	}

	file.seekg(0,file.end);
	size = file.tellg();
	file.seekg(0,file.beg);
	src = new char[size + 1];
	file.read(src,size);
	file.close();
	src[size] = '\0';
	return src;
}

