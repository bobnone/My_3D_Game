#include "world.h"

World::World(Images* images)
{
	Mesh* mesh = genCubeMesh();
	blocks[0] = new Cube(images, mesh, "wall", "./Resources/Textures/Tile.png", vec3(5.0f, -1.0f, 2.0f));
	blocks[1] = new Cube(images, mesh, "wall", "./Resources/Textures/WALL1.png", vec3(0.0f, 0.0f, 2.0f));
	blocks[2] = new Cube(images, mesh, "wall", "./Resources/Textures/WALL1.png", vec3(1.0f, 0.0f, 2.0f));
	blocks[3] = new Cube(images, mesh, "wall", "./Resources/Textures/WALL1.png", vec3(2.0f, 0.0f, 2.0f));
	blocks[4] = new Cube(images, mesh, "wall", "./Resources/Textures/WALLcorner1.png", vec3(3.0f, 0.0f, 2.0f));
	blocks[5] = new Cube(images, mesh, "wall", "./Resources/Textures/WALL1.png", vec3(3.0f, 1.0f, 2.0f));
	blocks[5]->setRotationZ(270);
	blocks[6] = new Cube(images, mesh, "wall", "./Resources/Textures/Tile.png", vec3(0.0f, -1.0f, 2.0f));
	blocks[7] = new Cube(images, mesh, "wall", "./Resources/Textures/Tile.png", vec3(1.0f, -1.0f, 2.0f));
	blocks[8] = new Cube(images, mesh, "wall", "./Resources/Textures/Tile.png", vec3(2.0f, -1.0f, 2.0f));
	blocks[9] = new Cube(images, mesh, "wall", "./Resources/Textures/Tile.png", vec3(3.0f, -1.0f, 2.0f));
	blocks[10] = new Cube(images, mesh, "wall", "./Resources/Textures/Tile.png", vec3(4.0f, -1.0f, 2.0f));
	blocks[11] = new Cube(images, mesh, "wall", "./Resources/Textures/Tile.png", vec3(4.0f, 0.0f, 2.0f));
	blocks[12] = new Cube(images, mesh, "wall", "./Resources/Textures/WALLcorner1.png", vec3(5.0f, 0.0f, 2.0f));
	blocks[13] = new Cube(images, mesh, "wall", "./Resources/Textures/WALL1.png", vec3(5.0f, 1.0f, 2.0f));
	blocks[13]->setRotationZ(90);
}
World::~World()
{
	for (int i = 0; i < 14; i++)
	{
		delete blocks[i];
		blocks[i] = NULL;
	}
}
void World::draw(Shader& shader, Camera& camera)
{
	for (int i = 0; i < 14; i++)
	{
		blocks[i]->draw(shader, camera);
	}
}
Mesh* World::genCubeMesh()
{
	Vertice vertices[] =
	{
		Vertice(vec3(1.0f, 0.0f, 0.0f), vec2(1, 0), vec4(1.0f, 0.0f, 0.0f, 0.5f)),// Front Bottom Left  0
		Vertice(vec3(0.0f, 0.0f, 0.0f), vec2(0, 0), vec4(0.0f, 1.0f, 0.0f, 0.5f)),// Front Bottom Right 1
		Vertice(vec3(1.0f, 1.0f, 0.0f), vec2(1, 1), vec4(0.0f, 0.0f, 1.0f, 0.5f)),// Front Top Left     2
		Vertice(vec3(0.0f, 1.0f, 0.0f), vec2(0, 1), vec4(1.0f, 1.0f, 0.0f, 0.5f)),// Front Top Right    3
		Vertice(vec3(1.0f, 0.0f, 1.0f), vec2(1, 0)),// Back Bottom Left   4
		Vertice(vec3(0.0f, 0.0f, 1.0f), vec2(0, 0)),// Back Bottom Right  5
		Vertice(vec3(1.0f, 1.0f, 1.0f), vec2(1, 1)),// Back Top Left      6
		Vertice(vec3(0.0f, 1.0f, 1.0f), vec2(0, 1)) // Back Top Right     7
	};
	//						  Front 1, Front 2, Left 1, Left 2, Back 1, Back 2, Right 1, Right 2, Top 1, Top 2, Bottom 1, Bottom 2
	unsigned int indices[] = { 2,0,1,   1,3,2,   3,1,5,  5,7,3,  5,4,6,  6,7,5,  2,6,4,   4,0,2,   6,2,3, 3,7,6, 1,0,4,    4,5,1 };
	return new Mesh(vertices, 8, indices, 36);
}