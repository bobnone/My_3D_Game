#include "display.h"

void Display::resetWindow() //also used to initialy setup the window
{
	const char* TITLE = "<My 3D Game>";
	// Window Options
	glfwSwapInterval(1); //vsync 0=off/1=on
	glfwWindowHint(GLFW_MAXIMIZED, GL_TRUE);
	glfwWindowHint(GLFW_REFRESH_RATE, GLFW_DONT_CARE);
	/*switch (settings->getWindowMode())
	{
	case 0: // Fullscreen
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		glfwWindowHint(GLFW_DECORATED, GL_FALSE);
		window = glfwCreateWindow(currentVideoMode->width, currentVideoMode->height, TITLE, primaryMonitor, 0);
		break;
	case 2: // Borderless-Windowed
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
		glfwWindowHint(GLFW_DECORATED, GL_FALSE);
		window = glfwCreateWindow(settings->getWindowWidth(), settings->getWindowHeight(), TITLE, primaryMonitor, 0);
		break;
	default: // Windowed
		glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
		glfwWindowHint(GLFW_DECORATED, GL_TRUE);
		window = glfwCreateWindow(settings->getWindowWidth(), settings->getWindowHeight(), TITLE, primaryMonitor, 0);
		break;
	}*/
	//GLFWwindow* second_window = glfwCreateWindow(640, 480, "Second Window", NULL, first_window);
	if (window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);
}
Display::Display(Settings* settings)
{
	this->settings = settings;

	//primary monitor,multi-monitor,viewmode,multi-viewmodes,...
	/*GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
	int monitorCount;
	GLFWmonitor** monitors = glfwGetMonitors(&monitorCount);
	const GLFWvidmode* currentVideoMode = glfwGetVideoMode(primaryMonitor);
	int videModeCount;
	const GLFWvidmode* videModes = glfwGetVideoModes(primaryMonitor, &videModeCount);
	glfwWindowHint(GLFW_RED_BITS, currentVideoMode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, currentVideoMode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, currentVideoMode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, currentVideoMode->refreshRate);*/

	/*// Monitor DPI:
	int widthMM, heightMM; // Millimeter guess of actual monitor size (not resolution)
	glfwGetMonitorPhysicalSize(primaryMonitor, &widthMM, &heightMM);
	// Calculate the DPI of a monitor.
	const double dpi = currentVideoMode->width / (widthMM / 25.4);*/


	/*// Virtual Position:
	// The position of the monitor on the virtual desktop, in screen coordinates.
	int xpos, ypos;
	glfwGetMonitorPos(primaryMonitor, &xpos, &ypos);*/

	/*// Human-readable name:
	//The human-readable, UTF-8 encoded name of a monitor.
	const char* monitorName = glfwGetMonitorName(primaryMonitor);*/

	/*//Gamma ramp:
	//setting the gamma ramp of a monitor.
	GLFWgammaramp ramp;
	unsigned short red[256], green[256], blue[256];
	ramp.size = 256;
	ramp.red = red;
	ramp.green = green;
	ramp.blue = blue;
	for (int i = 0; i < ramp.size; i++)
	{
		// Fill out gamma ramp arrays as desired
	}
	glfwSetGammaRamp(primaryMonitor, &ramp);
	//Note: It is recommended to use gamma ramps of size 256, as that is the size supported by all graphics cards on all platforms.
	//The current gamma ramp for a monitor.
	const GLFWgammaramp* currentGammaRamp = glfwGetGammaRamp(primaryMonitor);
	//If you wish to set a regular gamma ramp, you can have GLFW calculate it for you from the desired exponent.
	glfwSetGamma(primaryMonitor, 1.0);*/

	// Create the window and stuff
	//resetWindow();
	// Create the window and stuff (temp)
	glfwSwapInterval(1); //vsync 0=off/1=on
	//glfwWindowHint(GLFW_MAXIMIZED, GL_TRUE);
	width = settings->getWindowWidth();
	height = settings->getWindowHeight();
	window = glfwCreateWindow(width, height, "<My 3D Game>", 0, 0);
	if (window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
		return;
	}
	// Tells GLFW to capture our mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	// Tells OpenGL to use this window
	glfwMakeContextCurrent(window);
}
void Display::clear()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
}
// Input handleing
void Display::processInputs(float deltaTime)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}	
	if (glfwGetKey(window, GLFW_KEY_W)==GLFW_PRESS)
	{
		player->moveUp(deltaTime);
	}
	else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		player->moveUp(-deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		player->moveRight(-deltaTime);
	}
	else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		player->moveRight(deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		player->moveForward(deltaTime);
	}
	else if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		player->moveForward(-deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
	{
		player->Roll(-deltaTime);
	}
	else if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
	{
		player->Roll(deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
	{
		player->Pitch(-deltaTime);
	}
	else if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
	{
		player->Pitch(deltaTime);
	}
	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
	{
		player->Yaw(deltaTime);
	}
	else if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
	{
		player->Yaw(-deltaTime);
	}
}
void Display::init()
{
	images = new Images();
	quadMesh = new Mesh(MESH_RECTANGLE);
	shader = new Shader("./Data/gameShader");
	text = new Text("./Data/textShader", width, height);
	world = new World(images);
	player = new Player(images, quadMesh, "bobnone", "./Resources/Textures/ANOTHERCHARACTERRRRquestionmark1.png");
	audio = new Audio(0, "./Resources/Music/Music5.wav");
	resize(width, height);
}
void Display::draw()
{
	clear();
	//TODO:2Dshader->setCurrent();// For hud
	text->draw("This is sample text", 25.0f, 25.0f, 1.0f, vec3(0.5, 0.8f, 0.2f));
	text->draw("LearnOpenGL.com", 540.0f, 570.0f, 0.5f, vec3(0.3, 0.7f, 0.9f));
	shader->setCurrent();
	world->draw(*shader, *(player->getCamera()));
	player->draw(*shader);
}
void Display::resize(const int width, const int height)
{
	this->width = width;
	this->height = height;
	settings->setWindowWidth(width);
	settings->setWindowHeight(height);
	player->resize(width, height);
}
Display::~Display()
{
	delete images;
	images = NULL;
	delete quadMesh;
	quadMesh = NULL;
	delete shader;
	shader = NULL;
	delete audio;
	audio = NULL;
	delete text;
	text = NULL;
	delete world;
	world = NULL;
	delete player;
	player = NULL;
	glfwDestroyWindow(window);
}
GLFWwindow* Display::getWindow()
{
	return window;
}
int Display::getWindowWidth()
{
	return width;
}
int Display::getWindowHeight()
{
	return height;
}
Camera* Display::getCamera()
{
	return player->getCamera();
}