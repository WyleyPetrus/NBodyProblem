#include "Gravity.h"
#include <math.h>


Vector2D Gravity::forceFunction(Particle p1, Particle p2) {
	double square_distance = powf((p2.getPosition() - p1.getPosition()).magnitude(), 2);
	return (p2.getPosition() - p1.getPosition()).normalize() * (GRAVITATIONAL_CONSTANT * p1.getMass() * p2.getMass()/square_distance);
}

double Gravity::getPotential(Particle p1, Particle p2) {
	return 0;
}