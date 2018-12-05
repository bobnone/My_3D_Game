#include "cube.h"

Cube::Cube(Images* images, Mesh* mesh, const string name, const char* fileName, const vec3 position, const vec3 rotation, const vec3 scale)
{
	this->images = images;
	this->mesh = mesh;
	this->textureID = images->genTexture(fileName);
	this->position = position;
	this->worldCoordinates = position;
	this->rotation = rotation;
	this->scale = scale;
	this->name = name;
	type = BASIC;
	solid = true;
}
// Overrides:
void Cube::draw(Shader& shader, Camera& camera)
{
	shader.update(*this, camera);
	images->setTexture(textureID);
	mesh->draw();
}