cmake_minimum_required(VERSION 3.24)
project(EcoSim)

set(CMAKE_CXX_STANDARD 17)

add_executable(EcoSim src/main.cpp src/Organism.cpp src/Organism.h src/Predator.cpp src/Predator.h src/Prey.cpp src/Prey.h src/World.cpp src/World.h src/Point.cpp src/Point.h src/GameSpecs.h)
