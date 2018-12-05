#ifndef DISPLAY_H
#define DISPLAY_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "settings.h"
#include "copyright/audio.h"
#include "copyright/mesh.h"
#include "copyright/text.h"
#include "World Stuff/world.h"
#include "Player Stuff/player.h"

class Display
{
public:
	Display(Settings* settings);
	~Display();
	// Clears the screen and its buffers
	void clear();
	// Input handleing
	void processInputs(float deltaTime);
	void init();
	// Screen rendering
	void draw();
	void resize(const int width, const int height);
	GLFWwindow* getWindow();
	int getWindowWidth();
	int getWindowHeight();
	Camera* getCamera();
protected:
private:
	int width, height;
	GLFWwindow* window;
	Settings* settings;
	Images* images;
	Shader* shader;
	Audio* audio;
	Text* text;
	World* world;
	Player* player;

	void resetWindow();
};
#endif