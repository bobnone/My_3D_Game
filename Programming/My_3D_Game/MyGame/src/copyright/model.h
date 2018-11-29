#ifndef MODEL_H
#define MODEL_H

#include <GLM/glm.hpp>
#include <vector>
using namespace std;
using namespace glm;

struct Model
{
public:
	vector<vec3> position;
	vector<vec2> texCoords;
	vector<vec3> normal;
	vector<unsigned int> indices;
protected:
private:
};
#endif