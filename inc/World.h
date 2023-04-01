//
// Created by Kaitlyn Archambault on 2023-03-29.
//

#ifndef ECOSIM_WORLD_H
#define ECOSIM_WORLD_H

#include "Point.h"
#include "Prey.h"
#include "Predator.h"

#include <iostream>
#include <random>
using namespace std;

#define WORLD_SIZE 20
#define STARTING_PREY 30
#define STARTING_PREDATORS 5

class World {

private:
    Organism* world[WORLD_SIZE][WORLD_SIZE];
    Point randomPoint();

public:
    World();
    void populateWorld();
    void takeTurns();
    friend ostream& operator<<(ostream &output, const World& world);
};

typedef World* WorldPtr;

#endif //ECOSIM_WORLD_H