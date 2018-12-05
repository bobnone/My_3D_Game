#ifndef IMAGES_H
#define IMAGES_H

#include <GL/glew.h>
#include <ctime>
#include <IL/ilut.h>
using namespace std;

struct Images
{
	// Takes a screenshot of the viewport
	void screenshot();
	// Takes a screenshot of the viewport (WARNING: overrides the image)
	void screenshot(const ILuint imageID);
	// Used to set the current image
	void setImage(const ILuint imageID);
	// Used to get the current image's width
	ILuint imageWidth();
	// Used to get the current image's height
	ILuint imageHeight();
	// Used to get the current image's data
	ILubyte* imageData();
	// Used to load an image
	ILuint loadImage(const char* fileName);
	// Used to load an image as a specific file type
	ILuint loadImage(const char* fileName, ILenum fileType);
	// Used to save an image
	void saveImage(const char* fileName);
	// Used to save an image as a specific file type
	void saveImage(const char* fileName, ILenum fileType);
	// Used to delete an image
	void deleteImage(const ILuint* imageID);
	// Used to generate a texture
	GLuint genTexture(const char* fileName);
	// Used to generate a texture
	GLuint genTexture(const char* fileName, ILenum fileType);
	// Used to generate a texture from an image
	GLuint genTexture(ILuint imageID);
	// Builds Mipmaps from the current texture
	void genMipmaps();
	/*Builds Mipmaps from the specified texture
	WARNING: binds the specified texture*/
	void genMipmaps(const GLuint textureID);
	// Used to set the current texture
	void setTexture(const GLuint textureID);
	// Used to delete the texture
	void deleteTexture(const GLuint* textureID);
};
#endif