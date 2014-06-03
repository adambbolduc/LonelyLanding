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
	void setView(const glm::vec3& eye, const glm::vec3& center, const glm::vec3& up);
	void setProjection(float viewAngle,float ratio, float near, float far);
	void translate(const glm::vec3& displacement);
	void rotate(float theta, const glm::vec3& axis);
	glm::mat4 getMatrix() const;
private:
	glm::mat4 viewMatrix;
	glm::mat4 projection;
};

#endif /* CAMERA_H_ */
