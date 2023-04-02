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

    //make the possible moves appear in random order
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock
    shuffle(possibleMoves.begin(),possibleMoves.end(),default_random_engine(seed));

    this->possibleMoves = possibleMoves;
}

//------------------------------Class Methods--------------------------------//

void Prey::turn() {

    if (!moved) {
        setPossibleMoves();
        move();
        //recruit();
    }
}

void Prey::move() {

    Point previousLocation = location;
    Point pointToMove;
    int i = 0;

    while (!moved && i<PREY_MOVE_POINTS) {

        //this will force the organism to check all available move points if one or more are blocked
        pointToMove = possibleMoves.at(i);
        i++;

        //if one of their possible moves isn't empty, they'll stay in the same spot and not be marked moved
        if (thisWorld->pointEmpty(pointToMove)) {
            location = pointToMove;
            this->moved = true;
        }
    }

    if (this->moved) {
        thisWorld->placeOrganismAt(location, this);
        thisWorld->removeOrganismAt(previousLocation);
    }
}

void Prey::recruit() {

    //every couple of turns they need to spawn a new human/prey in an adjacent(moveable)space.
}