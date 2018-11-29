#include "camera.h"

Camera::Camera(const vec3& position, float fov, float aspect, float zNear, float zFar)
{
	this->position = position;
	this->right = vec3(1.0f, 0.0f, 0.0f);
	this->up = vec3(0.0f, 1.0f, 0.0f);
	this->forward = vec3(0.0f, 0.0f, 1.0f);
	this->projection = perspective(fov, aspect, zNear, zFar);
}
void Camera::updateProjection(float fov, float aspect, float zNear, float zFar)
{
	this->projection = perspective(fov, aspect, zNear, zFar);
}
mat4 Camera::getViewProjection() const
{
	return projection * lookAt(position, position + forward, up);
}
void Camera::moveRight(float amount)
{
	position += cross(up, forward) * amount;
}
void Camera::moveUp(float amount)
{
	position += up * amount;
}
void Camera::moveForward(float amount)
{
	position += forward * amount;
}
void Camera::Roll(float angle)
{
	static const vec3 UP(0.0f, 1.0f, 0.0f);
	mat4 rotation = rotate(angle, UP);
	up = vec3(normalize(rotation * vec4(up, 0.0)));
	forward = vec3(normalize(rotation * vec4(forward, 0.0)));
}
void Camera::Pitch(float angle)
{
	vec3 right = normalize(cross(up, forward));
	up = normalize(cross(forward, right));
	forward = vec3(normalize(rotate(angle, right) * vec4(forward, 0.0)));
}
void Camera::Yaw(float angle)
{
	//TODO:
	vec3 right = normalize(cross(up, forward));
	up = vec3(normalize(rotate(angle, right) * vec4(up, 0.0)));
	forward = normalize(cross(forward, right));
}