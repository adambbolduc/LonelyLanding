/*
 * Shader.h
 *
 *  Created on: 2014-05-26
 *      Author: Adam
 */

#ifndef SHADER_H_
#define SHADER_H_

#include <GL/glew.h>
#include <string>

class Shader {

public:
	bool load(const char* path, GLenum shaderType);


private:
	GLuint m_id;

};

#endif /* SHADER_H_ */
