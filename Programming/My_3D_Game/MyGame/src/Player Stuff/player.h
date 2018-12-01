#ifndef PLAYER_H
#define PLAYER_H

#include "../Basic OpenGL Stuff/basic_object.h"
#include "../copyright/shader.h"
#include "hud.h"

class Player: public BasicObject
{
public:
	Player(Images* images, Mesh* mesh, string userName, const char* fileName, float aspect, vec3 position = vec3(0.0f, 0.0f, 0.0f), vec3 rotation = vec3(0.0f, 0.0f, 0.0f), vec3 scale = vec3(1.0f, 1.0f, 1.0f), float cameraDistance = 6.0f, float movementSpeed = 2.5f);
	~Player();
	bool isGhost(); // Checks if the player is solid
	void draw(Shader& shader);
	string getUserName();
	GLuint getTexture();
	Camera* getCamera();
	void resize(const int width, const int height);
	// Movement:
	void moveRight(float deltaTime);
	void moveUp(float deltaTime);
	void moveForward(float deltaTime);
	// Forced Rotation: (normaly handled by the camera)
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
	float movementSpeed;
};
#endif