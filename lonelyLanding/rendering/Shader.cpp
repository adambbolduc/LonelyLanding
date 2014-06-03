/*
 * Shader.cpp
 *
 *  Created on: 2014-05-26
 *      Author: Adam
 */

#include "Shader.h"
#include "../src/utility.h"
#include <iostream>




Shader::Shader(GLenum type) : compileInfo(NULL){
	m_id = glCreateShader(type);
}

Shader::~Shader(){
	if(!compileInfo){
		delete compileInfo;
	}

	glDeleteShader(m_id);
}

bool Shader::load(const char* path){
	std::string cpp_src = util::LoadSource(path);
	const char* src = cpp_src.c_str();
	glShaderSource(m_id, 1, &src, NULL);
	return true;
}

GLint Shader::compile(){

	glCompileShader(m_id);


	GLint success;
	glGetShaderiv(m_id,GL_COMPILE_STATUS,&success);


	if(!success){
		GLint infoLength;
		glGetShaderiv(m_id,GL_INFO_LOG_LENGTH,&infoLength);

		compileInfo = new GLchar[512];
		glGetShaderInfoLog(m_id,512,&infoLength,compileInfo);

	}
	return success;
}

void Shader::printCompileInfo() const{
	std::cout << compileInfo << std::endl;
}

GLuint Shader::getID() const{
	return m_id;
}
