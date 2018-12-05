#ifndef HUD_H
#define HUD_H

#include "../Basic OpenGL Stuff/basic_object.h"
#include "../copyright/shader.h"

class Hud : public BasicObject
{
public:
	Hud(Images* images, Mesh* mesh, const char* fileName, const vec3 position = vec3(0.0f, 0.0f, 0.0f), const vec3 rotation = vec3(0.0f, 0.0f, 0.0f), const vec3 scale = vec3(1.0f, 1.0f, 1.0f));
	void draw(Shader& shader, Camera& camera);
	GLuint getTexture();
	void moveUp(float amt);
	void moveForward(float amt);
	void moveRight(float amt);
	void resize(const int width, const int height);
protected:
private:
};
#endif