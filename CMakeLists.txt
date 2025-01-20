cmake_minimum_required(VERSION 3.10)
project(SpaceInvaders)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SpaceInvaders main.cpp tutorial.cpp commandSuite.cpp GameData.cpp playerController.cpp)