#ifndef CAMERA_H
#define CAMERA_H
#define GLM_ENABLE_EXPERIMENTAL

#include <GLM/glm.hpp>
#include <GLM/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <iostream>
using namespace std;
using namespace glm;

class Camera
{
public:
	// Constructor with vectors
	Camera(const vec3& position, float fov = 70.0f);
	// Returns the view matrix calculated using Euler Angles and the LookAt Matrix
	mat4 getViewMatrix() const;
	mat4 getProjectionMatrix(float zNear = 0.1f, float zFar = 100.0f) const;
	// Movement:
	void moveRight(float amount);
	void moveUp(float amount);
	void moveForward(float amount);
	// Rotation:
	void Roll(float angle);
	void Pitch(float angle);
	void Yaw(float angle);
	// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
	void processMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);
	// Processes input received from a mouse scroll-wheel event
	void processMouseScroll(float yoffset);
	void resize(const float width, const float height);
protected:
private:
	vec3 position;
	vec3 right;
	vec3 up;
	vec3 forward;
	vec3 worldUp;
	float yaw;
	float pitch;
	float mouseSensitivity;
	float zoom;
	float fov;// Field Of View
	float aspect;// Aspect Ratio
	// Calculates the forward vector from the Camera's (updated) Euler Angles
	void updateCameraVectors();
};
#endif