#include "Particle.h"

Particle::Particle(double mass, double radius, Vector2D position, Vector2D velocity, Vector2D acceleration) {
	this->mass = mass;
	this->radius = radius;
	this->position = Vector2D(position.x, position.y);
	this->velocity = Vector2D(velocity.x, velocity.y);
	this->acceleration = Vector2D(acceleration.x, acceleration.y);
	this->sprite = sf::CircleShape(radius);
	this->sprite.setFillColor(sf::Color::Red);
	this->sprite.setPosition(sf::Vector2f(position.x, position.y));
}

double Particle::getMass() {
	return mass;
}

double Particle::getRadius() {
	return radius;
}

Vector2D Particle::getVelocity() {
	return velocity;
}

Vector2D Particle::getPosition() {
	return position;
}

sf::CircleShape Particle::getSprite() {
	return sprite;
}

void Particle::setAcceleration(Vector2D a) {
	this->acceleration = a;
}

void Particle::setVelocity(Vector2D v) {
	this->velocity = v;
}

void Particle::setPosition(Vector2D p) {
	this->position = p;
	this->sprite.setPosition(sf::Vector2f(p.x, p.y));
}

void Particle::move(double deltaTime) {
	Vector2D dp = this->velocity * deltaTime;
	setPosition(dp + this->position);
}

void Particle::updateVelocity(double deltaTime) {
	Vector2D dv = this->acceleration * deltaTime;
	setVelocity(this->velocity + dv);
}

double Particle::calculateKineticEnergy() {
	double kinetic = .5 * mass * pow(velocity.magnitude(),2);
	return kinetic;
}