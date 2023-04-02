#include <iostream>
#include "World.h"

#include <thread>

int main() {

    int generation = 0;

    auto* world = new World();

    //populate with both predators and prey
    world->populateWorld();

    while (world->hasDiversity()) {
        //here needs to loop
        cout << *world;

        this_thread::sleep_for(1s);

        world->takeTurns();
        world->resetFlags();

        generation++;
        //"clear screen"
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    }

    cout << "Generation: " << generation << endl;
    cout << "Prey remaining: " << world->getPreyCount() << endl;
    cout << "Predators remaining: " << world->getPredatorCount() << endl;

    return 0;
}