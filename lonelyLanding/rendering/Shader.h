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
	Shader(GLenum type);
	~Shader();
	bool load(const char* path);
	GLint compile();
	void printCompileInfo() const;

private:
	GLuint m_id;
	GLchar* compileInfo;

};

#endif /* SHADER_H_ */
