//
// Created by Kaitlyn Archambault on 2023-03-29.
//

#include "World.h"
#include "Prey.h"
#include "Predator.h"

//--------------------------------Constructors--------------------------------//

World::World():
preyCount(0), predatorCount(0) {

    //create an empty world:
    for (int i=0;i<WORLD_SIZE;i++) {
        for (int j=0;j<WORLD_SIZE;j++) {

            world[i][j] = nullptr;
        }
    }
}

World::~World() = default;

//------------------------------Getters/Setters--------------------------------//
int World::getPreyCount() const {
    return preyCount;
}

void World::incPreyCount() {
    preyCount++;
}

int World::getPredatorCount() const {
    return predatorCount;
}

void World::incPredatorCount() {
    predatorCount++;
}

bool World::hasDiversity() const {
    return (preyCount > 0 && predatorCount > 0);
}

//used by the predator class to check if they can eat/reproduce
bool World::containsPrey(Point point) {

    if (point.x < 0 || point.y < 0 || point.x > WORLD_SIZE - 1 || point.y > WORLD_SIZE - 1)
        return false;

    if (world[point.x][point.y] != nullptr)
        return (world[point.x][point.y]->getSymbol() == PREY_SYMBOL);

    return false;
}

//------------------------------Class Methods--------------------------------//

Point World::randomPoint() {

    //generate a new random seed every time the program is run
    std::random_device rd;

    //make sure the point falls within the limits of the world
    std::uniform_int_distribution<int> dist(0, WORLD_SIZE - 1);

    Point point(dist(rd), dist(rd));

    return point;
}

bool World::pointEmpty(Point point) {

    //need to do an out-of-bounds check before looking into the world array
    if (point.x < 0 || point.y < 0 || point.x > WORLD_SIZE - 1 || point.y > WORLD_SIZE - 1)
        return false;

    return (world[point.x][point.y] == nullptr);
}

//initializes
void World::populateWorld() {

    Point point;

    //prey
    while (preyCount < STARTING_PREY) {

        point = randomPoint();

        if (pointEmpty(point)) {

            Organism* prey = new Prey(point, this);
            //set them in the world
            world[point.x][point.y] = prey;
        }
    }

    //do the same for predators
    while (predatorCount < STARTING_PREDATORS) {

        point = randomPoint();

        if (pointEmpty(point)) {

            Organism* predator = new Predator(point, this);
            //set them in the world
            world[point.x][point.y] = predator;
        }
    }
}

void World::removeOrganismAt(Point point, bool kill) {

    if (kill) {
        if (world[point.x][point.y]->getSymbol() == PREY_SYMBOL)
            this->preyCount--;
        else
            this->predatorCount--;
    }

    world[point.x][point.y] = nullptr;
}

void World::placeOrganismAt(Point point, Organism* movedOrganism) {

    //delete world[point.getX()][point.getY()];
    world[point.x][point.y] = movedOrganism;
}

void World::takeTurns() {

    for (auto & row : world) {
        for (auto & organism : row) {

            if (organism != nullptr) {

                organism->turn();
            }
        }
    }
}

void World::resetFlags() {

    for (auto & row : world) {
        for (auto & organism : row) {

            if (organism != nullptr) {

                organism->setMoved(false);
            }
        }
    }
}


ostream& operator<<(ostream &output, const World& world) {

    //print the arena:
    for (const auto & row : world.world) {
        for (auto organism : row) {

            if (organism == nullptr) output << " " << "-" << " ";

            else
                output << *organism;
        }
        output << endl;
    }

    return output;
}

