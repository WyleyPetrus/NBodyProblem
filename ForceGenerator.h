#pragma once
#include "Particle.h"
#include "Vector2D.h"

struct ForceGenerator
{
public:
	virtual Vector2D forceFunction(Particle p1, Particle p2) = 0;
	virtual double getPotential(Particle p1, Particle p2) = 0;
};

