#include "block.h"

// To be overriden
void Block::draw(Shader& shader, Camera& camera)
{
}
string Block::getName()
{
	return name;
}
BlockType Block::getType()
{
	return type;
}