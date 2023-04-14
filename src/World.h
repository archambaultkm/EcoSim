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
    int preyCount;
    int predatorCount;

public:
    //-------------------Constructors-------------------//
    World();
    virtual ~World();
    //-------------------Getters/Setters-------------------//
    int getPreyCount() const;
    void incPreyCount();
    int getPredatorCount() const;
    void incPredatorCount();
    bool hasDiversity() const;
    bool containsPrey(Point point);
    //-------------------Class Methods-------------------//
    void populateWorld();
    bool pointEmpty(Point point);
    void removeOrganismAt(Point point, bool kill);
    void placeOrganismAt(Point point, Organism* movedOrganism);
    void takeTurns();
    void resetFlags();

    friend ostream& operator<<(ostream &output, const World& world);
};

#endif //ECOSIM_WORLD_H