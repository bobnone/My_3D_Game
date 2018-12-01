#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include "../Basic OpenGL Stuff/model.h"
#include "../Basic OpenGL Stuff/vertice.h"

enum MeshBufferPositions
{
	MBP_POSITION,
	MBP_TEXCOORDS,
	MBP_COLOR,
	MBP_NORMAL,
	MBP_INDEX
};
enum MeshTypes
{
	MESH_TRIANGLE,
	MESH_RECTANGLE,
	MESH_HEXAGON
};

class Mesh
{
public:
	// Used to get pre-defined Meshs
	Mesh(int type);
	// Used to create a custom mesh
	Mesh(Vertice* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
	void draw();
	~Mesh();
protected:
private:
	static const unsigned int NUM_BUFFERS = 5;
	GLuint VAO;
	GLuint buffers[NUM_BUFFERS];
	unsigned int numIndices;

	void init(Vertice* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
	void genTriangleMesh();
	void genRectangleMesh();
	void genHexagonMesh();
};
#endif