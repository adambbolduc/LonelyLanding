/*
 * Camera.cpp
 *
 *  Created on: 2014-06-01
 *      Author: Adam
 */

#include "Camera.h"

#include <iostream>

Camera::Camera(){
	viewMatrix = glm::mat4(1.0);
	projection = glm::mat4();
}

void Camera::setView(const glm::vec3& eye, const glm::vec3& center, const glm::vec3& up){
	viewMatrix = glm::lookAt(eye,center,up);
}

void Camera::setProjection(float viewAngle,float ratio, float near, float far){
	projection = glm::perspective(viewAngle,ratio,near,far);
}

void Camera::translate(const glm::vec3& displacement){
	viewMatrix = glm::translate(viewMatrix,displacement);
}

void Camera::rotate(float theta, const glm::vec3& axis){
	glm::rotate(viewMatrix,theta,axis);
}

glm::mat4 Camera::getMatrix() const{
	return projection*viewMatrix;
}
