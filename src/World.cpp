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

int World::getPredatorCount() const {
    return predatorCount;
}

bool World::hasDiversity() const {
    return (preyCount > 0 && predatorCount > 0);
}

bool World::containsPrey(Point point) {

    if (point.getX() < 0 || point.getY() < 0 || point.getX() > WORLD_SIZE - 1 || point.getY() > WORLD_SIZE - 1)
        return false;

    if (world[point.getX()][point.getY()] != nullptr)
        return (world[point.getX()][point.getY()]->getSymbol() == 'h');

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
    if (point.getX() < 0 || point.getY() < 0 || point.getX() > WORLD_SIZE - 1 || point.getY() > WORLD_SIZE - 1)
        return false;

    return (world[point.getX()][point.getY()] == nullptr);
}

//initializes
void World::populateWorld() {

    Point point;

    //prey
    while (preyCount < STARTING_PREY) {

        point = randomPoint();

        if (pointEmpty(point)) {

            Organism* prey = new Prey(point, this);
            preyCount++;
            //set them in the world
            world[point.getX()][point.getY()] = prey;
        }
    }

    //do the same for predators
    while (predatorCount < STARTING_PREDATORS) {

        point = randomPoint();

        if (pointEmpty(point)) {

            Organism* predator = new Predator(point, this);
            predatorCount++;
            //set them in the world
            world[point.getX()][point.getY()] = predator;
        }
    }
}

void World::removeOrganismAt(Point point) {

    world[point.getX()][point.getY()] = nullptr;
}

void World::killOrganismAt(Point point) {

    //if this method is called it's already been checked that the point isn't a null pointer
    if (world[point.getX()][point.getY()]->getSymbol() == 'h')
        this->preyCount--;
    else
        this->predatorCount--;
}

void World::placeOrganismAt(Point point, Organism* movedOrganism) {

    if(pointEmpty(point)) {
        delete world[point.getX()][point.getY()];
        world[point.getX()][point.getY()] = movedOrganism;
    }
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
                (output << " " << organism->getSymbol())
                        << " "; //will print a 'z' for predator, 'h' for prey, '-' for null
        }
        output << endl;
    }

    return output;
}

