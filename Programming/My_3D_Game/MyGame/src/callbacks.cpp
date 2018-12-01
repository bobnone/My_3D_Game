#include "callbacks.h"

Display* display;
Camera* camera;
float xoffset, yoffset, lastX, lastY;
bool firstMouse = true;

/*	The function signature for Unicode character callbacks.
 *
 *  @param[in] window The window that received the event.
 *  @param[in] codepoint The Unicode code point of the character.
 *
 *  @sa @ref input_char
 *  @sa glfwSetCharCallback
 */
void charCallback(GLFWwindow* window, unsigned int codepoint)
{
	//
}
/*	The function signature for Unicode character with modifiers
 *  callbacks.
 *
 *  This is the function signature for Unicode character with modifiers callback
 *  functions.  It is called for each input character, regardless of what
 *  modifier keys are held down.
 *
 *  @param[in] window The window that received the event.
 *  @param[in] codepoint The Unicode code point of the character.
 *  @param[in] mods Bit field describing which [modifier keys](@ref mods) were
 *  held down.
 *
 *  @sa @ref input_char
 *  @sa glfwSetCharModsCallback
 */
void charModsCallback(GLFWwindow* window, unsigned int codepoint, int mods)
{
	//
}
/*	The function signature for cursor enter/leave callbacks.
 *
 *  @param[in] window The window that received the event.
 *  @param[in] entered `GLFW_TRUE` if the cursor entered the window's client
 *  area, or `GLFW_FALSE` if it left it.
 *
 *  @sa @ref cursor_enter
 *  @sa glfwSetCursorEnterCallback
 */
void cursorEnterCallback(GLFWwindow* window, int entered)
{
	firstMouse = true;
}
/*	The function signature for cursor position callbacks.
 *
 *  @param[in] window The window that received the event.
 *  @param[in] xpos The new cursor x-coordinate, relative to the left edge of
 *  the client area.
 *  @param[in] ypos The new cursor y-coordinate, relative to the top edge of the
 *  client area.
 *
 *  @sa @ref cursor_pos
 *  @sa glfwSetCursorPosCallback
 */
void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}
	xoffset = xpos - lastX;
	yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top
	lastX = xpos;
	lastY = ypos;
	//camera->processMouseMovement(xoffset, yoffset);
}
/*	The function signature for file drop callbacks.
 *
 *  @param[in] window The window that received the event.
 *  @param[in] count The number of dropped files.
 *  @param[in] paths The UTF-8 encoded file and/or directory path names.
 *
 *  @sa @ref path_drop
 *  @sa glfwSetDropCallback
 */
void dropCallback(GLFWwindow* window, int count, const char** paths)
{
	//
}
/*	The function signature for error callbacks.
 *
 *  @param[in] error An [error code](@ref errors).
 *  @param[in] description A UTF-8 encoded string describing the error.
 *
 *  @sa @ref error_handling
 *  @sa glfwSetErrorCallback
 */
void errorCallback(int error, const char* description)
{
	fprintf(stderr, "ERROR: %s Details: %s\n", error, description);
	//Game::crash();
}
/*	The function signature for framebuffer resize callbacks.
 *
 *
 *  @param[in] window The window whose framebuffer was resized.
 *  @param[in] width The new width, in pixels, of the framebuffer.
 *  @param[in] height The new height, in pixels, of the framebuffer.
 *
 *  @sa @ref window_fbsize
 *  @sa glfwSetFramebufferSizeCallback
 */
void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}
/*	The function signature for joystick configuration callbacks.
 *
 *  @param[in] joystick The joystick that was connected or disconnected.
 *  @param[in] event One of `GLFW_CONNECTED` or `GLFW_DISCONNECTED`.
 *
 *  @sa @ref joystick_event
 *  @sa glfwSetJoystickCallback
 */
void joystickCallback(int joystick, int event)
{
	//
}
/*	The function signature for keyboard key callbacks.
 *
 *  @param[in] window The window that received the event.
 *  @param[in] key The [keyboard key](@ref keys) that was pressed or released.
 *  @param[in] scancode The system-specific scancode of the key.
 *  @param[in] action `GLFW_PRESS`, `GLFW_RELEASE` or `GLFW_REPEAT`.
 *  @param[in] mods Bit field describing which [modifier keys](@ref mods) were
 *  held down.
 *
 *  @sa @ref input_key
 *  @sa glfwSetKeyCallback
 */
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	//
}
/*	The function signature for monitor configuration callbacks.
 *
 *  @param[in] monitor The monitor that was connected or disconnected.
 *  @param[in] event One of `GLFW_CONNECTED` or `GLFW_DISCONNECTED`.
 *
 *  @sa @ref monitor_event
 *  @sa glfwSetMonitorCallback
 */
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
/*	The function signature for mouse button callbacks.
 *
 *  @param[in] window The window that received the event.
 *  @param[in] button The [mouse button](@ref buttons) that was pressed or
 *  released.
 *  @param[in] action One of `GLFW_PRESS` or `GLFW_RELEASE`.
 *  @param[in] mods Bit field describing which [modifier keys](@ref mods) were
 *  held down.
 *
 *  @sa @ref input_mouse_button
 *  @sa glfwSetMouseButtonCallback
 */
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	//
}
/*	The function signature for scroll callbacks.
 *
 *  @param[in] window The window that received the event.
 *  @param[in] xoffset The scroll offset along the x-axis.
 *  @param[in] yoffset The scroll offset along the y-axis.
 *
 *  @sa @ref scrolling
 *  @sa glfwSetScrollCallback
 */
