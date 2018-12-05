#include "block.h"

// To be overriden
void Block::draw(Shader& shader, Camera& camera)
{
}
// WorldCords:
void Block::setWorldCoordinates(vec3 worldCoordinates)
{
	this->worldCoordinates = worldCoordinates;
}
void Block::setWorldCoordinatesX(float x)
{
	worldCoordinates.x = x;
}
void Block::setWorldCoordinatesY(float y)
{
	worldCoordinates.y = y;
}
void Block::setWorldCoordinatesZ(float z)
{
	worldCoordinates.z = z;
}
vec3 Block::getWorldCoordinates()
{
	return worldCoordinates;
}
float Block::getWorldCoordinatesX()
{
	return worldCoordinates.x;
}
float Block::getWorldCoordinatesY()
{
	return worldCoordinates.y;
}
float Block::getWorldCoordinatesZ()
{
	return worldCoordinates.z;
}
string Block::getName()
{
	return name;
}
BlockType Block::getType()
{
	return type;
}
void Block::setSolid(bool solid)
{
	this->solid = solid;
}
bool Block::isSolid()
{
	return solid;
}