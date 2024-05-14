#pragma once
#include "Vector2D.h"
#include <SFML/Graphics.hpp>

class Particle
{
private:
	double mass;
	double radius;
	Vector2D acceleration;
	Vector2D position;
	Vector2D velocity;
	sf::CircleShape sprite;

public:
	Particle(double mass, double radius, Vector2D position, Vector2D velocity, Vector2D acceleration);
	double getMass();
	double getRadius();
	Vector2D getVelocity();
	Vector2D getPosition();
	sf::CircleShape getSprite();
	void setAcceleration(Vector2D a);
	void setVelocity(Vector2D v);
	void setPosition(Vector2D p);
	void move(double deltaTime);
	void updateVelocity(double deltaTime);

	double calculateKineticEnergy();
};

