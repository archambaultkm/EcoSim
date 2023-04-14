//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#ifndef ECOSIM_ORGANISM_H
#define ECOSIM_ORGANISM_H

#include "GameSpecs.h"
#include "Point.h"

#include <iostream>
#include <vector>
using namespace std;

//define it here rather than including the world header so that you don't break things
class World;

class Organism {
protected:

    World* thisWorld;
    bool isAlive;
    int turnsSinceReproduced;
    bool moved;
    Point location;
    PointVector possibleMoves;
    char symbol;

public:

    //-------------------Constructors-------------------//
    Organism();
    Organism(Point point, World* worldptr, char symbol);
    virtual ~Organism();

    //-------------------Getters/Setters-------------------//
    virtual void setPossibleMoves() = 0;
    void setMoved(bool moved);
    bool getMoved();
    char getSymbol();

    //-------------------Class Methods-------------------//
    virtual void turn() = 0;
    virtual void move() = 0;
    virtual void reproduce() = 0;

    friend ostream& operator<<(ostream &output, const Organism& organism);
};

#endif //ECOSIM_ORGANISM_H
