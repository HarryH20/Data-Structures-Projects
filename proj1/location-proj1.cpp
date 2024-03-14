/* CSI 3334
 * Project 1 -- Maze
 * Filename: location-proj1.cpp
 * Student name: Harrison Hassler
 * Due Date: Sept 8, 2023
 * Description: This file implements the functions in
 *     location-proj.h
 */


#include "location-proj1.h"
#include <iostream>
using namespace std;

/*
 * Location
 *
 * This function is a default constructor
 *     for the Location class.
 *
 * parameters: None
 *
 * return values: None, it just sets
 *     row, col and nextDirection to their
 *     appropriate values.
 */
Location::Location() {
    this->row = 0;
    this->col = 0;
    nextDirection = RIGHT;

}
/*
 * iterationBegin
 *
 * This function resets nextDirection
 *     so it can be used to reset the movement
 *     in depth 1st search.
 *
 * parameters: None
 *
 * return values: None, it just sets
 *     nextDirection to RIGHT.
 */
void Location::iterationBegin() {
    nextDirection = RIGHT;
}

/*
 * iterationCurrent
 *
 * This function creates a copy of
 *     the location object so that when
 *     iterationAdvance is called it returns
 *     a neighbor in a new location
 *
 * parameters: None
 *
 * return values: neighbor which is an object
 *     of the location class
 */
Location Location::iterationCurrent() const{
    Location neighbor = *this;
    if(nextDirection == RIGHT){
        neighbor.col++;
    }
    else if(nextDirection == DOWN){
        neighbor.row++;
    }
    else if(nextDirection == LEFT){
        neighbor.col--;
    }
    else if(nextDirection == UP){
        neighbor.row--;
    }
    return neighbor;

}

/*
 * iterationAdvance
 *
 * This function moves the iteration forward
 *     so that when iterationCurrent is called it
 *     returns a neighbor with a different location
 *
 * parameters: None
 *
 * return values: None, advances next direction.
 */
void Location::iterationAdvance() {
    nextDirection++;
}
/*
 * iterationDone
 *
 * Returns true when the neighbors
 *     have all been iterated through
 *
 * parameters: None
 *
 * return values: Returns true if
 *     the neighbors have been iterated through
 */
bool Location::iterationDone() const {
    return nextDirection == DONE;
}

/*
 * operator==
 *
 * compares two object locations
 *
 * parameters: loc- a passed by reference location
 *                 object used for comparison
 *
 * return values: Returns true if
 *     the objects are in the same place.
 */
bool Location::operator==(const Location &loc) const {
    return loc.row == row && loc.col == col;
}

/*
 * operator<<
 *
 * streams location object out
 *
 * parameters: loc- a passed by reference location
 *             os- a stream that passes out the row
 *                 and column
 *
 * return values: Returns the row and column number.
 */
ostream &operator<<(ostream &os, const Location &loc){
    os << loc.row << " " << loc.col;
    return os;
}

/*
 * operator>>
 *
 * streams location object in
 *
 * parameters: loc- a passed by reference location object
 *             is- to stream in the location object
 *
 * return values: Returns row and column number as
 *     a stream reference
 */
istream &operator>>(istream &is, Location &loc) {
    is >> loc.row >> loc.col;
    return is;
}

