#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <fstream>
#include "../Basic OpenGL Stuff/basic_object.h"
#include "../Basic OpenGL Stuff/camera.h"
#include <iostream>
#include <string>
using namespace std;

class Shader
{
public:
	Shader(const string& fileName);
	~Shader();
	GLuint getProgram();
	void use();
	void update(const BasicObject& basicObject, const Camera& camera);
protected:
private:
	static const unsigned int NUM_SHADERS = 2;
	static const unsigned int NUM_UNIFORMS = 4;
	GLuint program;
	GLuint shaders[NUM_SHADERS];
	GLuint uniforms[NUM_UNIFORMS];
	string LoadShader(const string& fileName);
	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage);
	GLuint CreateShader(const string& text, const unsigned int type);
};
#endif