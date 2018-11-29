#version 330 core

// Per-Vertex attributes
in vec3 position;
in vec2 texCoords;
in vec3 normal;
in float boolean;

// Stuff to send to the Fragment shader
out vec2 fsTexCoords;
out vec3 fsNormal;
out float fsBoolean;

// Variables from code (Uniforms)
uniform mat4 MVP;
uniform mat4 Normal;

void main()
{
	if(fsBoolean >= 0.5)
	{
		gl_Position = MVP * vec4(position, 1.0);
	}
	else
	{
		gl_Position = MVP * vec4(position, 1.0);
		fsNormal = (Normal * vec4(normal, 0.0)).xyz;
	}
	fsTexCoords = texCoords;
	fsBoolean = boolean;
}
