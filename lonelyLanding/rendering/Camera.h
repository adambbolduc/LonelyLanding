/*
 * Camera.h
 *
 *  Created on: 2014-06-01
 *      Author: Adam
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#define GLM_FORCE_RADIANS

#include <glm.hpp>
#include <gtx/transform.hpp>
#include <gtc/type_ptr.hpp>

class Camera {
public:
	Camera();

	void setPos(const glm::vec3& position);
	void setOrientation(float theta, float phi);
	void setViewMatrix();
	void setProjectionMatrix(float viewAngle,float ratio, float near, float far);
	void translate(const glm::vec3& displacement);
	void move(const glm::vec3& displacement);
	void rotate(float dTheta, float dPhi);
	glm::mat4 getMatrix() const;
private:
	//position
	glm::vec3 m_pos;
	// orientation
	float m_theta,m_phi;
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projection;
};

#endif /* CAMERA_H_ */
