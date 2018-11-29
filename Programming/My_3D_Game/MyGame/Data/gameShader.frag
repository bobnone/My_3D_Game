#version 120
// Variables accessable to all shaders
varying vec2 texCoordsShader;
varying vec3 normalShader;

// Variables from code (Uniforms)
uniform sampler2D sampler;
uniform vec3 lightDirection;

void main()
{
    gl_FragColor = texture2D(sampler, texCoordsShader) * clamp(dot(-lightDirection, normalShader), 0.0, 1.0);
}
