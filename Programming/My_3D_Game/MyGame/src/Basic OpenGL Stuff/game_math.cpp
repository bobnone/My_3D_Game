#include "game_math.h"

// Used to convert from radians to degrees
const double GameMath::getRadians(int degrees)
{
	return getRadians(getAllRadians(degrees));
}
// Used to convert radians from (+ or - infinity) => to (+ 0-2PI)
const double GameMath::getRadians(double radians)
{
	while(radians < 0)
	{
		radians = 6.28319 + radians;
	}
	while(radians >= 6.28319)
	{
		radians /= 6.28319;
	}
	return radians;
}
// Used to convert from radians to degrees (WARNING: numbers can be between + or - infinity)
const double GameMath::getAllRadians(int degrees)
{
	return ((double)degrees)*(3.14159/180.0);
}
// Used to convert from degrees to radians
const int GameMath::getDegrees(double radians)
{
	return getDegrees(getAllDegrees(radians));
}
// Used to convert degrees from (+ or - infinity) => to (+ 0-359)
const int GameMath::getDegrees(int degrees)
{
	while(degrees < 0)
	{
		degrees = 360 + degrees;
	}
	while(degrees >= 360)
	{
		degrees /= 360;
	}
	return degrees;
}
// Used to convert from degrees to radians (WARNING: numbers can be between + or - infinity)
const int GameMath::getAllDegrees(double radians)
{
	return radians*(180.0/3.14159);
}