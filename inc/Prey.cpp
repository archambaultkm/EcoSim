//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#include "Prey.h"

#define WORLD_SIZE 20 //TODO this is obviously a bad solution, figure out something better

//--------------------------------Constructors--------------------------------//

Prey::Prey():Organism()
{}

Prey::Prey(Point point) : Organism(point, symbol)
{}

Prey::~Prey() {}

//------------------------------Getters/Setters--------------------------------//

char Prey::getSymbol() {
    return symbol;
}

//------------------------------Class Methods--------------------------------//

void Prey::turn() {

    move();
    //recruit();
}

void Prey::move() {
    //pick a random spot out of the possibleMoves vector
    Point currentPoint = this->getLocation();

    int newX = currentPoint.getX() - 1;
    int newY = currentPoint.getY() - 1;

    if (newX <0 || newX > WORLD_SIZE) {
        newX = currentPoint.getX();
    }

    if (newY <0 || newY > WORLD_SIZE) {
        newY = currentPoint.getY();
    }

    Point newPoint(newX, newY);

    this->setLocation(newPoint);
}

void Prey::recruit() {

    //every couple of turns they need to spawn a new human/prey in an adjacent(moveable)space.
}