#ifndef LOCATION_PROJ1_H
#define LOCATION_PROJ1_H

#include <iostream>

using namespace std;

/* An object of the Location class represents a location, and also the ability
 * to find out all the possible "neighbors" of this location through an
 * iteration interface.
 *
 * The coordinates inside the Location are hidden.  A client may stream in a
 * Location object, or stream it out, but may not view its internals directly.
 * However, a client may test to see whether two Location objects are equal
 * (which is true only if their data members row and col are equal).
 *
 * A Location object acts as an iterator over all neighbor locations.  Two
 * Locations are neighbors if their rows are the same and their columns differ
 * by 1, or if their columns are the same and their rows differ by 1. A client
 * should be able to find all the neighbors of a Location loc the following
 * way:
 *
 *   for (loc.iterationBegin(); !loc.iterationDone(); loc.iterationAdvance()) {
 *       Location neighbor = loc.iterationCurrent();
 *       cout << neighbor << endl;
 *   }
 *
 * The iterationBegin() method initializes the iteration capability of a
 * Location object.  The iterationCurrent() method creates a copy of the current
 * Location object, modifies the copy so that it represents a different location
 * (either in row or column), and it returns the neighbor it created.  The
 * iterationAdvance() method moves the iteration forward, so that the next time
 * iterationCurrent() is called, it returns a different neighbor.  The
 * iterationDone() method returns true when the all the neighbors of a Location
 * have been iterated over.
 *
 * Iteration must proceed in a well-defined way for this project. The first
 * neighbor visited is to the right of the current location, then down, then to
 * the left, then up. The iterationCurrent() method should never return the same
 * Location that it was called on (i.e. a Location is never a neighbor of
 * itself).
 *
 * A Location object keeps track of where it is in the iteration sequence with
 * the data member nextDirection, which should take the value RIGHT, DOWN,
 * LEFT, UP, or DONE. These constant values are defined in the enum in the
 * class.
 *
 * The operator==() provides a means of comparing two Location objects. Two
 * Location objects are equal if they represent the same row and col (again,
 * regardless of each one's iteration status).
 *
 * The friend functions operator<<() and operator>>() provide a means of
 * streaming a Location object in or out. The operator<<() should not write an
 * endline; let the caller determine whether it wants a return.  Remember to
 * return a stream reference from each function so that input and output can be
 * chained together.
 *
 * The constructor should initialize the data members to reasonable values.
 *
 * We don't need to write the "big five" (operator=, copy constructor, move
 * constructor, and move operator=, and destructor) for this class because the
 * class does not allocate any memory, so the ones the compiler automatically
 * creates are sufficient.
 */
class Location {
public:
    Location();

    void iterationBegin();
    Location iterationCurrent() const;
    void iterationAdvance();
    bool iterationDone() const;

    bool operator==(const Location &loc) const;

    friend ostream &operator<<(ostream &os, const Location &loc);
    friend istream &operator>>(istream &is, Location &loc);

    enum { RIGHT, DOWN, LEFT, UP, DONE };

protected:
    int row, col;
    unsigned int nextDirection;
};

#endif
