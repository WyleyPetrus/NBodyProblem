#pragma once
#include <math.h>

class Vector2D
{
public:
	double x;
	double y;
public:
	Vector2D();
	Vector2D(double x, double y);
	Vector2D operator+(Vector2D const& obj);
	Vector2D operator-(Vector2D const& obj);
	Vector2D operator*(Vector2D const& obj);
	Vector2D operator*(double const& obj);
	Vector2D operator/(double const& obj);
	Vector2D normalize();
	double dot(Vector2D obj);
	double magnitude();
};

