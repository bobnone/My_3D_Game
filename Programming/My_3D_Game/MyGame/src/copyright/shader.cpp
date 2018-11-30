#include "shader.h"

Shader::Shader(const string& fileName)
{
	program = glCreateProgram();
	/*
        ".vert" - a vertex shader
        !".tesc" - a tessellation control shader
        !".tese" - a tessellation evaluation shader
        !".geom" - a geometry shader
        ".frag" - a fragment shader
        !".comp" - a compute shader
	*/
	shaders[0] = CreateShader(LoadShader(fileName + ".vert"), GL_VERTEX_SHADER);
	shaders[1] = CreateShader(LoadShader(fileName + ".frag"), GL_FRAGMENT_SHADER);
	for (unsigned int i = 0; i < NUM_SHADERS; i++)
	{
		glAttachShader(program, shaders[i]);
	}
	glBindAttribLocation(program, 0, "position");
	glBindAttribLocation(program, 1, "texCoords");
	glBindAttribLocation(program, 2, "color");
	glBindAttribLocation(program, 3, "normal");
	glLinkProgram(program);
	CheckShaderError(program, GL_LINK_STATUS, true, "Error linking shader program");
	glValidateProgram(program);
	CheckShaderError(program, GL_LINK_STATUS, true, "Invalid shader program");
	uniforms[0] = glGetUniformLocation(program, "MVP");
	uniforms[1] = glGetUniformLocation(program, "Normal");
	uniforms[2] = glGetUniformLocation(program, "lightDirection");
	uniforms[3] = glGetUniformLocation(program, "textColor");
}
Shader::~Shader()
{
	for(unsigned int i = 0; i < NUM_SHADERS; i++)
    {
        glDetachShader(program, shaders[i]);
        glDeleteShader(shaders[i]);
    }
	glDeleteProgram(program);
}
GLuint Shader::getProgram()
{
	return program;
}
void Shader::setCurrent()
{
	glUseProgram(program);
}
void Shader::update(const BasicObject& basicObject, const Camera& camera)
{
	mat4 MVP = basicObject.getMVP(camera);
	mat4 Normal = basicObject.getModel();
	glUniformMatrix4fv(uniforms[0], 1, GL_FALSE, &MVP[0][0]);
	glUniformMatrix4fv(uniforms[1], 1, GL_FALSE, &Normal[0][0]);
	glUniform3f(uniforms[2], 0.0f, 0.0f, 1.0f);
}
string Shader::LoadShader(const string& fileName)
{
    ifstream file;
    file.open((fileName).c_str());
    string output;
    string line;
    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
			output.append(line + "\n");
        }
    }
    else
    {
		cerr << "Unable to load shader: " << fileName << endl;
    }
    return output;
}
void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = {0};

	if (isProgram)
	{
		glGetProgramiv(shader, flag, &success);
	}
	else
	{
		glGetShaderiv(shader, flag, &success);
	}
    if(success == GL_FALSE)
    {
		if (isProgram)
		{
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		}
		else
		{
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);
		}
        cerr << errorMessage << ": '" << error << "'" << endl;
    }
}
GLuint Shader::CreateShader(const string& text, unsigned int type)
{
    GLuint shader = glCreateShader(type);

	if (shader == 0)
	{
		cerr << "Error compiling shader type " << type << endl;
	}
    const GLchar* p[1];
    p[0] = text.c_str();
    GLint lengths[1];
    lengths[0] = text.length();
    glShaderSource(shader, 1, p, lengths);
    glCompileShader(shader);
    CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error compiling shader!");
    return shader;
}