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
#include <sstream>
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

vector<string> util::splitStringIntoToken(string line){
	istringstream line_str(line);
	string token;
	vector<string> tokenVector;
	while(!line_str.eof()){
		line_str >> token;
		tokenVector.push_back(token);
	}
	return tokenVector;
}

std::string util::doubleSlash(string s){
	for(unsigned int i=0 ; i < s.length() ; i++){
		if( i < (s.length()-1) &&  s[i] == '/'){
			if(s[i+1] == '/'){
				s.insert(i+1,"1");
				i++;
			}
		}
	}


	return s;
}

string util::slash_to_space(std::string s){
	for(unsigned int i = 0 ; i < s.length() ; i++){
		if(s[i] == '/')
			s[i] = ' ';
	}
	return s;
}




