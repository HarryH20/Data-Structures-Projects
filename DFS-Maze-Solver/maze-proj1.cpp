/* CSI 3334
 * Project 1 -- Maze
 * Filename: maze-proj1.cpp
 * Student name: Harrison Hassler
 * Due Date: Sept 8, 2023
 * Description: This file tests the functions in
 *     maze-proj1.h
 */


#include "maze-proj1.h"
#include <iostream>
using namespace std;
/*
 * Maze
 *
 * This function is a default
 *     constructor for the Maze class
 *
 * parameters: None
 *
 * return values: None, it just sets
 *     validLocations to nullptr and
 *     validLocationCount to 0
 */
Maze::Maze(void){
    validLocations = nullptr;
    validLocationCount = 0;
}

/*
 * ~Maze
 *
 * This function is a destructor
 *     for the Maze class
 *
 * parameters: None
 *
 * return values: None, it deletes
 *     all the validLocations in the array
 *     and makes the object "look" empty
 */
Maze::~Maze(){
    delete[] validLocations;
    validLocations = nullptr;
    validLocationCount = 0;
}

/*
 * getStartLocation
 *
 * This function gets the start location
 *     of the maze
 *
 * parameters: None
 *
 * return values: the start location
 */
Location Maze::getStartLocation() const {
    return startLocation;
}

/*
 * isValidLocation
 *
 * Checks to see if a location is in
 *     the array by looping through it
 *
 * parameters: loc- a location object passed by
 *     reference
 *
 * return values: returns if the loc is
 *     in the array
 */
bool Maze::isValidLocation(const Location &loc) const {
    for(int i = 0; i < validLocationCount; i++) {
        if (loc == validLocations[i]) {
            return true;
        }
    }
    return false;


}

/*
 * isEndLocation
 *
 * Checks to see if a location is the
 *     end location
 *
 * parameters: loc- a Location passed by
 *     reference
 *
 * return values: returns if the loc is
 *     the end loc
 */
bool Maze::isEndLocation(const Location &loc) const {
    if(loc == endLocation){
        return true;
    }
    return false;
}

/*
 * isstream operator
 *
 * Streams in the maze object
 *     made up of the number of valid
 *     locations, the valid locations, and
 *     the start and end locations
 *
 * parameters: is- to stream in a maze object
 *             m- a maze object passed by reference
 *                being streamed in
 *
 * return values: returns the istream object
 */
istream& operator>>(istream &is, Maze &m){
    delete[] m.validLocations;
    is >> m.validLocationCount;
    m.validLocations = new Location[m.validLocationCount];

    for(int i = 0; i < m.validLocationCount; i++){
        is >> m.validLocations[i];
    }

    is >> m.startLocation;
    is >> m.endLocation;

    return is;
}



