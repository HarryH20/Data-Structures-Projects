#ifndef MAZE_PROJ1_H
#define MAZE_PROJ1_H

#include <iostream>
#include <cassert>
#include "location-proj1.h"

using namespace std;

/* A Maze object contains three things: the starting location, the
 * ending location, and a list of valid locations. It does not contain
 * any logic for actually solving the maze.
 *
 * The Maze constructor initializes all the data members that it can,
 * but the validLocationCount will not yet be known when the Maze is
 * constructed, so use a sensible value here.
 *
 * The Maze destructor should free any memory that the object is
 * using. It's also wise to use a destructor to make an object "look"
 * empty.
 *
 * getStartLocation() returns the starting location of the maze.
 * isEndLocation() returns true if the given Location is the end of
 * the maze, otherwise false.  isValidLocation() returns true if the
 * given Location is in the list of valid Locations, otherwise false.
 *
 * operator>>() provides a means of streaming in a Maze object.  In
 * this version, operator>>() does not do any error checking.  We
 * assume that the entered data is perfect. Consider the following
 * when writing this function: what if we stream in a Maze object with
 * this function, and later call the same function on the same object?
 *
 * validLocationCount keeps the number of valid locations, which will
 * not be known until the object is streamed in. This is the length of
 * the validLocations array.
 *
 * validLocations is an array that contains all the locations that may
 * be used to solve the maze.
 *
 * startLocation holds the starting location of the maze, and
 * endLocation holds the target location of the maze.
 *
 * We make the operator=() and copy constructor non-public and illegal to
 * call, because they are not needed in this project, and we don't
 * want the compiler to provide them for us (since this class uses
 * dynamically allocated memory).  If these methods are called, they
 * will intentionally crash the program by the call to assert(false).
 */
class Maze {
public:

    Maze(void);
    ~Maze();

    Location getStartLocation(void) const;
    bool isValidLocation(const Location &loc) const;
    bool isEndLocation(const Location &loc) const;


    friend istream &operator>>(istream &is, Maze &m);

protected:
    Maze(const Maze &) { assert(false); }
    const Maze &operator=(const Maze &)
    { assert(false); return *this; }

    int validLocationCount;
    Location *validLocations;

    Location startLocation, endLocation;
};

#endif
