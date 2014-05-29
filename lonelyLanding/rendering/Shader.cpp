/*
 * Shader.cpp
 *
 *  Created on: 2014-05-26
 *      Author: Adam
 */

#include "Shader.h"
#include "../src/utility.h"
#include <iostream>

using namespace util;

bool Shader::load(const char* path, GLenum type){

	m_id = glCreateShader(type);

	const char* src = LoadSource(path);
	glShaderSource(m_id, 1, &src, NULL);

	return true;
}
