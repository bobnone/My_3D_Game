#ifndef CAMERA_H
#define CAMERA_H
#define GLM_ENABLE_EXPERIMENTAL

#include <GLM/glm.hpp>
#include <GLM/gtx/transform.hpp>
using namespace glm;

struct Camera
{
public:
	Camera(const vec3& position, float fov, float aspect, float zNear, float zFar);
	void updateProjection(float fov, float aspect, float zNear, float zFar);
	mat4 getViewProjection() const;
	// Movement:
	void moveRight(float amount);
	void moveUp(float amount);
	void moveForward(float amount);
	// Rotation:
	void Roll(float angle);
	void Pitch(float angle);
	void Yaw(float angle);
protected:
private:
	mat4 projection;
	vec3 position;
	vec3 right;
	vec3 up;
	vec3 forward;
};
#endif