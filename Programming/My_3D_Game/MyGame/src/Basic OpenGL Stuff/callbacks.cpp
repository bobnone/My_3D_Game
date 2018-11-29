#include "callbacks.h"

Display* local_display;
Inputs* local_inputs;

// Error callback
void errorCallback(int error, const char* description)
{
	fputs(description, stderr);
}
// Framebuffer size callback
void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
// Window close callback
void windowCloseCallback(GLFWwindow* window)
{
	/*if (!time_to_close)
	{
		glfwSetWindowShouldClose(window, GL_FALSE);
	}*/
}
// Window size callback
void windowSizeCallback(GLFWwindow* window, int width, int height)
{
	local_display->resize(width, height);
}
// Window position callback
void windowPositionCallback(GLFWwindow* window, int xpos, int ypos)
{
	//
}
// Key callback
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	switch (action)
	{
	case GLFW_RELEASE:
		local_inputs->keyRelease(window, key, scancode, mods);
		break;
	case GLFW_PRESS:
		local_inputs->keyPress(window, key, scancode, mods);
		break;
	case GLFW_REPEAT:
		local_inputs->keyRepeat(window, key, scancode, mods);
		break;
	}
}
// Mouse button callback
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		//inputs->mousePress(window, button, mods);
	}
}
// Scroll callback
void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	//
}
void monitorCallback(GLFWmonitor* monitor, int event)
{
	if (event == GLFW_CONNECTED)
	{
		// The monitor was connected
	}
	else if (event == GLFW_DISCONNECTED)
	{
		// The monitor was disconnected
	}
}
// wrapper for error related callbacks (must be called before Init(), as it is use during Init())
void Callbacks::errorCallbacks()
{
	// Setup Error Callback
	glfwSetErrorCallback(errorCallback);
}
// Init metod
Callbacks::Callbacks(Display* display, Inputs* inputs)
{
	this->display = display;
	local_display = display;
	local_inputs = inputs;
}
// Wrapper for display(window+context) related callbacks
void Callbacks::displayCallbacks()
{
	glfwSetFramebufferSizeCallback(display->getWindow(), framebufferSizeCallback);
	glfwSetWindowCloseCallback(display->getWindow(), windowCloseCallback);
	glfwSetWindowSizeCallback(display->getWindow(), windowSizeCallback);
	glfwSetWindowPosCallback(display->getWindow(), windowPositionCallback);
}
// Wrapper for monitor related callbacks
void Callbacks::monitorCallbacks()
{
	glfwSetMonitorCallback(monitorCallback);
}
// wrapper for input related callbacks
void Callbacks::inputCallbacks()
{
	//glfwGetInputMode(display->getWindow(), mode);
	//glfwSetInputMode(display->getWindow(), mode, value);
	//glfwGetKey(display->getWindow(), key);
	glfwSetKeyCallback(display->getWindow(), keyCallback);
	//glfwGetMouseButton(display->getWindow(), button);
	glfwSetMouseButtonCallback(display->getWindow(), mouseButtonCallback);
	//glfwGetCursorPos(display->getWindow(), xpos, ypos);
	//glfwSetCursorPos(display->getWindow(), xpos, ypos);
	//glfwSetCursorPosCallback(display->getWindow(), cursorPositionCallback);
	//glfwSetCursorEnterCallback(display->getWindow(), cursorEnterCallback);
	glfwSetScrollCallback(display->getWindow(), scrollCallback);
	//glfwSetCharCallback(display->getWindow(), charCallback);
}