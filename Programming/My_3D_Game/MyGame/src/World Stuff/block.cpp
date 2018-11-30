#include "block.h"

// To be overriden
void Block::draw(Shader& shader, Camera& camera)
{
}
// WorldCords:
void Block::setWorldCords(vec3 position)
{
	worldCords = position;
}
void Block::setWorldCords(float x, float y, float z)
{
	worldCords.x = x;
	worldCords.y = y;
	worldCords.z = z;
}
void Block::setWorldCordsX(float x)
{
	worldCords.x = x;
}
void Block::setWorldCordsY(float y)
{
	worldCords.y = y;
}
void Block::setWorldCordsZ(float z)
{
	worldCords.z = z;
}
vec3 Block::getWorldCords()
{
	return worldCords;
}
float Block::getWorldCordsX()
{
	return worldCords.x;
}
float Block::getWorldCordsY()
{
	return worldCords.y;
}
float Block::getWorldCordsZ()
{
	return worldCords.z;
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