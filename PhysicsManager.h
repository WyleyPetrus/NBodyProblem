#pragma once
#include "Particle.h"
#include "ForceGenerator.h"
#include <iostream>
#include <vector>
#include <SFML/System/Time.hpp>

class PhysicsManager
{
public:
	double simulationSpeed;
	std::vector<Particle*> particleList;
	std::vector<ForceGenerator*> fgList;
public:
	PhysicsManager();
	PhysicsManager(double simulationSpeed);
	int numberOfParticles();
	int numberOfForces();
	void addParticle(Particle* p);
	void addForceGenerator(ForceGenerator* fg);

	void updatePhysics(double deltaTime);
	double calculatePotential(Particle *p1);
	double calculateEnergy(Particle *p1);
	double totalEnergy();
	~PhysicsManager();
};
