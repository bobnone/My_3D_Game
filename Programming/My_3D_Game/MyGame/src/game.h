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
protected:
private:
	Settings* settings;
	Display* display;
	Callbacks* callbacks;

	// Initial Setup
	void init();
	// Extention support Checker
	void extentionSupport();
	// Update method
	void update(const float deltaTime);
	// Used to crash the game
	void crash();
	// Used to shutdown the game
	void shutdown();
};
#endif