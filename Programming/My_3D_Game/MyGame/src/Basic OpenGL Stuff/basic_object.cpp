#include "basic_object.h"

mat4 BasicObject::getModel() const
{
	mat4 positionMat = translate(position);
	mat4 scaleMat = glm::scale(scale);
	mat4 rotationX = rotate(rotation.x, vec3(1.0, 0.0, 0.0));
	mat4 rotationY = rotate(rotation.y, vec3(0.0, 1.0, 0.0));
	mat4 rotationZ = rotate(rotation.z, vec3(0.0, 0.0, 1.0));
	mat4 rotationMat = rotationX * rotationY * rotationZ;
	return positionMat * rotationMat * scaleMat;
}
// Model, View, and Projection (MVP)
mat4 BasicObject::getMVP(const Camera& camera) const
{
	mat4 VP = camera.getViewProjection();
	mat4 M = getModel();
	return VP * M;//camera.getViewProjection() * getModel();
}
bool BasicObject::isSolid()
{
	return solid;
}
void BasicObject::setSolid(bool solid)
{
	this->solid = solid;
}
void BasicObject::setPosition(vec3 position)
{
	this->position = position;
}
void BasicObject::setPosition(float x, float y, float z)
{
	this->position = vec3(x, y, z);
}
void BasicObject::setPositionX(float x)
{
	setPosition(x, position.y, position.z);
}
void BasicObject::setPositionY(float y)
{
	setPosition(position.x, y, position.z);
}
void BasicObject::setPositionZ(float z)
{
	setPosition(position.x, position.y, z);
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
void BasicObject::setRotation(vec3 rotation)
{
	this->rotation = rotation;
}
void BasicObject::setRotation(float x, float y, float z)
{
	this->rotation = vec3(x, y, z);
}
void BasicObject::setRotationX(float x)
{
	setRotation(x, rotation.y, rotation.z);
}
void BasicObject::setRotationY(float y)
{
	setRotation(rotation.x, y, rotation.z);
}
void BasicObject::setRotationZ(float z)
{
	setRotation(rotation.x, rotation.y, z);
}
void BasicObject::setRotationDegreesX(int x)
{
	setRotation(GameMath::getRadians(x), rotation.y, rotation.z);
}
void BasicObject::setRotationDegreesY(int y)
{
	setRotation(rotation.x, GameMath::getRadians(y), rotation.z);
}
void BasicObject::setRotationDegreesZ(int z)
{
	setRotation(rotation.x, rotation.y, GameMath::getRadians(z));
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
void BasicObject::setScale(vec3 scale)
{
	this->scale = scale;
}
void BasicObject::setScale(float x, float y, float z)
{
	this->scale = vec3(x, y, z);
}
void BasicObject::setScaleX(float x)
{
	setScale(x, scale.y, scale.z);
}
void BasicObject::setScaleY(float y)
{
	setScale(scale.x, y, scale.z);
}
void BasicObject::setScaleZ(float z)
{
	setScale(scale.x, scale.y, z);
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