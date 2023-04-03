//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#include "Organism.h"

//--------------------------------Constructors--------------------------------//

Organism::Organism(Point point, World* world, char symbol):
isAlive(true), location(point), thisWorld(world), symbol(symbol), turnsSinceReproduced(0), moved(true)
{}

Organism::~Organism() = default;

//------------------------------Getters/Setters--------------------------------//

char Organism::getSymbol() {
    return symbol;
}

void Organism::setPossibleMoves() {
    this->possibleMoves = possibleMoves;
}

void Organism::setMoved(bool moved) {
    this->moved = moved;
}

//------------------------------Class Methods--------------------------------//

ostream& operator<<(ostream &output, const Organism& organism) {

    const std::string reset("\033[90m");
    const std::string pred("\033[33m");
    const std::string prey("\033[34m");

    if (organism.symbol == PREY_SYMBOL)
        output << " " << prey << organism.symbol << reset << " ";
    else if (organism.symbol == PREDATOR_SYMBOL)
        output << " " << pred << organism.symbol << reset << " ";

    return output;
}