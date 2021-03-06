/*
 * Program.cpp
 *
 *  Created on: 2014-05-29
 *      Author: Adam
 */

#include "Program.h"


#include <iostream>


Program::Program() : m_shaders(),MVP_location(0){
	m_id = glCreateProgram();
}

Program::Program(GLuint programID) : m_id(programID), m_shaders(), MVP_location(0) {}

Program::~Program(){
	std::set<GLuint>::iterator it = m_shaders.begin();
	while(it != m_shaders.end()){
		detachShader(*it++);
	}
}

bool Program::attachShader(Shader shader){
	glAttachShader(m_id,shader.getID());
	return m_shaders.insert(shader.getID()).second;
}

bool Program::detachShader(Shader shader){
	glDetachShader(m_id,shader.getID());
	return m_shaders.erase(shader.getID());
}

void Program::bindAttribLocation(GLint index,const std::string& name){
	glBindAttribLocation(m_id, index, name.c_str());
}

void Program::link(){
	glLinkProgram(m_id);
}


GLuint Program::getID() const{
	return m_id;
}

void Program::getUniformLocation(){
	MVP_location = glGetUniformLocation(m_id,"MVP");
}

int Program::getMVPLocation() const{
	return MVP_location;
}

