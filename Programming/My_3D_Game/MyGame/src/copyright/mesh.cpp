#include "mesh.h"

// Used to get pre-defined Meshs
Mesh::Mesh(int type)
{
	switch (type)
	{
	case MESH_RECTANGLE:
		genRectangleMesh();
		break;
	defult: //MESH_TRIANGLE
		genTriangleMesh();
		break;
	}
}
// Used to create a custom mesh
Mesh::Mesh(Vertice* vertices, unsigned int* indices)
{
	init(vertices, (sizeof(vertices) / sizeof(vertices[0])), indices, (sizeof(indices) / sizeof(indices[0])));
}
// Used to create a custom mesh and manually specify the size
Mesh::Mesh(Vertice* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices)
{
	init(vertices, numVertices, indices, numIndices);
}
Mesh::~Mesh()
{
	glDeleteBuffers(NUM_BUFFERS, buffers);
	glDeleteVertexArrays(1, &VAO);
}
void Mesh::draw()
{
	glBindVertexArray(VAO);
	glDrawElementsBaseVertex(GL_TRIANGLES, numIndices, GL_UNSIGNED_INT, 0, 0);
	glBindVertexArray(NULL);
}
void Mesh::init(Vertice* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices, float boolean)
{
	this->numIndices = numIndices;
	Model model;
	for (unsigned int i = 0; i < numVertices; i++)
	{
		model.position.push_back(*vertices[i].getPosition());
		model.texCoords.push_back(*vertices[i].getTexCoords());
		model.normal.push_back(*vertices[i].getNormal());
	}
	for (unsigned int i = 0; i < numIndices; i++)
	{
		model.indices.push_back(indices[i]);
	}
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(NUM_BUFFERS, buffers);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[MBP_POSITION]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(model.position[0]) * model.position.size(), &model.position[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[MBP_TEXCOORDS]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(model.texCoords[0]) * model.texCoords.size(), &model.texCoords[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[MBP_NORMAL]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(model.normal[0]) * model.normal.size(), &model.normal[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, buffers[MBP_BOOLEAN]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GL_FLOAT), &boolean, GL_STATIC_DRAW);
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[MBP_INDEX]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(model.indices[0]) * model.indices.size(), &model.indices[0], GL_STATIC_DRAW);
	glBindVertexArray(NULL);
}
void Mesh::genTriangleMesh()
{
	Vertice vertices[] =
	{
		Vertice(vec3(1.0f, 0.0f, 1.0f), vec2(1, 0)),// Bottom Left
		Vertice(vec3(0.0f, 0.0f, 1.0f), vec2(0, 0)),// Bottom Right
		Vertice(vec3(1.0f, 1.0f, 1.0f), vec2(1, 1)),// Top Left
	};
	unsigned int indices[] = { 2, 0, 1 };
	init(vertices, 3, indices, 3);
}
void Mesh::genRectangleMesh()
{
	Vertice vertices[] =
	{
		Vertice(vec3(1.0f, 0.0f, 1.0f), vec2(1, 0)),// Bottom Left
		Vertice(vec3(0.0f, 0.0f, 1.0f), vec2(0, 0)),// Bottom Right
		Vertice(vec3(1.0f, 1.0f, 1.0f), vec2(1, 1)),// Top Left
		Vertice(vec3(0.0f, 1.0f, 1.0f), vec2(0, 1))// Top Right
	};
	unsigned int indices[] = { 2, 0, 1 , 1, 3, 2 };
	init(vertices, 4, indices, 6);
}