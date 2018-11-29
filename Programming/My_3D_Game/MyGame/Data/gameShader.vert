#version 120
// Pre-defined attributes
attribute vec3 position;
attribute vec2 texCoords;
attribute vec3 normal;

// Variables accessable to all shaders
varying vec2 texCoordsShader;
varying vec3 normalShader;

// Variables from code (Uniforms)
uniform mat4 MVP;
uniform mat4 Normal;

void main()
{
	gl_Position = MVP * vec4(position, 1.0);
	texCoordsShader = texCoords;
	normalShader = (Normal * vec4(normal, 0.0)).xyz;
}
