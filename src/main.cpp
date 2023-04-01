#include <iostream>
#include "../inc/World.h"

#include <thread>

int main() {

    auto* world = new World();

    //populate with both predators and prey
    world->populateWorld();

    //here needs to loop
    cout << *world;

    this_thread::sleep_for(5s);

    world->takeTurns();

    cout << *world;

    return 0;
}