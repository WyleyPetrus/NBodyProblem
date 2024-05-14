#include "PhysicsManager.h"
#include <stdio.h>

PhysicsManager::PhysicsManager() {
	this->simulationSpeed = 0;
}

PhysicsManager::PhysicsManager(double simulationSpeed) {
	this->simulationSpeed = simulationSpeed;
}

int PhysicsManager::numberOfParticles() {
	return this->particleList.size();
}

int PhysicsManager::numberOfForces() {
	return this->fgList.size();
}

void PhysicsManager::addParticle(Particle *p) {
	this->particleList.insert(particleList.begin(), p);
}


void PhysicsManager::addForceGenerator(ForceGenerator* fg) {
	this->fgList.insert(fgList.begin(),fg);
}


void PhysicsManager::updatePhysics(double deltaTime) {
	for (int p1 = 0; p1 < numberOfParticles(); p1++) {
		Vector2D totalForce = Vector2D();
		for (int p2 = 0; p2 < numberOfParticles(); p2++) {
			if (p1 != p2) {
				for (int f = 0; f < numberOfForces(); f++) {
					Particle particle1 = *(particleList.at(p1));
					Particle particle2 = *(particleList.at(p2));
					totalForce = totalForce + (*(fgList.at(f))).forceFunction(particle1, particle2);
				}
			}
			(*particleList.at(p1)).setAcceleration(totalForce / (*particleList.at(p1)).getMass());
		}
	}
	for (int p = 0; p < numberOfParticles(); p++) {
		(*particleList.at(p)).updateVelocity(deltaTime);
		(*particleList.at(p)).move(deltaTime);
	}
}

double PhysicsManager::calculatePotential(Particle* p1) {
	double potential = 0;
	for (int i = 0; i < numberOfParticles(); i++) {
		double r = ((*particleList.at(i)).getPosition() - (*p1).getPosition()).magnitude();
		if (r != 0) {
			potential += -((*p1).getMass() * 9 * (*particleList.at(i)).getMass() / r);
		}
	}
	return potential;
}

double PhysicsManager::calculateEnergy(Particle* p1) {
	printf("Kinetic %lf\n", (*p1).calculateKineticEnergy());
	printf("potential %lf\n", calculatePotential(p1));
	return (*p1).calculateKineticEnergy() + calculatePotential(p1);
}

double PhysicsManager::totalEnergy() {
	double totalEnergy = 0;
	for (int i = 0; i < numberOfParticles(); i++) {
		totalEnergy += calculateEnergy(particleList.at(i));
	}
	return totalEnergy;
}

PhysicsManager::~PhysicsManager() {

}