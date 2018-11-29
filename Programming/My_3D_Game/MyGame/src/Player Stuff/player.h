#ifndef PLAYER_H
#define PLAYER_H

#include "../Basic OpenGL Stuff/basic_object.h"
#include "../copyright/shader.h"
#include "hud.h"

class Player: public BasicObject
{
public:
	Player(Images* images, Mesh* mesh, const string userName, const char* fileName, float aspectRatio, const vec3 position = vec3(0.0f, 0.0f, 0.0f), const float cameraDistance = 6.0f, const vec3 scale = vec3(1.0f, 1.0f, 1.0f), float zNear = 0.1f, float zFar = 100.0f, float fov = 70.0f);
	~Player();
	bool isGhost(); // Checks if the player is solid
	void draw(Shader& shader);
	string getUserName();
	GLuint getTexture();
	Camera* getCamera();
	void updateProjection(const int width, const int height, float aspectRatio, float zNear = 0.1f, float zFar = 100.0f, float fov = 70.0f);
	// Movement:
	void moveRight(float amount);
	void moveUp(float amount);
	void moveForward(float amount);
	// Rotation:
	void Roll(float angle);
	void Pitch(float angle);
	void Yaw(float angle);
protected:
private:
	bool solid;
	string userName; // Name of the player (must be unique)
	Camera* camera;
	GLuint textureID;
	Hud* hud;
	Images* images;
	void setSolid(bool solid);
};
#endif