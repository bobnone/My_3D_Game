#include "vertice.h"

Vertice::Vertice(const vec3& position, const vec2& texCoords, const vec4& color, const vec3& normal)
{
	this->position = position;
	this->texCoords = texCoords;
	this->color = color;
	this->normal = normal;
}
// Returns a vector of XYZ
vec3* Vertice::getPosition()
{
	return &position;
}
// Returns a vector of ST
vec2* Vertice::getTexCoords()
{
	return &texCoords;
}
// Returns a vector of RGBA
vec4* Vertice::getColor()
{
	return &color;
}
// Returns a vector of IJK
vec3* Vertice::getNormal()
{
	return &normal;
}