//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#include <random>
#include "Predator.h"
#include "World.h"

//--------------------------------Constructors--------------------------------//

Predator::Predator(Point point, World* worldptr) : Organism(point, worldptr, symbol),
    hunger(0)
{}

Predator::~Predator() = default;

//------------------------------Getters/Setters--------------------------------//
void Predator::setPossibleMoves() {

    PointVector possibleMoves;

    possibleMoves.push_back(*new Point(location.getX()-1, location.getY()));
    possibleMoves.push_back(*new Point(location.getX()+1, location.getY()));
    possibleMoves.push_back(*new Point(location.getX(), location.getY()-1));
    possibleMoves.push_back(*new Point(location.getX(), location.getY()+1));
    //predators only get diagonal movements
    possibleMoves.push_back(*new Point(location.getX()-1, location.getY()-1));
    possibleMoves.push_back(*new Point(location.getX()+1, location.getY()+1));
    possibleMoves.push_back(*new Point(location.getX()-1, location.getY()+1));
    possibleMoves.push_back(*new Point(location.getX()+1, location.getY()-1));

    //make the possible moves appear in random order
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();//create random seed using system clock
    shuffle(possibleMoves.begin(),possibleMoves.end(),default_random_engine(seed));

    this->possibleMoves = possibleMoves;
}
//------------------------------Class Methods--------------------------------//

void Predator::turn() {

    if (!moved) {

        setPossibleMoves();
        hunger++;
        move(); //this will reset hunger if they eat

        if (hunger >= TURNS_TO_STARVE) {
            thisWorld->killOrganismAt(location);
            thisWorld->removeOrganismAt(location);
            //this predator has died
            return;
        }
    }
}

void Predator::move() {

    Point previousLocation = location;
    Point pointToMove;
    int i = 0;

    //first check if they can eat
    while (!moved && i<PREDATOR_MOVE_POINTS) {

        pointToMove = possibleMoves.at(i);
        i++;

        if (thisWorld->containsPrey(pointToMove)) {
            eat(pointToMove);
            location = pointToMove;
            this->moved = true;
        }
    }

    //TODO having two of the same loop feels janky see if you can fix this
    i = 0;
    //if eating wasn't possible, try to just move
    while (!moved && i<PREDATOR_MOVE_POINTS) {

        //this will force the organism to check all available move points if one or more are blocked
        pointToMove = possibleMoves.at(i);
        i++;

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

void Predator::eat(Point point) {

    //if there's an adjacent prey, destroy them
    thisWorld->killOrganismAt(point);
    thisWorld->removeOrganismAt(point);
    //reset hunger to 0;
    hunger = 0;
}