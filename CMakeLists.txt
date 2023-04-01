cmake_minimum_required(VERSION 3.24)
project(EcoSim)

set(CMAKE_CXX_STANDARD 17)

add_executable(EcoSim src/main.cpp inc/Organism.cpp inc/Organism.h inc/Predator.cpp inc/Predator.h inc/Prey.cpp inc/Prey.h inc/World.cpp inc/World.h inc/Point.cpp inc/Point.h inc/GameSpecs.h)
