#include "game.h"

void Game::init()
{
	// ----------------------------------------------------------
	// GLFW
	// ----------------------------------------------------------
	// Init GLFW
	if (!glfwInit())
	{
		cerr << "ERROR: Failed to load GLFW!" << endl;
		crash();
	}
	glfwWindowHint(GLFW_SAMPLES, 4);// 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);// We want OpenGL version 3.X
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);// We want OpenGL version X.3
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);// To make MacOS happy;
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);// We don't want the old OpenGL 
	// -----------------------------------------------------------// Init Settings
	
	// Init Settings
	settings = new Settings();
	// Init Display
	display = new Display(settings);
	// Init Callbacks
	callbacks = new Callbacks(display);

	// -----------------------------------------------
	// GLEW
	// -----------------------------------------------
	glewExperimental = true;// Needed in core profile
	GLenum err = glewInit();// Init GLEW
	if (err != GLEW_OK)// Check for errors
	{
		cerr << "ERROR: Failed to load GLEW! \nDetails: " << glewGetErrorString(err) << endl;
		crash();
	}
	// -----------------------------------------------

	// -----------------------------------------------
	// Set OpenGL options
	// -----------------------------------------------
	// Enable Depth
	glEnable(GL_DEPTH_TEST);
	// Enable Alpha
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// Enable Culling of hidden/unseen textures
	glEnable(GL_CULL_FACE);
	// -----------------------------------------------

	// Init GL3W
	//gl3wInit();

	// -----------------------------------------------
	// DevIL
	// -----------------------------------------------
	// version checking
	if((ilGetInteger(IL_VERSION_NUM) < IL_VERSION)
	|| (iluGetInteger(ILU_VERSION_NUM) < ILU_VERSION)
	|| (ilutGetInteger(ILUT_VERSION_NUM) < ILUT_VERSION))
	{
		cerr << "ERROR: Failed to load DevIL! \nDeatils: Version mismatch!" << endl;
		crash();
	}
	// Init DevIL Libraries
	ilInit();
	iluInit();
	// Tell DevIL to use OpenGL
	ilutRenderer(ILUT_OPENGL);
	// Disables GPU on-board conversion (everything => 16-bit), allowing DevIL to handle everything
	ilutEnable(ILUT_OPENGL_CONV);
	// Allows files to be overriden (if file already exist)
	ilEnable(IL_FILE_OVERWRITE);
	// -----------------------------------------------

	display->init();
	callbacks->initWindowCallbacks();
}
// Extention support Checker
void Game::extentionSupport()
{
	//TODO: add more extenction checks for GLEW and add checks for others like GLFW
	if (glewIsSupported("GL_VERSION_4_5  GL_ARB_point_sprite"))
	{
		cout << "Great, we have OpenGL 4.5 and point sprites." << endl;
	}
	else if (glewIsSupported("GL_VERSION_4_5"))
	{
		cout << "Great, we have OpenGL 4.5 but not point sprites." << endl;
	}
	else
	{
		cout << "ERROR: No OpenGL 4.5 or point sprites." << endl;
	}
}
// Update method
void Game::update(float deltaTime)
{
	//----------------------------------------------------
	// Error checking
	// ---------------------------------------------------
	// Checks to make sure a window/context is loaded.
	if(!glfwGetCurrentContext())
	{
		cerr << "ERROR: No window currently loaded!" << endl;
		crash();
	}
	// Polls DevIL's Error stack for any errors that may have occurred.
	ILenum ilError = ilGetError();
	if (ilError != IL_NO_ERROR)
	{
		cerr << "ERROR: DevIL crashed! \nDeatils: " << iluErrorString(ilError) << endl;
		crash();
	}
	//---------------------------------------------------

	// ------------------------------------------------
	// Inputs
	// ------------------------------------------------
	// Get IO events (keys pressed/released, mouse moved etc.)
	glfwPollEvents();
	display->processInputs(deltaTime);
	// ------------------------------------------------

	// Get system time and date
	//time_t systemTime;
	//time(&systemTime);
	//tm system;
	//localtime_s(&system, &systemTime);
	//cout << (system.tm_year + 1900) << '-' << (system.tm_mon + 1) << '-' << system.tm_mday << '-' << (system.tm_hour) << ':' << (system.tm_min) << ':' << (system.tm_sec) << "\n";
	
	// ---------------------
	// Rendering
	// ---------------------
	display->draw();
	// ---------------------
}
// Constructor
void Game::start()
{
	init();
	// timing
	float deltaTime = 0.0f;// Time between current frame and last frame
	float lastFrameTime = 0.0f;// Time of last frame
	double previousTime = glfwGetTime();
	double currentTime;
	int frameCount = 0;
	// Game Loop
	while(!glfwWindowShouldClose(display->getWindow()))
	{
		// Measure speeds
		currentTime = glfwGetTime();
		deltaTime = 0.01f;//currentTime - lastFrameTime;
		lastFrameTime = currentTime;
		frameCount++;
		// If last prinf() was more than 1 sec ago
		if ((currentTime - previousTime) >= 1.0)
		{
			// printf and reset timer
			printf("%f ms/frame\n", (1000.0 / double(frameCount)));
			printf("FPS: %d\n", frameCount);
			printf("Delta Time: %d\n", deltaTime);
			//TODO: add fps to hud (render text)
			frameCount = 0;
			previousTime += 1.0;
		}
		update(deltaTime);
		glfwSwapBuffers(display->getWindow());
	}
	// Shutdown the game
	shutdown();
}
// Used to crash the game
void Game::crash()
{
	// Used to keep the window open
	cout << "Press any key to continue . . . ";
	cin.get();
	// Tells the program to close as a failure
	exit(EXIT_FAILURE);
}
// Used to shutdown the game
void Game::shutdown()
{
	// Delete pointers
	delete settings;
	settings = NULL;
	delete display;
	display = NULL;
	delete callbacks;
	callbacks = NULL;
	// Shutdown GLFW
	glfwTerminate();
	// Used to keep the window open
	cout << "Press any key to continue . . . ";
	cin.get();
	// Tells the program to close
	exit(EXIT_SUCCESS);
}