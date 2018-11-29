#include "images.h"

// Takes a screenshot of the viewport
void Images::screenshot()
{
	ILboolean error;
	ILuint imageID;
	const char* fileName = "";

	//TODO: use time as file name
	//time_t t = time(0);   // get time now
	//tm* now = localtime(&t);
	//cout << (now->tm_year + 1900) << '-' << (now->tm_mon + 1) << '-' << now->tm_mday << "\n";

	// Used to generate a new image with a unique imageID
	ilGenImages(1, &imageID);
	setImage(imageID);
	// Takes a screenshot (in - game) of the viewport and overrides the currently loaded image
	error = !ilutGLScreen();
	if (error)
	{
		fprintf(stderr, "ERROR: Failed to save screenshot \"%s\"\n", fileName);
		//Game::crash();
	}
	// Saves te image to te disk
	ilSaveImage(fileName);
	// Deletes the image
	ilDeleteImages(1, &imageID);
}
// Takes a screenshot of the viewport (WARNING: overrides the image)
void Images::screenshot(const ILuint imageID)
{
	ILboolean error;
	const char* fileName = "";

	//TODO: use time as file name

	setImage(imageID);
	// Takes a screenshot (in - game) of the viewport and overrides the currently loaded image
	error = !ilutGLScreen();
	if (error)
	{
		fprintf(stderr, "ERROR: Failed to save screenshot to image \"%s\"\n", imageID);
		//Game::crash();
	}
	// Saves the image to the disk
	saveImage(fileName);
}
// Used to set the current image
void Images::setImage(const ILuint imageID)
{
	ilBindImage(imageID);
}
// Used to get the current image's width
ILuint Images::imageWidth()
{
	return ilGetInteger(IL_IMAGE_WIDTH);
}
// Used to get the current image's height
ILuint Images::imageHeight()
{
	return ilGetInteger(IL_IMAGE_HEIGHT);
}
// Used to get the current image's data
ILubyte* Images::imageData()
{
	return ilGetData();
}
// Used to load an image
ILuint Images::loadImage(const char* fileName)
{
	ILboolean error;
	// Used to load an image
	ILuint imageID;
	// Used to generate a new image with a unique imageID
	ilGenImages(1, &imageID);
	// Sets image of imageID as the current image
	ilBindImage(imageID);
	// Reads the image file
	error = !ilLoadImage(fileName);
	if(error)
	{
		fprintf(stderr, "ERROR: Failed to load image \"%s\"\n", fileName);
		//Game::crash();
	}
	return imageID;
}
// Used to load an image as a specific file type
ILuint Images::loadImage(ILenum fileType, const char* fileName)
{
	ILboolean error;
	// Used to load an image
	ILuint imageID;
	// Used to generate a new image with a unique imageID
	ilGenImages(1, &imageID);
	// Sets image of imageID as the current image
	ilBindImage(imageID);
	// Reads the image file (will try to convert the loaded image to the requested file type)
	error = !ilLoad(fileType, fileName);
	if(error)
	{
		fprintf(stderr, "ERROR: Failed to load image \"%s\" as type \"%s\"\n", fileName, fileType);
		//Game::crash();
	}
	return imageID;
}
// Used to save an image
void Images::saveImage(const char* fileName)
{
	ILboolean error;
	error = !ilSaveImage(fileName);
	if(error)
	{
		fprintf(stderr, "ERROR: Failed to save image \"%s\"\n", fileName);
		//Game::crash();
	}
}
// Used to save an image as a specific file type
void Images::saveImage(ILenum fileType, const char* fileName)
{
	ILboolean error;
	error = !ilSave(fileType, fileName);
	if (error)
	{
		fprintf(stderr, "ERROR: Failed to save image \"%s\" as type \"%s\"\n", fileName, fileType);
		//Game::crash();
	}
}
// Used to delete an image
void Images::deleteImage(const ILuint* imageID)
{
	ilDeleteImages(1, imageID);
}
// Used to generate a texture
GLuint Images::genTexture(const char* fileName)
{
	ILboolean error;
	// Used to load an image
	ILuint imageID = loadImage(fileName);
	GLuint textureID;
	glGenTextures(1, &textureID);
	setTexture(textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// This function calls glTexImage2D after performing any required conversions. The Level parameter allows you to manually set mipmaps.
	error = !ilutGLTexImage(0);
	if (error)
	{
		fprintf(stderr, "ERROR: Failed to load texture \"%s\"\n", fileName);
		//Game::crash();
	}
	// Deletes the image
	deleteImage(&imageID);
	return textureID;
}
// Used to generate a texture
GLuint Images::genTexture(ILenum fileType, const char* fileName)
{
	ILboolean error;
	// Used to load an image
	ILuint imageID = loadImage(fileType, fileName);
	GLuint textureID;
	glGenTextures(1, &textureID);
	setTexture(textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// This function calls glTexImage2D after performing any required conversions. The Level parameter allows you to manually set mipmaps.
	error = !ilutGLTexImage(0);
	if (error)
	{
		fprintf(stderr, "ERROR: Failed to load texture \"%s\" using file type \"%s\"\n", fileName, fileType);
		//Game::crash();
	}
	// Deletes the image
	deleteImage(&imageID);
	return textureID;
}
// Used to generate a texture from an image
GLuint Images::genTexture(ILuint imageID)
{
	ILboolean error;
	GLuint textureID;
	glGenTextures(1, &textureID);
	setTexture(textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// This function calls glTexImage2D after performing any required conversions. The Level parameter allows you to manually set mipmaps.
	error = !ilutGLTexImage(0);
	if (error)
	{
		fprintf(stderr, "ERROR: Failed to load texture from image \"%s\"\n", imageID);
		//Game::crash();
	}
	return textureID;
}
// Used to set the current texture
void Images::setTexture(const GLuint textureID)
{
	glBindTexture(GL_TEXTURE_2D, textureID);
}
// Used to delete the texture
void Images::deleteTexture(const GLuint* textureID)
{
	glDeleteTextures(1, textureID);
}