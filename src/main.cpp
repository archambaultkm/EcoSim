#include <iostream>
#include "World.h"

#include <thread>

int main() {

    int generation = 0;

    auto* world = new World();

    //populate with both predators and prey
    world->populateWorld();

    while (world->hasDiversity()) {
        cout << *world;
        cout << "Generation: " << generation;
        cout << "  Prey remaining: " << world->getPreyCount();
        cout << "  Predators remaining: " << world->getPredatorCount() << endl;

        this_thread::sleep_for(0.5s);

        world->takeTurns();
        world->resetFlags();

        generation++;
        //"clear screen"
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }

    return 0;
}