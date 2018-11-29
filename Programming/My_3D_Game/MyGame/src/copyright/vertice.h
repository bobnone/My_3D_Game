#ifndef VERTICE_H
#define VERTICE_H

#include <glm/glm.hpp>
using namespace glm;

class Vertice
{
public:
	Vertice(const vec3& position, const vec2& texCoords, const vec3& normal = vec3(0, 0, -1));
	vec3* getPosition();
	vec2* getTexCoords();
	vec3* getNormal();
protected:
private:
	vec3 position;
	vec2 texCoords;
	vec3 normal;
};
#endif