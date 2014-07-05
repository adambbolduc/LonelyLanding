/*
 * Program.h
 *
 *  Created on: 2014-05-29
 *      Author: Adam
 */

#ifndef PROGRAM_H_
#define PROGRAM_H_

#include <GL/glew.h>

#include "Shader.h"
#include <set>
#include <string>

class Program {

public:
	Program();
	~Program();
	Program(GLuint programID);

	bool attachShader(Shader shader);
	bool detachShader(Shader shader);

	void bindAttribLocation(GLint index,const std::string& name);
	void link();
	GLuint getID() const;
	void getUniformLocation();
	int getMVPLocation() const;
	int getLightLocation() const;

private:
	GLuint m_id;
	std::set<GLuint> m_shaders;
	int MVP_location;

};

#endif /* PROGRAM_H_ */
