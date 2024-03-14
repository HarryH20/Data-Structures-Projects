/* CSI 3334
 * Project 1 -- Maze
 * Filename: stack-proj1.cpp
 * Student name: Harrison Hassler
 * Due Date: Sept 8, 2023
 * Description: This file tests the functions in
 *     stack-proj1.h
 */


#include "stack-proj1.h"
#include <iostream>
using namespace std;

/*
 * LocationStackNode
 *
 * This function is a constructor
 *     for the LocationStackNode class
 *
 * parameters: loc- location object passed by reference
 *             next- a pointer to the next node
 *
 * return values: None, it just sets
 *     location and nextNode based
 *     on what the parameters are
 */
LocationStackNode::LocationStackNode(const Location &loc, LocationStackNode *next) {
    location = loc;
    nextNode = next;
}

/*
 * ~LocationStackNode
 *
 * This function is a destructor
 *     for the LocationStackNode class
 *
 * parameters: None
 *
 * return values: None, it deletes nextNode
 *     so that deleting the top node deletes
 *     the whole stack recursively.
 */
LocationStackNode::~LocationStackNode() {
        delete nextNode;

}

/*
 * getLocation
 *
 * This function returns the location
 *
 * parameters: None
 *
 * return values: Returns the location
 */
const Location &LocationStackNode::getLocation() const {
    return location;

}

/*
 * getNextNode
 *
 * This function returns the nextNode as the
 *    one below it on the stack
 *
 * parameters: None
 *
 * return values: Returns the nextNode
 */
LocationStackNode *LocationStackNode::getNextNode() const {
    return nextNode;
}

/*
 * setNextNode
 *
 * This function sets the nextNode on
 *     the stack
 *
 * parameters: loc- a LocationStackNode object that will
 *                  be the next node
 *
 * return values: None, just sets nextNode
 *    based on the parameters
 */
void LocationStackNode::setNextNode(LocationStackNode *next) {
    nextNode = next;
}

/*
 * LocationStack
 *
 * This function is a default constructor for
 *     the LocationStack class
 *
 * parameters: None
 *
 * return values: None, just sets the
 *    top node to null
 */
LocationStack::LocationStack() {
    top = nullptr;
}

/*
 * ~LocationStack
 *
 * This function is a destructor for
 *     the LocationStack class
 *
 * parameters: None
 *
 * return values: None, just deletes the top node
 *     calling the recursive function and sets top to
 *     null
 */
LocationStack::~LocationStack() {
   delete top;
   top = nullptr;
}

/*
 * push
 *
 * This function pushes a Location
 *     onto the top of the stack
 *
 * parameters: loc- a location object passed by reference
 *                  that will be pushed on the stack
 *
 * return values: None, it pushes the location
 *     onto the top of the stack
 */
void LocationStack::push(const Location &loc) {
    this->top = new LocationStackNode(loc,this->top);
}

/*
 * pop
 *
 * This function pops a Location
 *     off the top of the stack
 *
 * parameters: None
 *
 * return values: None, it asserts
 *    that the list is not empty then
 *    pops the location
 */
void LocationStack::pop() {
    assert(!isEmpty());
    LocationStackNode *temp = this->top;
    this->top = this->top->getNextNode();
    temp->setNextNode(nullptr);
    delete temp;


}

/*
 * getTop
 *
 * This function gets the top node
 *     off of the list
 *
 * parameters: None
 *
 * return values: It asserts
 *    that the list is not empty then
 *    returns the top location
 */
const Location &LocationStack::getTop() const {
    assert(!isEmpty());
    return this->top->getLocation();
}

/*
 * isEmpty
 *
 * This function checks if the
 *     list is empty
 *
 * parameters: None
 *
 * return values: Returns true
 *     if the list is empty
 */
bool LocationStack::isEmpty() const {
    return this->top == nullptr;

}

/*
 * isOn
 *
 * This function checks if a
 *     specified location is on the list
 *
 * parameters: loc- a location object passed by reference
 *
 * return values: Returns true
 *     if the location is on the list else
 *     it returns false
 */
bool LocationStack::isOn(const Location &loc) const {
    LocationStackNode *current = this->top;
    while(current != nullptr){
        if(current->getLocation() == loc){
            return true;
        }
        current = current->getNextNode();
    }
    return false;
}

/*
 * ostream <<
 *
 * This function prints out the stack from
 *    top to bottom by passing over the stack twice
 *    and reversing the node links each time
 *
 * parameters: ostream- used to stream out the LocationStack
 *             s- location stack object
 *
 * return values: returns the ostream which is the list
 *     printed out from top to bottom
 */
ostream &operator<<(ostream &os, const LocationStack &s) {
    LocationStackNode *current = s.top;
    LocationStackNode *next = nullptr;
    LocationStackNode *prev = nullptr;

    while (current != nullptr) {
        next = current->getNextNode();
        current->setNextNode(prev);
        prev = current;
        current = next;
    }

    current = prev;
    prev = nullptr;

    while (current != nullptr) {
        os << current->getLocation() << endl;
        next = current->getNextNode();
        current->setNextNode(prev);
        prev = current;
        current = next;
    }

    return os;
}



