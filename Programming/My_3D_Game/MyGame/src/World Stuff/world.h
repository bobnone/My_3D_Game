#ifndef WORLD_H
#define WORLD_H

#include "cube.h"

class World
{
public:
	World(Images* images);
	~World();
	void draw(Shader& shader, Camera& camera);
protected:
private:
	Block* blocks[14];
	Mesh* mesh;
	void genCubeMesh();	
};
#endif