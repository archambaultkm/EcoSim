#include <iostream>
#include "../inc/World.h"

#include <thread>

int main() {

    auto* world = new World();

    //populate with both predators and prey
    world->populateWorld();

    for (int i=0;i<20;i++) {
        //here needs to loop
        cout << *world;

        this_thread::sleep_for(1s);

        world->takeTurns();
        world->resetFlags();

        //"clear screen"
        cout << "\n";
    }

    return 0;
}