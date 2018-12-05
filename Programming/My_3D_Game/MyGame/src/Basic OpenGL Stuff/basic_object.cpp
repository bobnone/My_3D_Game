#include "basic_object.h"

mat4 BasicObject::getModel() const
{
	mat4 positionMatrix = translate(position);
	mat4 scaleMatrix = glm::scale(scale);
	mat4 rotationX = rotate(rotation.x, vec3(1.0, 0.0, 0.0));
	mat4 rotationY = rotate(rotation.y, vec3(0.0, 1.0, 0.0));
	mat4 rotationZ = rotate(rotation.z, vec3(0.0, 0.0, 1.0));
	mat4 rotationMatrix = rotationX * rotationY * rotationZ;
	return positionMatrix * rotationMatrix * scaleMatrix;
}
void BasicObject::setPosition(const vec3 position)
{
	this->position = position;
}
void BasicObject::setPosition(const float x, const float y, const float z)
{
	this->position = vec3(x, y, z);
}
void BasicObject::setPositionX(const float x)
{
	position.x = x;
}
void BasicObject::setPositionY(const float y)
{
	position.y = y;
}
void BasicObject::setPositionZ(const float z)
{
	position.z = z;
}
vec3 BasicObject::getPosition()
{
	return position;
}
float BasicObject::getPositionX()
{
	return position.x;
}
float BasicObject::getPositionY()
{
	return position.y;
}
float BasicObject::getPositionZ()
{
	return position.z;
}
void BasicObject::setRotation(const vec3 rotation)
{
	this->rotation = rotation;
}
void BasicObject::setRotation(const float x, const float y, const float z)
{
	this->rotation = vec3(x, y, z);
}
void BasicObject::setRotationX(const float x)
{
	rotation.x = x;
}
void BasicObject::setRotationY(const float y)
{
	rotation.y = y;
}
void BasicObject::setRotationZ(const float z)
{
	rotation.z = z;
}
void BasicObject::setRotationDegreesX(const int x)
{
	rotation.x = radians(x);
}
void BasicObject::setRotationDegreesY(const int y)
{
	rotation.y = radians(y);
}
void BasicObject::setRotationDegreesZ(const int z)
{
	rotation.z = radians(z);
}
/*void BasicObject::setRotationDegreesX(int x)
{
	int degrees = GameMath::getDegrees(x);
	setRotationX(x);
	if (degrees<90)
	{
		// Do nothing
	}
	if (degrees<180)
	{
		setPositionZ(position.z + 1.0f);
	}
	else if (degrees<270)
	{
		setPositionZ(position.z + 1.0f);
		setPositionY(position.y + 1.0f);
	}
	else if (degrees<360)
	{
		setPositionY(position.y + 1.0f);
	}
}
void BasicObject::setRotationDegreesY(int y)
{
	int degrees = GameMath::getDegrees(y);
	setRotationY(y);
	if (degrees<90)
	{
		// Do nothing
	}
	if (degrees<180)
	{
		setPositionX(position.x + 1.0f);
	}
	else if (degrees<270)
	{
		setPositionX(position.x + 1.0f);
		setPositionZ(position.z + 1.0f);
	}
	else if (degrees<360)
	{
		setPositionZ(position.z + 1.0f);
	}
}
void BasicObject::setRotationDegreesZ(int z)
{
	int degrees = GameMath::getDegrees(z);
	setRotationZ(z);
	if (degrees<90)
	{
		// Do nothing
	}
	if (degrees<180)
	{
		setPositionX(position.x + 1.0f);
	}
	else if (degrees<270)
	{
		setPositionX(position.x+1.0f);
		setPositionY(position.y+1.0f);
	}
	else if (degrees<360)
	{
		setPositionY(position.y+1.0f);
	}
}*/
vec3 BasicObject::getRotation()
{
	return rotation;
}
float BasicObject::getRotationX()
{
	return rotation.x;
}
float BasicObject::getRotationY()
{
	return rotation.y;
}
float BasicObject::getRotationZ()
{
	return rotation.z;
}
void BasicObject::setScale(const vec3 scale)
{
	this->scale = scale;
}
void BasicObject::setScale(const float x, const float y, const float z)
{
	this->scale = vec3(x, y, z);
}
void BasicObject::setScaleX(const float x)
{
	scale.x = x;
}
void BasicObject::setScaleY(const float y)
{
	scale.y = y;
}
void BasicObject::setScaleZ(const float z)
{
	scale.z = z;
}
vec3 BasicObject::getScale()
{
	return scale;
}
float BasicObject::getScaleX()
{
	return scale.x;
}
float BasicObject::getScaleY()
{
	return scale.y;
}
float BasicObject::getScaleZ()
{
	return scale.z;
}
Mesh* BasicObject::getMesh()
{
	return mesh;
}
GLuint BasicObject::getTexture()
{
	return textureID;
}
float BasicObject::radians(const int x)
{
	return glm::radians((float)x);
}