#ifndef DISPLAY_H
#define DISPLAY_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "settings.h"
#include "copyright/mesh.h"
#include "copyright/text.h"
#include "World Stuff/world.h"
#include "Player Stuff/player.h"
#include "copyright/audio.h"

class Display
{
public:
	Display(Settings* settings);
	~Display();
	void clear();
	void update();
	void init();
	void draw();
	void resize(const int width, const int height);
	GLFWwindow* getWindow();
protected:
private:
	GLFWwindow* window;
	Settings* settings;
	Images* images;
	Mesh* quadMesh;
	Shader* shader;
	Audio* audio;
	Text* text;
	World* world;
	Player* player;

	void resetWindow();
};
#endif