cmake_minimum_required(VERSION 3.31)
project(advancedcpp_lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(advancedcpp_lab1 src/main.cpp
        src/DeckManager.cpp
        src/DeckManager.h
        src/Card.cpp
        src/Card.h)
