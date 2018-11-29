#ifndef TILEDOOR_H
#define TILEDOOR_H

#include <vector>
#include "../World Stuff/tile.h"

class TileDoor : public Tile
{
public:
	TileDoor(Images* images, const string name, const char* fileName, const vec3 position = vec3(0.0f, 0.0f, 2.0f), const vec3 scale = vec3(1.0f, 1.0f, 1.0f));
	~TileDoor();
	GLuint getTexture();
	// Overrides:
	void draw(Shader& shader, Camera& camera);
protected:
private:
	Images * images;
	GLuint textureID;
};
#endif
