//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#include <random>
#include "Prey.h"
#include "World.h"

//--------------------------------Constructors--------------------------------//
Prey::Prey(Point point, World* worldptr) : Organism(point, worldptr, symbol)
{
    thisWorld->incPreyCount();
}

Prey::~Prey() = default;

//------------------------------Getters/Setters--------------------------------//

void Prey::setPossibleMoves() {

    PointVector possibleMoves;

    //TODO directions should be an enum
    possibleMoves.push_back(*new Point(location.x-1, location.y));
    possibleMoves.push_back(*new Point(location.x+1, location.y));
    possibleMoves.push_back(*new Point(location.x, location.y-1));
    possibleMoves.push_back(*new Point(location.x, location.y+1));

    std::random_device rd;
    //this will produce a different shuffle sequence each time it's run (more random)
    auto rng = std::default_random_engine { rd() };
    shuffle(possibleMoves.begin(),possibleMoves.end(), rng);

    this->possibleMoves = possibleMoves;
}

//------------------------------Class Methods--------------------------------//

void Prey::turn() {

    turnsSinceReproduced++;

    if (!moved) {
        setPossibleMoves();
        move();

        if (turnsSinceReproduced == PREY_TURNS_TO_REPRODUCE) {
            setPossibleMoves();
            reproduce();
        }
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
        thisWorld->removeOrganismAt(previousLocation, false);
    }
}

//method only called if they're allowed to try to reproduce that turn
void Prey::reproduce() {

    //every couple of turns they need to spawn a new human/prey in an adjacent(moveable)space.
    Point pointToReproduce;
    int i=0;

    while (turnsSinceReproduced !=0 && i<PREY_MOVE_POINTS) {
        //cycle through the predator's adjacent spots for a prey to transform
        pointToReproduce = possibleMoves.at(i);
        i++;

        if (thisWorld->pointEmpty(pointToReproduce)) {

            turnsSinceReproduced = 0;

            Organism* baby = new Prey(pointToReproduce, thisWorld);
            thisWorld->placeOrganismAt(pointToReproduce, baby);
        }
    }

    //for prey the reproduction counter needs to be reset regardless of if they succeeded
    turnsSinceReproduced = 0;
}