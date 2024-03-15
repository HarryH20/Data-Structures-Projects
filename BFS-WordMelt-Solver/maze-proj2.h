#ifndef MAZE_PROJ2_H
#define MAZE_PROJ2_H

#include <iostream>
#include <set>
#include "location-proj2.h"

using namespace std;

/* Changes from project 1:
 *
 * Data member validLocations was changed from a Location array to a
 * set<Location>, but it still represents the group of locations that may be
 * visited in the maze.
 *
 * Data member validLocationCount was eliminated (because validLocations is no
 * longer an array).
 *
 * We let the compiler provide the operator=, copy constructor, and destructor
 * for this version of the Maze, since this Maze does not handle any memory
 * allocations itself.
 */
class Maze {
public:
    Maze(void);

    Location getStartLocation(void) const;
    bool isValidLocation(const Location &loc) const;
    bool isEndLocation(const Location &loc) const;

    friend istream &operator>>(istream &is, Maze &m);

private:
    set<Location> validLocations;

    Location startLocation, endLocation;
};

#endif