//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#include <random>
#include "Prey.h"
#include "World.h"

//--------------------------------Constructors--------------------------------//
Prey::Prey(Point point, World* worldptr) : Organism(point, worldptr, symbol)
{}

Prey::~Prey() {}

//------------------------------Getters/Setters--------------------------------//

void Prey::setPossibleMoves() {

    PointVector possibleMoves;

    possibleMoves.push_back(*new Point(location.getX()-1, location.getY()));
    possibleMoves.push_back(*new Point(location.getX()+1, location.getY()));
    possibleMoves.push_back(*new Point(location.getX(), location.getY()-1));
    possibleMoves.push_back(*new Point(location.getX(), location.getY()+1));

    this->possibleMoves = possibleMoves;
}

//------------------------------Class Methods--------------------------------//

void Prey::turn() {

    if (!moved) {
        move();
        //recruit();
    }
}

void Prey::move() {

    //TODO I don't know if here or turn is the spot that makes most sense to call it
    setPossibleMoves();

    //pick a random spot out of the possibleMoves vector
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock
    shuffle(possibleMoves.begin(),possibleMoves.end(),default_random_engine(seed));

    Point previousLocation = location;
    Point pointToMove;
    int i = 0;

    while (!moved && i<PREY_MOVE_POINTS) {

        pointToMove = possibleMoves.at(i);
        i++;

        int newX = pointToMove.getX();
        int newY = pointToMove.getY();

        //if the new x or y coordinate will fall out of bounds, default that coordinate to their current location
        if (newX < 0 || newX > WORLD_SIZE) {
            pointToMove.setX(location.getX());
        }

        if (newY < 0 || newY > WORLD_SIZE) {
            pointToMove.setY(location.getY());
        }

        //TODO this assumes one of their possible moves is empty, make a safety net
        if (thisWorld->pointEmpty(pointToMove)) {
            location = pointToMove;
            moved = true;
        }
    }

    thisWorld->placeOrganismAt(location, this);
    thisWorld->removeOrganismAt(previousLocation);
}

void Prey::recruit() {

    //every couple of turns they need to spawn a new human/prey in an adjacent(moveable)space.
}