#include "hud.h"

Hud::Hud(Images* images, Mesh* mesh, const char* fileName, const vec3 position, const vec3 rotation, const vec3 scale)
{
	this->images = images;
	this->mesh = mesh;
	this->textureID = images->genTexture(fileName);
	this->position = position;
	this->scale = scale;
}
void Hud::draw(Shader& shader, Camera& camera)
{
	shader.update(*this, camera);
	images->setTexture(textureID);
	mesh->draw();
}
GLuint Hud::getTexture()
{
	return textureID;
}
void Hud::moveUp(float amt)
{
	setPositionY(position.y + amt);
}
void Hud::moveForward(float amt)
{
	setPositionZ(position.z + amt);
}
void Hud::moveRight(float amt)
{
	setPositionX(position.x + amt);
}
void Hud::resize(const int width, const int height)
{
	//XXX: resize the hud
}