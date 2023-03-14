#include <iostream>
#include "../inc/Animal.h"
#include "../inc/Prey.h"
#include "../inc/Predator.h"

#include <random>

#define WORLD_SIZE 20
#define STARTING_PREY 30
#define STARTING_PREDATORS 5

Point randomPoint() {

    Point point;

    //srand(time(0)) and rand() wasn't working

    //generate a new random seed every time the program is run
    random_device rd;

    //make sure the point falls within the limits of the world
    uniform_int_distribution<int> dist(0, WORLD_SIZE);

    point.setX(dist(rd));
    point.setY(dist(rd));

    return point;
}

int main() {

    //make a seperate header file for all these "world" methods, main should just run it

    Animal* world[WORLD_SIZE][WORLD_SIZE];

    //create an empty world:
    for (int i=0;i<WORLD_SIZE;i++) {
        for (int j=0;j<WORLD_SIZE;j++) {

            world[i][j] = nullptr;
        }
    }

    //initialize some spots with prey and predators

    //prey
    for (int i=0;i<STARTING_PREY;i++) {

        Point point;
        bool pointEmpty = false;

        //check that the random point falls in a null spot on the world
        while (!pointEmpty) {

            point = randomPoint();

            if (world[point.getX()][point.getY()] == nullptr)
            {
                pointEmpty = true;
            }
        }

        //make the new prey
        Animal* prey = new Prey(point);

        //set them in the world
        world[point.getX()][point.getY()] = prey;
    }

    //predators
    for (int i=0;i<STARTING_PREDATORS;i++) {

        Point point;
        bool pointEmpty = false;

        //check that the random point falls in a null spot on the world
        while (!pointEmpty) {

            point = randomPoint();

            if (world[point.getX()][point.getY()] == nullptr)
            {
                pointEmpty = true;
            }
        }

        //make the new prey
        Animal* predator = new Predator(point);

        //set them in the world
        world[point.getX()][point.getY()] = predator;
    }

    //print the arena:
    for (int i=0;i<WORLD_SIZE;i++) {
        for (int j=0;j<WORLD_SIZE;j++) {

            if (world[i][j] == nullptr) cout << " " << "-" << " ";

            else (cout << " " << world[i][j]->getSymbol()) << " "; //will print an 'x' for predator, 'o' for prey, '-' for null
        }

        cout << endl;
    }


    return 0;
}