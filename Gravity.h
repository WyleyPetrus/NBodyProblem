#pragma once
#include "ForceGenerator.h"

#define GRAVITATIONAL_CONSTANT 9

class Gravity : public ForceGenerator
{
public:
	Vector2D forceFunction(Particle p1, Particle p2);
	double getPotential(Particle p1, Particle p2);
};

