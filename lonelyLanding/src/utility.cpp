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

std::string util::LoadSource(const char* filename){
	std::ifstream ifile(filename);
	std::string filetext;
	if(!ifile){
		std::cerr << "Cannot open file " << filename << std::endl;
	}
	while( ifile.good() ) {
		std::string line;
		std::getline(ifile, line);
		filetext.append(line + "\n");
	}
	return filetext;
}

