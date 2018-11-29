#include "vertice.h"

Vertice::Vertice(const vec3& position, const vec2& texCoords, const vec3& normal)
{
	this->position = position;
	this->texCoords = texCoords;
	this->normal = normal;
}
vec3* Vertice::getPosition()
{
	return &position;
}
vec2* Vertice::getTexCoords()
{
	return &texCoords;
}
vec3* Vertice::getNormal()
{
	return &normal;
}