#ifndef GAME_H
#define GAME_H

#include "callbacks.h"
#include "display.h"
#include "settings.h"

class Game
{
public:
	// Start Game
	void start();
	// Update method
	void update(float deltaTime);
	// Used to crash the game
	static void crash();
protected:
private:
	Settings* settings;
	Display* display;
	Callbacks* callbacks;

	// Initial Setup
	void init();
	// Used to shutdown the game
	void shutdown();
	// Extention support Checker
	void extentionSupport();
};
#endif