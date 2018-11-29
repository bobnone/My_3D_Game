#include "player.h"

Player::Player(Images* images, Mesh* mesh, const string userName, const char* fileName, const float aspectRatio, const vec3 position, const float cameraDistance, const vec3 scale, const float zNear, const float zFar, const float fov)
{
	this->images = images;
	this->mesh = mesh;
	this->textureID = images->genTexture(fileName);
	this->userName = userName;
	this->position = position;
	this->scale = scale;
	solid = true;
	camera = new Camera(vec3(position.x, position.y, position.z-cameraDistance), fov, aspectRatio, zNear, zFar);
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
void Player::updateProjection(const int width, const int height, float aspectRatio, float zNear, float zFar, float fov)
{
	camera->updateProjection(fov, aspectRatio, zNear, zFar);
	hud->resize(width, height);
}
void Player::moveRight(float amount)
{
	setPositionX(position.x+amount);
	camera->moveRight(amount);
	hud->moveRight(amount);
}
void Player::moveUp(float amount)
{
	setPositionY(position.y + amount);
	camera->moveUp(amount);
	hud->moveUp(amount);
}
void Player::moveForward(float amount)
{
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