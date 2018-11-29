#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include "model.h"
#include "vertice.h"

enum MeshBufferPositions
{
	MBP_POSITION,
	MBP_TEXCOORDS,
	MBP_NORMAL,
	MBP_BOOLEAN,
	MBP_INDEX
};
enum MeshTypes
{
	MESH_TRIANGLE,
	MESH_RECTANGLE,
	MESH_PENTAGON,
	MESH_HEXAGON,
	MESH_STAR
};

class Mesh
{
public:
	// Used to get pre-defined Meshs
	Mesh(int type);
	// Used to create a custom mesh
	Mesh(Vertice* vertices, unsigned int* indices);
	// Used to create a custom mesh and manually specify the size
	Mesh(Vertice* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
	void draw();
	virtual ~Mesh();
protected:
private:
	static const unsigned int NUM_BUFFERS = 5;

	GLuint VAO;
	GLuint buffers[NUM_BUFFERS];
	unsigned int numIndices;
	/*
		If boolean is true the shader will load a static mesh.
		A static mesh is not effected by the cammera (EX: Text).
		boolean is treated as a bool (0.0 = false/ 1.0 = true); This is a work around for a bool in a Shader file.
	*/
	void init(Vertice* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices, float boolean = 0.0);

	void genTriangleMesh();
	void genRectangleMesh();
};
#endif