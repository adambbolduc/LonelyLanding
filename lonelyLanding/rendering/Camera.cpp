/*
 * Camera.cpp
 *
 *  Created on: 2014-06-01
 *      Author: Adam
 */

#include "Camera.h"


Camera::Camera() : m_pos(), m_theta(0),m_phi(0), m_viewMatrix(1.0),m_projection() {}

void Camera::setPos(const glm::vec3& position){
	m_pos = position;
}

void Camera::setOrientation(float theta, float phi){
	m_theta = theta;
	m_phi = phi;
}

void Camera::setViewMatrix(){
	m_viewMatrix = glm::lookAt(m_pos,m_pos+glm::vec3(glm::cos(m_theta)*glm::cos(m_phi),glm::cos(m_theta)*glm::sin(m_phi),glm::sin(m_theta)),glm::vec3(0,0,1));
}

void Camera::setProjectionMatrix(float viewAngle,float ratio, float near, float far){
	m_projection = glm::perspective(viewAngle,ratio,near,far);
}

void Camera::translate(const glm::vec3& displacement){
	m_pos += displacement;
}

void Camera::move(const glm::vec3& displacement){
	translate(glm::vec3(glm::cos(m_phi)*displacement.x - glm::sin(m_phi)*displacement.y ,
						glm::sin(m_phi)*displacement.x + glm::cos(m_phi)*displacement.y ,
						displacement.z + glm::sin(m_theta)*displacement.x));
}


void Camera::rotate(float dTheta,float dPhi){
	m_theta += dTheta;
	m_phi += dPhi;
}

glm::mat4 Camera::getMatrix() const{
	return m_projection*m_viewMatrix;
}
