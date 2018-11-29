#ifndef GAME_H
#define GAME_H

#include "Basic OpenGL Stuff/callbacks.h"
#include "display.h"
#include "Basic OpenGL Stuff/inputs.h"
#include "settings.h"

class Game
{
public:
	// Start Game
	void start();
	// Update method
	void update();
	// Used to crash the game
	static void crash();
protected:
private:
	Settings* settings;
	Display* display;
	Inputs* inputs;
	Callbacks* callbacks;

	// Initial Setup
	void init();
	// Used to shutdown the game
	void shutdown();
	// Extention support Checker
	void extentionSupport();
};
#endif