void scrollCallback(GLFWwindow* window, double xpos, double ypos)
{
	//camera->processMouseScroll(yoffset);
}
/*	The function signature for window close callbacks.
 *
 *  @param[in] window The window that the user attempted to close.
 *
 *  @sa @ref window_close
 *  @sa glfwSetWindowCloseCallback
 */
void windowCloseCallback(GLFWwindow* window)
{
	/*if (!time_to_close)
	{
		glfwSetWindowShouldClose(window, GL_FALSE);
	}*/
}
/*	The function signature for window focus/defocus callbacks.
 *
 *  @param[in] window The window that gained or lost input focus.
 *  @param[in] focused `GLFW_TRUE` if the window was given input focus, or
 *  `GLFW_FALSE` if it lost it.
 *
 *  @sa @ref window_focus
 *  @sa glfwSetWindowFocusCallback
 */
void windowFocusCallback(GLFWwindow* window, int focused)
{
	firstMouse = true;
}
/*	The function signature for window iconify/restore callbacks.
 *
 *  @param[in] window The window that was iconified or restored.
 *  @param[in] iconified `GLFW_TRUE` if the window was iconified, or
 *  `GLFW_FALSE` if it was restored.
 *
 *  @sa @ref window_iconify
 *  @sa glfwSetWindowIconifyCallback
 */
void windowIconifyCallback(GLFWwindow* window, int iconified)
{
	//
}
/*	The function signature for window position callbacks.
 *
 *  @param[in] window The window that was moved.
 *  @param[in] xpos The new x-coordinate, in screen coordinates, of the
 *  upper-left corner of the client area of the window.
 *  @param[in] ypos The new y-coordinate, in screen coordinates, of the
 *  upper-left corner of the client area of the window.
 *
 *  @sa @ref window_pos
 *  @sa glfwSetWindowPosCallback
 */
void windowPositionCallback(GLFWwindow* window, int xpos, int ypos)
{
	//
}
/*	The function signature for window content refresh callbacks.
 *
 *  @param[in] window The window whose content needs to be refreshed.
 *
 *  @sa @ref window_refresh
 *  @sa glfwSetWindowRefreshCallback
 */
void windowRefreshCallback(GLFWwindow* window)
{
	//
}
/*	The function signature for window resize callbacks.
 *
 *  @param[in] window The window that was resized.
 *  @param[in] width The new width, in screen coordinates, of the window.
 *  @param[in] height The new height, in screen coordinates, of the window.
 *
 *  @sa @ref window_size
 *  @sa glfwSetWindowSizeCallback
 */
void windowSizeCallback(GLFWwindow* window, int width, int height)
{
	display->resize(width, height);
}
Callbacks::Callbacks(Display* dis)
{
	display = dis;
	glfwSetErrorCallback(errorCallback);
	glfwSetMonitorCallback(monitorCallback);
}
void Callbacks::initWindowCallbacks()
{
	GLFWwindow* window = display->getWindow();
	lastX = (float)display->getWindowWidth()/2.0f;
	lastY = (float)display->getWindowHeight()/2.0f;
	camera = display->getCamera();

	glfwSetCharCallback(window, charCallback);
	glfwSetCharModsCallback(window, charModsCallback);
	glfwSetCursorEnterCallback(window, cursorEnterCallback);
	glfwSetCursorPosCallback(window, cursorPositionCallback);
	glfwSetDropCallback(window, dropCallback);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
	glfwSetJoystickCallback(joystickCallback);
	glfwSetKeyCallback(window, keyCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
	glfwSetScrollCallback(window, scrollCallback);
	glfwSetWindowCloseCallback(window, windowCloseCallback);
	glfwSetWindowFocusCallback(window, windowFocusCallback);
	glfwSetWindowIconifyCallback(window, windowIconifyCallback);
	glfwSetWindowPosCallback(window, windowPositionCallback);
	glfwSetWindowRefreshCallback(window, windowRefreshCallback);
	glfwSetWindowSizeCallback(window, windowSizeCallback);
}