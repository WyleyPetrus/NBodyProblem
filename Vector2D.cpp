#include "Vector2D.h"
#include <math.h>

Vector2D::Vector2D() {
	this->x = 0;
	this->y = 0;
}

Vector2D::Vector2D(double x, double y) {
	this->x = x;
	this->y = y;
}

Vector2D Vector2D::operator+(Vector2D const& obj) {
	Vector2D res;
	res.x = x + obj.x;
	res.y = y + obj.y;
	return res;
}

Vector2D Vector2D::operator-(Vector2D const& obj) {
	Vector2D res;
	res.x = x - obj.x;
	res.y = y - obj.y;
	return res;
}

Vector2D Vector2D::operator*(Vector2D const& obj) {
	Vector2D res;
	res.x = x * obj.x;
	res.y = y * obj.y;
	return res;
}

Vector2D Vector2D::operator*(double const& obj) {
	Vector2D res;
	res.x = x * obj;
	res.y = y * obj;
	return res;
}

Vector2D Vector2D::operator/(double const& obj) {
	Vector2D res;
	res.x = x / obj;
	res.y = y / obj;
	return res;
}

Vector2D Vector2D::normalize() {
	Vector2D res;
	double magnitude = this->magnitude();
	return *this / magnitude;
}

double Vector2D::dot(Vector2D obj) {
	return x * obj.x + y * obj.y;
}

double Vector2D::magnitude() {
	return sqrt(x * x + y * y);
}