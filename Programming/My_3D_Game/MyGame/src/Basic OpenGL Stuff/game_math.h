#ifndef GAMEMATH_H
#define GAMEMATH_H

class GameMath
{
public:
	const double PI = 3.14159;
	const double TWOPI = 6.28319;

	// Used to convert from radians to degrees
	static const double getRadians(int degrees);
	// Used to convert radians from (+ or - infinity) => to (+ 0-2PI)
	static const double getRadians(double radians);
	// Used to convert from radians to degrees (WARNING: numbers can be between + or - infinity)
	static const double getAllRadians(int degrees);
	// Used to convert from degrees to radians
	static const int getDegrees(double radians);
	// Used to convert degrees from (+ or - infinity) => to (+ 0-359)
	static const int getDegrees(int degrees);
	// Used to convert from degrees to radians (WARNING: numbers can be between + or - infinity)
	static const int getAllDegrees(double radians);
protected:
private:
};
#endif