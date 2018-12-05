#ifndef PLAYER_H
#define PLAYER_H

#include "../Basic OpenGL Stuff/basic_object.h"
#include "../copyright/shader.h"
#include "hud.h"

class Player: public BasicObject
{
public:
	Player(Images* images, string userName, const char* fileName, vec3 position = vec3(0.0f, 0.0f, 0.0f), vec3 rotation = vec3(0.0f, 0.0f, 0.0f), vec3 scale = vec3(1.0f, 1.0f, 1.0f), float cameraDistance = 6.0f, float movementSpeed = 2.5f);
	~Player();
	// Checks if the player is solid
	bool isGhost();
	void draw(Shader& shader);
	string getUserName();
	GLuint getTexture();
	Camera* getCamera();
	void resize(const int width, const int height);
	// Movement:
	void moveRight(const float deltaTime);
	void moveUp(const float deltaTime);
	void moveForward(const float deltaTime);
	// Forced Rotation: (normaly handled by the camera)
	void Roll(const float angle);
	void Pitch(const float angle);
	void Yaw(const float angle);
protected:
private:
	bool solid;
	string userName; // Name of the player (must be unique)
	Camera* camera;
	GLuint textureID;
	Hud* hud;
	Images* images;
	float movementSpeed;
	void setSolid(const bool solid);
};
#endif