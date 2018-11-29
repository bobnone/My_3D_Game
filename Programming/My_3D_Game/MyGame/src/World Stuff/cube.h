#ifndef CUBE_H
#define CUBE_H

#include "block.h"
#include "../Basic OpenGL Stuff/images.h"

class Cube: public Block
{
public:
	Cube(Images* images, const string name, const char* fileName, const vec3 position = vec3(0.0f, 0.0f, 2.0f), const vec3 scale = vec3(1.0f, 1.0f, 1.0f));
	~Cube();
	GLuint getTexture();
	// Overrides:
	void draw(Shader& shader, Camera& camera);
protected:
private:
	GLuint textureID;
	Images* images;
	Mesh* genMesh();
};
#endif