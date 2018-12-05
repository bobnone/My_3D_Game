#ifndef BASICOBJECT_H
#define BASICOBJECT_H
#define GLM_ENABLE_EXPERIMENTAL

#include <GLM/glm.hpp>
#include <GLM/gtx/transform.hpp>
#include "images.h"
#include "../Copyright/mesh.h"
using namespace glm;

class BasicObject
{
public:
	mat4 getModel() const;
	// Position:
	void setPosition(const vec3 position);
	void setPosition(const float x, const float y, const float z);
	void setPositionX(const float x);
	void setPositionY(const float y);
	void setPositionZ(const float z);
	vec3 getPosition();
	float getPositionX();
	float getPositionY();
	float getPositionZ();
	// Rotation (Axis Rotation + Position):
	void setRotation(const vec3 rotation);
	void setRotation(const float x, const float y, const float z);
	// Radians
	void setRotationX(const float x);
	void setRotationY(const float y);
	void setRotationZ(const float z);
	//Degrees
	void setRotationDegreesX(const int x);
	void setRotationDegreesY(const int y);
	void setRotationDegreesZ(const int z);
	vec3 getRotation();
	float getRotationX();
	float getRotationY();
	float getRotationZ();
	// Scale:
	void setScale(const vec3 scale);
	void setScale(const float x, const float y, const float z);
	void setScaleX(float x);
	void setScaleY(float y);
	void setScaleZ(float z);
	vec3 getScale();
	float getScaleX();
	float getScaleY();
	float getScaleZ();
	Mesh* getMesh();
	GLuint getTexture();
protected:
	vec3 position; //<x, y, z> // Position on the screen (Offset from worldCords)
	vec3 rotation; //<x, y, z>
	vec3 scale; //<x, y, z>
	Mesh* mesh;
	GLuint textureID;
	Images* images;
	float radians(const int x);
private:
};
#endif