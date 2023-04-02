//
// Created by Kaitlyn Archambault on 2023-03-11.
//

#include "Organism.h"

//--------------------------------Constructors--------------------------------//

Organism::Organism(Point point, World* world, char symbol):
isAlive(true), location(point), thisWorld(world), symbol(symbol), moved(false)
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

bool Organism::getMoved() {
    return moved;
}