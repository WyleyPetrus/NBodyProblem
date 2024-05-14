// NBodyProblem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Particle.h"
#include "Vector2D.h"
#include "PhysicsManager.h"
#include "Gravity.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

int main()
{
    std::ofstream p1file;
    std::ofstream p2file;
    p1file.open("totalEnergyP1.txt");
    p2file.open("totalEnergyP2.txt");

    sf::RenderWindow window(sf::VideoMode(630, 630), "Main Window!");

    Particle p1(10000, 10, Vector2D(900,400), Vector2D(0, -15), Vector2D(0, 0));
    Particle p2(10000, 10, Vector2D(700, 400), Vector2D(0, 15), Vector2D(0, 0));

    Gravity g;

    PhysicsManager pm;
    pm.addForceGenerator(&g);
    pm.addParticle(&p1);
    pm.addParticle(&p2);

    double elapsedTime = 0;
    sf::Clock timer;
    timer.restart();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (timer.getElapsedTime().asMilliseconds() > 1000) {
            timer.restart();
            p1file << pm.calculateEnergy(&p1) << ","  << elapsedTime << std::endl;
            p2file << pm.calculateEnergy(&p2) << "," << elapsedTime << std::endl;
            elapsedTime += 1;
        }

        double deltaTime = .001;
        pm.updatePhysics(deltaTime);

        window.clear();
        window.draw(p1.getSprite());
        window.draw(p2.getSprite());
        window.display();
    }
    p1file.close();
    p2file.close();
    return 0;
}

