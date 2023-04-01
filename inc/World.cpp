//
// Created by Kaitlyn Archambault on 2023-03-29.
//

#include "World.h"

//--------------------------------Constructors--------------------------------//

World::World() {

    //create an empty world:
    for (int i=0;i<WORLD_SIZE;i++) {
        for (int j=0;j<WORLD_SIZE;j++) {

            world[i][j] = nullptr;
        }
    }
}

//------------------------------Class Methods--------------------------------//

Point World::randomPoint() {

    //generate a new random seed every time the program is run
    std::random_device rd;

    //make sure the point falls within the limits of the world
    std::uniform_int_distribution<int> dist(0, WORLD_SIZE);

    Point point(dist(rd), dist(rd));

    return point;
}

void World::populateWorld() {

    //TODO this needs to be done in quadrants to minimize bias

    //initialize some spots with prey and predators
    bool pointEmpty = false;

    //prey
    for (int i=0;i<STARTING_PREY;i++) {

        Point point;
        pointEmpty = false;

        //check that the random point falls in a null spot on the world
        while (!pointEmpty) {

            point = randomPoint();

            if (world[point.getX()][point.getY()] == nullptr)
            {
                pointEmpty = true;
            }
        }
        //make the new prey
        Organism* prey = new Prey(point);

        //set them in the world
        world[point.getX()][point.getY()] = prey;
    }

    //predators
    for (int i=0;i<STARTING_PREDATORS;i++) {

        Point point;
        pointEmpty = false;

        //check that the random point falls in a null spot on the world
        while (!pointEmpty) {

            point = randomPoint();

            if (world[point.getX()][point.getY()] == nullptr)
            {
                pointEmpty = true;
            }
        }
        //make the new predator
        Organism* predator = new Predator(point);

        //set them in the world
        world[point.getX()][point.getY()] = predator;
    }
}

void World::takeTurns() {

    for (int i=0;i<WORLD_SIZE;i++) {
        for (int j=0;j<WORLD_SIZE;j++) {

            if (world[i][j] != nullptr) {

                world[i][j]->move();
            }
        }
    }
}

ostream& operator<<(ostream &output, const World& world) {

    //print the arena:
    for (int i = 0; i < WORLD_SIZE; i++) {
        for (int j = 0; j < WORLD_SIZE; j++) {

            if (world.world[i][j] == nullptr) output << " " << "-" << " ";

            else
                (output << " " << world.world[i][j]->getSymbol())
                        << " "; //will print a 'z' for predator, 'h' for prey, '-' for null
        }
        output << endl;
    }

    return output;
}
