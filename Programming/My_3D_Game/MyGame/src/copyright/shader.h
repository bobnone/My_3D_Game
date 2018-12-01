#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <fstream>
#include "../Basic OpenGL Stuff/basic_object.h"
#include "../copyright/camera.h"
#include <iostream>
#include <string>
using namespace std;

class Shader
{
public:
	Shader(const string& fileName);
	void setCurrent();
	void update(const BasicObject& basicObject, const Camera& camera);
	~Shader();
	GLuint getProgram();
protected:
private:
	static const unsigned int NUM_SHADERS = 2;
	static const unsigned int NUM_UNIFORMS = 4;

	string LoadShader(const string& fileName);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	GLuint CreateShader(const string& text, unsigned int type);
	GLuint program;
	GLuint shaders[NUM_SHADERS];
	GLuint uniforms[NUM_UNIFORMS];
};
#endif