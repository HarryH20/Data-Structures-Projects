/* CSI 3334
 * Project 2 -- WordMelt
 * Filename: maze-proj2.cpp
 * Student name: Harrison Hassler
 * Due Date: Sept 15, 2023
 * Description: This file implements the functions in
 *     maze-proj2.h
 */


#include "maze-proj2.h"

Maze::Maze(void){
    validLocations = set<Location>();

}

Location Maze::getStartLocation(void) const {
    return startLocation;
}

bool Maze::isValidLocation(const Location &loc) const {
    if(validLocations.find(loc) != validLocations.end()){
        return true;
    }
    return false;
}

bool Maze::isEndLocation(const Location &loc) const {
    return loc == endLocation;
}

istream &operator>>(istream &is, Maze &m){
    Location loc;
    m.validLocations.clear();
    int size;
    is >> size;
    for(int i = 0; i < size; i++){
        is >> loc;
        m.validLocations.insert(loc);
    }
    is >> m.startLocation;
    is >> m.endLocation;
    return is;
}