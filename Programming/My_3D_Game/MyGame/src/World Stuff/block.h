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
	void setWorldCords(vec3 position);
	void setWorldCords(float x, float y, float z);
	void setWorldCordsX(float x);
	void setWorldCordsY(float y);
	void setWorldCordsZ(float z);
	vec3 getWorldCords();
	float getWorldCordsX();
	float getWorldCordsY();
	float getWorldCordsZ();
	string getName();
	BlockType getType();
	void setSolid(bool solid);
	bool isSolid();
protected:
	vec3 worldCords; // <x, y, z> // Position in the world
	string name; // Name for the block (must be unique)
	BlockType type; // The type of block
	bool solid; // Is it solid
private:
};
#endif
