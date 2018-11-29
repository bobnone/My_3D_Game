#ifndef BLOCK_H
#define BLOCK_H

#include "../Basic OpenGL Stuff/basic_object.h"
#include "../copyright/shader.h"

enum BlockType
{
	FLOOR,
	WALL,
	DOOR,
	UNKNOWN
};
class Block: public BasicObject
{
public:
	virtual void draw(Shader& shader, Camera& camera);
	string getName();
	BlockType getType();
protected:
	string name; // Name for the tile (must be unique)
	BlockType type; //The type of tile
private:
};
#endif
