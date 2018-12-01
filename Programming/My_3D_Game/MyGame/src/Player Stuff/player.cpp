#include "player.h"

Player::Player(Images* images, Mesh* mesh, const string userName, const char* fileName, vec3 position, vec3 rotation, vec3 scale, float cameraDistance, float movementSpeed)
{
	this->images = images;
	this->mesh = mesh;
	this->textureID = images->genTexture(fileName);
	this->userName = userName;
	this->position = position;
	this->rotation = rotation;
	this->scale = scale;
	this->movementSpeed = movementSpeed;
	solid = true;
	camera = new Camera(vec3(position.x, position.y, position.z-cameraDistance));
	hud = new Hud(images, mesh, "./Resources/Textures/Character.png", vec3(2.0f, 2.0f, 0.0f), vec3(5.0f, 2.0f, 1.0f));
}
Player::~Player()
{
	delete camera;
	camera = NULL;
	delete hud;
	hud = NULL;
}
// Checks if the player is solid
bool Player::isGhost()
{
	return !solid;
}
void Player::draw(Shader& shader)
{
	shader.update(*this, *camera);
	images->setTexture(textureID);
	mesh->draw();
	hud->draw(shader, *camera);
}
string Player::getUserName()
{
	return userName;
}
GLuint Player::getTexture()
{
	return textureID;
}
Camera* Player::getCamera()
{
	return camera;
}
void Player::resize(const int width, const int height)
{
	camera->resize(width, height);
	hud->resize(width, height);
}
void Player::moveRight(float deltaTime)
{
	float amount = movementSpeed * deltaTime;
	setPositionX(position.x+amount);
	camera->moveRight(amount);
	hud->moveRight(amount);
}
void Player::moveUp(float deltaTime)
{
	float amount = movementSpeed * deltaTime;
	setPositionY(position.y + amount);
	camera->moveUp(amount);
	hud->moveUp(amount);
}
void Player::moveForward(float deltaTime)
{
	float amount = movementSpeed * deltaTime;
	setPositionZ(position.z + amount);
	camera->moveForward(amount);
	hud->moveForward(amount);
}
void Player::Roll(float angle)
{
	camera->Roll(angle);
}
void Player::Pitch(float angle)
{
	camera->Pitch(angle);
}
void Player::Yaw(float angle)
{
	camera->Yaw(angle);
}
void Player::setSolid(bool solid)
{
	this->solid = solid;
}