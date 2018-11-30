/*#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <map>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <ft2build.h>
#include FT_FREETYPE_H
using namespace std;
using namespace glm;
#include "../copyright/shader.h"

// Holds all state information relevant to a character as loaded using FreeType
struct ScreenCharacter
{
	GLuint TextureID;   // ID handle of the glyph texture
	ivec2 Size;    // Size of glyph
	ivec2 Bearing;  // Offset from baseline to left/top of glyph
	GLuint Advance;    // Horizontal offset to advance to next glyph
};

class Text
{
public:
	Text();
	//~Text();
	void RenderText(Shader &shader, string text, GLfloat x, GLfloat y, GLfloat scale, vec3 color);
protected:
private:
	//Shader* shader;
	const GLuint WIDTH = 800, HEIGHT = 600;
	map<GLchar, ScreenCharacter> Characters;
	GLuint VAO, VBO;
};
#endif*/