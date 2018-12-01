#ifndef BASICOBJECT_H
#define BASICOBJECT_H
#define GLM_ENABLE_EXPERIMENTAL

#include <GLM/glm.hpp>
#include <GLM/gtx/transform.hpp>
#include "game_math.h"
#include "images.h"
#include "../Copyright/mesh.h"
using namespace glm;

class BasicObject
{
public:
	mat4 getModel() const;
	// Position:
	void setPosition(vec3 position);
	void setPosition(float x, float y, float z);
	void setPositionX(float x);
	void setPositionY(float y);
	void setPositionZ(float z);
	vec3 getPosition();
	float getPositionX();
	float getPositionY();
	float getPositionZ();
	// Rotation (Axis Rotation + Position):
	void setRotation(vec3 rotation);
	void setRotation(float x, float y, float z);
	// Radians
	void setRotationX(float x);
	void setRotationY(float y);
	void setRotationZ(float z);
	//Degrees
	void setRotationDegreesX(int x);
	void setRotationDegreesY(int y);
	void setRotationDegreesZ(int z);
	vec3 getRotation();
	float getRotationX();
	float getRotationY();
	float getRotationZ();
	// Scale:
	void setScale(vec3 scale);
	void setScale(float x, float y, float z);
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
private:
};
#endif