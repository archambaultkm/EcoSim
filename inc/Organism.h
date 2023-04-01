//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#ifndef ECOSIM_ORGANISM_H
#define ECOSIM_ORGANISM_H

#include "GameSpecs.h"
#include "Point.h"

#include <vector>
using namespace std;

//define it here rather than including the world header so that you don't break things
class World;

class Organism {
protected:

    World* thisWorld;
    bool isAlive;
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
    char getSymbol();

    //-------------------Member Functions-------------------//
    virtual void turn() = 0;
    virtual void move() = 0;
};

#endif //ECOSIM_ORGANISM_H
