#ifndef BASICOBJECT_H
#define BASICOBJECT_H

#include "game_math.h"
#include "../copyright/camera.h"
#include "../copyright/mesh.h"

class BasicObject
{
public:
	mat4 getModel() const;
	mat4 getMVP(const Camera& camera) const;
	bool isSolid();
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
	// WorldCords:
	void setWorldCords(vec3 position);
	void setWorldCords(float x, float y, float z);
	void setWorldCordsX(float x);
	void setWorldCordsY(float y);
	void setWorldCordsZ(float z);
	vec3 getWorldCords();
	float getWorldCordsX();
	float getWorldCordsY();
	float getWorldCordsZ();
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
protected:
	bool solid;
	vec3 position; //<x, y, z> // Position on the screen (Offset from worldCords)
	vec3 worldCords; //<x, y, z> // Position in the world
	vec3 rotation; //<x, y, z>
	vec3 scale; //<x, y, z>
	Mesh* mesh;
	void setSolid(bool solid);
private:
};
#endif