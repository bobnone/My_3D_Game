#include "camera.h"

Camera::Camera(const vec3& position, const vec3& up, const vec3& forward, float yaw, float pitch, float mouseSensitivity, float fov)
{
	this->position = position;
	this->right = vec3(1.0f, 0.0f, 0.0f);//remove
	this->up = vec3(0.0f, 1.0f, 0.0f);//remove
	this->forward = vec3(0.0f, 0.0f, 1.0f);//remove
	//this->forward = forward;
	//this->worldUp = up;
	//this->yaw = yaw;
	//this->pitch = pitch;
	//this->mouseSensitivity = mouseSensitivity;
	this->fov = fov;
	zoom = fov;
	//updateCameraVectors();
}
// Returns the view matrix calculated using Euler Angles and the LookAt Matrix
mat4 Camera::getViewMatrix() const
{
	return lookAt(position, position + forward, up);
}
mat4 Camera::getProjectionMatrix(float zNear, float zFar) const
{
	return perspective(radians(zoom), aspect, zNear, zFar);
}
void Camera::moveRight(const float amount)
{
	position += cross(up, forward) * amount;
	printf("Position: %f\n", amount);
}
void Camera::moveUp(const float amount)
{
	position += up * amount;
	printf("Position: %f\n", amount);
}
void Camera::moveForward(const float amount)
{
	position += forward * amount;
	printf("Position: %f\n", amount);
}
// Z-axis rotation
void Camera::Roll(const float angle)
{
	//
}
// X-axis rotation
void Camera::Pitch(const float angle)
{
	vec3 right = normalize(cross(up, forward));
	up = normalize(cross(forward, right));
	forward = vec3(normalize(rotate(angle, right) * vec4(forward, 0.0)));
}
// Y-axis rotation
void Camera::Yaw(const float angle)
{
	static const vec3 UP(0.0f, 1.0f, 0.0f);
	mat4 rotation = rotate(angle, UP);
	up = vec3(normalize(rotation * vec4(up, 0.0)));
	forward = vec3(normalize(rotation * vec4(forward, 0.0)));
}
// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
void Camera::processMouseMovement(float xoffset, float yoffset, bool constrainPitch)
{
	xoffset *= mouseSensitivity;
	yoffset *= mouseSensitivity;

	yaw += xoffset;
	pitch += yoffset;

	// Make sure that when pitch is out of bounds (screen doesn't get flipped)
	if (constrainPitch)
	{
		if (pitch > 89.0f)
		{
			pitch = 89.0f;
		}
		else if (pitch < -89.0f)
		{
			pitch = -89.0f;
		}
	}
	// Update forward, right and up Vectors using the updated Euler angles
	updateCameraVectors();
}
// Processes input received from a mouse scroll-wheel event
void Camera::processMouseScroll(float yoffset)
{
	if (zoom >= 1.0f && zoom <= fov)
	{
		zoom -= yoffset;
	}
	if (zoom < 1.0f)
	{
		zoom = 1.0f;
	}
	else if (zoom > fov)
	{
		zoom = fov;
	}
}
// Calculates the forward vector from the Camera's (updated) Euler Angles
void Camera::updateCameraVectors()
{
	// Calculate the new forward vector
	vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	forward = normalize(front);
	// Also re-calculate the Right and Up vector
	right = normalize(cross(forward, worldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	up = normalize(cross(right, forward));
}
void Camera::resize(const float width, const float height)
{
	aspect = width / height;
}