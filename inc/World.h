//
// Created by Kaitlyn Archambault on 2023-03-29.
//

#ifndef ECOSIM_WORLD_H
#define ECOSIM_WORLD_H

#include "Point.h"
#include "GameSpecs.h"

#include <iostream>
#include <random>
using namespace std;

class Organism;

class World {

private:
    Organism* world[WORLD_SIZE][WORLD_SIZE];
    static Point randomPoint();

public:
    //-------------------Constructors-------------------//
    World();

    //-------------------Getters/Setters-------------------//

    //-------------------Member Functions-------------------//
    void populateWorld();
    bool pointEmpty(Point point);
    void removeOrganismAt(Point point);
    void placeOrganismAt(Point point, Organism* movedOrganism);
    void takeTurns();
    void resetFlags();

    friend ostream& operator<<(ostream &output, const World& world);
};

#endif //ECOSIM_WORLD_H