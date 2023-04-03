//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#include <random>
#include "Predator.h"
#include "World.h"
#include "Prey.h"

//--------------------------------Constructors--------------------------------//

Predator::Predator(Point point, World* worldptr) : Organism(point, worldptr, symbol),
    hunger(0)
{
    thisWorld->incPredatorCount();
}

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
    std::random_device rd;
    shuffle(possibleMoves.begin(),possibleMoves.end(), rd);

    this->possibleMoves = possibleMoves;
}
//------------------------------Class Methods--------------------------------//

void Predator::turn() {

    if (!moved) {

        hunger++;
        turnsSinceReproduced++;

        setPossibleMoves();
        move(); //this will reset hunger if they eat

        if (turnsSinceReproduced >= PREDATOR_TURNS_TO_REPRODUCE) {
            setPossibleMoves();
            reproduce();
        }

        if (hunger >= TURNS_TO_STARVE) {
            //this predator has died :(
            thisWorld->removeOrganismAt(location, true);

            //this predator reverts to a prey
            Organism* prey = new Prey(location, thisWorld);
            thisWorld->placeOrganismAt(location, prey);

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
        thisWorld->removeOrganismAt(previousLocation, false);
    }
}

void Predator::eat(Point point) {

    //if there's an adjacent prey, destroy them
    thisWorld->removeOrganismAt(point, true);
    //reset hunger to 0;
    hunger = 0;
}

void Predator::reproduce() {

    Point pointToReproduce;
    int i=0;

    while (turnsSinceReproduced !=0 && i<PREDATOR_MOVE_POINTS) {
        //cycle through the predator's adjacent spots for a prey to transform
        pointToReproduce = possibleMoves.at(i);
        i++;

        if (thisWorld->containsPrey(pointToReproduce)) {

            thisWorld->removeOrganismAt(pointToReproduce, true);

            Organism* baby = new Predator(pointToReproduce, thisWorld);
            thisWorld->placeOrganismAt(pointToReproduce, baby);

            turnsSinceReproduced = 0;
        }
    }
}

ostream& operator<<(ostream &output, const Predator& predator) {

    const std::string reset("\033[0m");
    const std::string red("\033[0;31m");

    output << " " << red << Predator::symbol << reset << " ";
    return output;
}