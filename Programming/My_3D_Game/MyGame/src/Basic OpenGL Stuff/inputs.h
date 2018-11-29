#ifndef INPUTS_H
#define INPUTS_H

#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

class Inputs
{
public:
	// Key callback
	void keyRelease(GLFWwindow* window, int key, int scancode, int mods);
	// Key callback
	void keyPress(GLFWwindow* window, int key, int scancode, int mods);
	// Key callback
	void keyRepeat(GLFWwindow* window, int key, int scancode, int mods);
	// Mouse button callback
	void mouseButtonCallback();
	// Scroll callback
	void scrollCallback();
	// Update method
	void update();
protected:
private:
};
#endif