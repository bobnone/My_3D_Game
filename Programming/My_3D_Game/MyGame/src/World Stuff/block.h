#ifndef BLOCK_H
#define BLOCK_H

#include "../Basic OpenGL Stuff/basic_object.h"
#include "../copyright/shader.h"

enum BlockType
{
	BASIC,
	DOOR,
	UNKNOWN
};
class Block: public BasicObject
{
public:
	virtual void draw(Shader& shader, Camera& camera);
	// WorldCords:
	void setWorldCoordinates(vec3 worldCoordinates);
	void setWorldCoordinatesX(float x);
	void setWorldCoordinatesY(float y);
	void setWorldCoordinatesZ(float z);
	vec3 getWorldCoordinates();
	float getWorldCoordinatesX();
	float getWorldCoordinatesY();
	float getWorldCoordinatesZ();
	string getName();
	BlockType getType();
	void setSolid(bool solid);
	bool isSolid();
protected:
	vec3 worldCoordinates; // <x, y, z> // Position in the world
	string name; // Name for the block (must be unique)
	BlockType type; // The type of block
	bool solid; // Is it solid
private:
};
#endif
