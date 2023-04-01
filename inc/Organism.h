//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#ifndef ECOSIM_ORGANISM_H
#define ECOSIM_ORGANISM_H

#include "Point.h"
//#include "World.h"

#include <vector>
using namespace std;

class Organism {
private:

    //WorldPtr thisWorld;
    bool isAlive;
    bool moved;
    Point location;
    PointVector possibleMoves;
    char symbol;

public:

    //-------------------Constructors-------------------//
    Organism();
    Organism(Point point, char symbol);
    ~Organism();

    //-------------------Getters/Setters-------------------//
    bool getAliveStatus();
    void setAliveStatus(bool alive);

    Point getLocation();
    void setLocation(Point newLocation);

    PointVector getPossibleMoves();
    void setPossibleMoves(PointVector possibleMoves);

    virtual char getSymbol() = 0;

    //-------------------Member Functions-------------------//
    virtual void turn() = 0;
    virtual void move() = 0;
};


#endif //ECOSIM_ORGANISM_H
