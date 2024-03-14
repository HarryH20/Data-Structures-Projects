#ifndef LOCATION_STACK_PROJ1_H
#define LOCATION_STACK_PROJ1_H

#include "location-proj1.h"
#include <cassert>
#include <iostream>

using namespace std;

/* This is a pre-declaration for the class LocationStackNode, so that
 * within the LocationStack class we may declare a pointer to a
 * LocationStackNode.
 */
class LocationStackNode;

/* Class declaration for a simple stack of Location objects. It is not
 * a templated class; it can contain only Location objects. It can
 * grow and shrink because it is a linked structure. The class
 * LocationStackNode (below) encapsulates the nodes of the stack.
 *
 * Methods push(), pop(), and getTop() provide standard stack methods.
 * Using assert() to check for problems in these three methods could
 * be useful (hint).  isEmpty() returns true if the stack is empty,
 * false otherwise. isOn() returns true if the given Location is on
 * the stack, otherwise returns false.
 *
 * operator<<() streams out the stack from bottom to top. This method
 * should NOT make a copy of the stack. Instead, it should require two
 * passes over the stack to print the stack. The first pass will
 * traverse the stack to top->bottom, reversing the links of the nodes
 * as it goes. The second pass will traverse from bottom->top,
 * printing each Location as it is visited, and undoing the reversing
 * of the node links.
 *
 * The default constructor initializes the data members as
 * appropriate, and the destructor frees any allocated memory. The
 * copy constructor and operator= are not usable in this class;
 * therefore they are non-public and will fail on an assert() if called.
 *
 * The data member top is a pointer to the top node.
 */

class LocationStack {
public:
    LocationStack(void);
    ~LocationStack();

    void push(const Location &loc);
    void pop(void);
    const Location &getTop(void) const;

    bool isEmpty(void) const;
    bool isOn(const Location &loc) const;

    friend ostream &operator<<(ostream &os, const LocationStack &s);

protected:
    const LocationStack & operator=(const LocationStack &)
    { assert(false); return *this; }
    LocationStack(const LocationStack &) { assert(false); }

    LocationStackNode *top;
};

/* Class declaration for a Node on a LocationStack. Each node contains
 * a Location and a link to the next LocationStackNode (the one below
 * it on the stack).
 *
 * The only constructor that may be used for this class is the one
 * which takes values to initialize its data members. Other
 * constructors and the operator= may not be called. These
 * restrictions help prevent us from accidentally making multiple
 * nodes that all point to the same next node.
 *
 * The destructor should call delete on the nextNode, so that deleting
 * the top of the stack has a chaining effect that deletes every node
 * on the stack.
 *
 * The get/set methods for this class are self-explanatory, and are
 * the interface by which you should modify a node as necessary.
 */
class LocationStackNode {
public:
    LocationStackNode(const Location &loc, LocationStackNode *next = NULL);
    ~LocationStackNode();

    const Location &getLocation() const;
    LocationStackNode *getNextNode() const;
    void setNextNode(LocationStackNode *next);

protected:
    LocationStackNode() { assert(false); }
    LocationStackNode(const LocationStackNode &) { assert(false); }
    LocationStackNode &operator=(const LocationStackNode &)
    { assert(false); return *this; }

    Location location;
    LocationStackNode *nextNode;
};


#endif

