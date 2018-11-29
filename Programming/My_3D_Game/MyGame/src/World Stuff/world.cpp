#include "world.h"

World::World(Images* images)
{
	blocks[0] = new Cube(images, "wall", "./Resources/Textures/Tile.png", vec3(5.0f, -1.0f, 2.0f));
	blocks[1] = new Cube(images, "wall", "./Resources/Textures/WALL1.png", vec3(0.0f, 0.0f, 2.0f));
	blocks[2] = new Cube(images, "wall", "./Resources/Textures/WALL1.png", vec3(1.0f, 0.0f, 2.0f));
	blocks[3] = new Cube(images, "wall", "./Resources/Textures/WALL1.png", vec3(2.0f, 0.0f, 2.0f));
	blocks[4] = new Cube(images, "wall", "./Resources/Textures/WALLcorner1.png", vec3(3.0f, 0.0f, 2.0f));
	blocks[5] = new Cube(images, "wall", "./Resources/Textures/WALL1.png", vec3(3.0f, 1.0f, 2.0f));
	blocks[5]->setRotationZ(270);
	blocks[6] = new Cube(images, "wall", "./Resources/Textures/Tile.png", vec3(0.0f, -1.0f, 2.0f));
	blocks[7] = new Cube(images, "wall", "./Resources/Textures/Tile.png", vec3(1.0f, -1.0f, 2.0f));
	blocks[8] = new Cube(images, "wall", "./Resources/Textures/Tile.png", vec3(2.0f, -1.0f, 2.0f));
	blocks[9] = new Cube(images, "wall", "./Resources/Textures/Tile.png", vec3(3.0f, -1.0f, 2.0f));
	blocks[10] = new Cube(images, "wall", "./Resources/Textures/Tile.png", vec3(4.0f, -1.0f, 2.0f));
	blocks[11] = new Cube(images, "wall", "./Resources/Textures/Tile.png", vec3(4.0f, 0.0f, 2.0f));
	blocks[12] = new Cube(images, "wall", "./Resources/Textures/WALLcorner1.png", vec3(5.0f, 0.0f, 2.0f));
	blocks[13] = new Cube(images, "wall", "./Resources/Textures/WALL1.png", vec3(5.0f, 1.0f, 2.0f));
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