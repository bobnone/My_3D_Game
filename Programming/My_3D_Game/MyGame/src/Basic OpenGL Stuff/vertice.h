#ifndef VERTICE_H
#define VERTICE_H

#include <glm/glm.hpp>
using namespace glm;

class Vertice
{
public:
	Vertice(const vec3& position, const vec2& texCoords, const vec4& color = vec4(1.0f, 1.0f, 1.0f, 1.0f), const vec3& normal = vec3(0, 0, -1));
	// Returns a vector of XYZ TODO:add W
	vec3* getPosition();
	// Returns a vector of ST
	vec2* getTexCoords();
	// Returns a vector of RGBA
	vec4* getColor();
	// Returns a vector of IJK
	vec3* getNormal();
protected:
private:
	vec3 position;	
	vec2 texCoords;
	vec4 color;
	vec3 normal;
};
#endif