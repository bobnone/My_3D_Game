#version 330 core

// Per-Vertex attributes
in vec2 fsTexCoords;
in vec3 fsNormal;
in float fsBoolean;

// Output to code
out vec4 color;

// Variables from code (Uniforms)
uniform sampler2D sampler;
uniform vec3 lightDirection;
uniform vec3 textColor;

void main()
{
    if(fsBoolean >= 0.5)
	{
		color = vec4(textColor, 1.0) * vec4(1.0, 1.0, 1.0, texture(sampler, fsTexCoords).r);
		//color = textColor;
	}
	else
	{
		color = texture(sampler, fsTexCoords) * clamp(dot(-lightDirection, fsNormal), 0.0, 1.0);
	}
}
