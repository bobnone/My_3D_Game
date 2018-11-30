#include "cube.h"

Cube::Cube(Images* images, const string name, const char* fileName, const vec3 position, const vec3 rotation, const vec3 scale)
{
	this->images = images;
	genMesh();
	this->textureID = images->genTexture(fileName);
	this->position = position;
	this->worldCords = position;
	this->rotation = rotation;
	this->scale = scale;
	this->name = name;
	type = BASIC;
	solid = true;
}
Cube::~Cube()
{
	delete mesh;
	mesh = NULL;
}
void Cube::genMesh()
{
	Vertice vertices[] =
	{
		Vertice(vec3(1.0f, 0.0f, 0.0f), vec2(1, 0)),// Front Bottom Left  0
		Vertice(vec3(0.0f, 0.0f, 0.0f), vec2(0, 0)),// Front Bottom Right 1
		Vertice(vec3(1.0f, 1.0f, 0.0f), vec2(1, 1)),// Front Top Left     2
		Vertice(vec3(0.0f, 1.0f, 0.0f), vec2(0, 1)),// Front Top Right    3
		Vertice(vec3(1.0f, 0.0f, 1.0f), vec2(1, 0)),// Back Bottom Left   4
		Vertice(vec3(0.0f, 0.0f, 1.0f), vec2(0, 0)),// Back Bottom Right  5
		Vertice(vec3(1.0f, 1.0f, 1.0f), vec2(1, 1)),// Back Top Left      6
		Vertice(vec3(0.0f, 1.0f, 1.0f), vec2(0, 1))// Back Top Right      7
	};
	//						  Front 1, Front 2, Left 1, Left 2, Back 1, Back 2, Right 1, Right 2, Top 1, Top 2, Bottom 1, Bottom 2
	unsigned int indices[] = {2,0,1,   1,3,2,   3,1,5,  5,7,3,  5,4,6,  6,7,5,  2,6,4,   4,0,2,   6,2,3, 3,7,6, 1,0,4,    4,5,1};
	mesh = new Mesh(vertices, 8, indices, 36);
}
// Overrides:
void Cube::draw(Shader& shader, Camera& camera)
{
	shader.update(*this, camera);
	images->setTexture(textureID);
	mesh->draw();
}