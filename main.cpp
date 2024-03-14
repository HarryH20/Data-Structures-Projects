/* CSI 3334
 * Project 1 -- Maze
 * Filename: main.cpp
 * Student name: Harrison Hassler
 * Due Date: Sept 8, 2023
 * Description: This file tests the functions in
 *     location-proj1.cpp, maze-proj1.cpp, and stack-proj1.cpp
 */
/* Mazes
 * 4
 * 0,2
 * 1,1
 * 2,1
 * 2,2
 * 2,1
 * 0,1
 *
 * 5
 * 0,1
 * 0,2
 * 1,0
 * 1,2
 * 2,1
 * 0,0
 * 2,2
 *
 * 1
 * 0,1
 * 0,0
 * 1,1
 *
 * 6
 * 0,1
 * 1,1
 * 2,1
 * 2,3
 * 1,3
 * 0,4
 * 2,2
 * 0,3
 *
 * 8
 * 1,0
 * 0,1
 * 0,2
 * 1,2
 * 2,2
 * 3,2
 * 3,1
 * 4,1
 * 1,1
 * 5,1
 *
 * 1
 * 0,1
 * 0,1
 * 0,1
 *
 * 8
 * 0,0
 * 0,1
 * 0,2
 * 1,0
 * 1,2
 * 2,0
 * 2,1
 * 3,0
 * 0,1
 * 3,2
 *
 * 0
 * 0,0
 * 1,1
 *
 * 4
 * 0,0
 * 1,0
 * 1,1
 * 1,2
 * 0,1
 * 0,3
 *
 * 0
 * 0,0
 * 0,1
 *
 */
/*#include <iostream>
#include "location-proj1.h"
#include "maze-proj1.h"
#include "stack-proj1.h"
#include <sstream>
using namespace std;
int main() {
    //Testing constructor

    //Should initialize row and
    //    column to 00
    Location loc;

    loc.iterationBegin();

    //Testing streaming location object out
    //    should print out 00
    cout << loc;
    cout << endl;

    //Should print out all the neighbors of 00
    for (loc.iterationBegin(); !loc.iterationDone(); loc.iterationAdvance()) {
        Location neighbor = loc.iterationCurrent();
        cout << neighbor << endl;
    }
    cout << endl;

    //Testing >> operator
    Location loc2;
    string input = "0 0";
    istringstream iss(input);
    iss >> loc2;
    iss.clear();
    cout << loc2;
    cout << endl;

    //Testing == operator
    if(loc == loc2){
        cout << "Overloading == operator works" << endl;
    }

    //Testing neighbors of 89
    Location loc3;
    input = "8 9";
    iss.str(input);
    iss >> loc3;
    cout << loc3;
    cout << endl;

    //Should print out all the neighbors of 89
    for (loc3.iterationBegin(); !loc3.iterationDone(); loc3.iterationAdvance()) {
        Location neighbor = loc3.iterationCurrent();
        cout << neighbor << endl;
    }
    cout << endl;




    //TESTING MAZE CLASS





    Maze maze;

    //Testing istream
    string input2 = "4\n 0 0\n 0 1\n 0 2\n 1 2\n 0 0\n 1 2\n";
    istringstream  is(input2);
    is >> maze;

    //Testing getStartLocation
    cout << "Start Location: " << maze.getStartLocation() << endl;
    cout << "Should be 0 0" << endl;

    //Testing is isValidLocation
    Location loc1;
    string input3 = "1 2";
    is.clear();
    is.str(input3);
    is >> loc;

    //Should be a part of the maze
    if(maze.isValidLocation(loc1)){
        cout << "Is a part of the maze" << endl;
    }

    is.clear();
    input3 = "1 1";
    is.str(input3);
    is >> loc1;

    //Should not be a part of the maze
    if(!maze.isValidLocation(loc1)){
        cout << "Is not a part of the maze" << endl;
    }

    //Testing isEndLocation
    //Should not be end location
    if(!maze.isEndLocation(loc1)){
        cout << "Is not end location" << endl;
    }

    is.clear();
    input3 = "1 2";
    is.str(input3);
    is >> loc1;

    //Should be end location
    if(maze.isEndLocation(loc1)){
        cout << "Is end location" << endl;
    }
    is.clear();

    //Testing default
    Maze maze2;
    cout << maze2.getStartLocation() << endl;


    //TESTING LOCATIONSTACK CLASS

    LocationStack stack;
    Location locstack1;
    Location locstack2;
    string inputLoc1 = "0 1";
    string inputLoc2 = "2 2";
    is.str(inputLoc1);
    is >> locstack1;
    is.clear();
    is.str(inputLoc2);
    is >> locstack2;

    stack.push(locstack1);
    cout << stack.getTop() << endl;
    stack.push(locstack2);
    cout << stack.getTop() << endl;
    cout << stack;
    stack.pop();
    cout << stack.getTop() << endl;
    if(stack.isOn(locstack1)){
        cout << "is on" << endl;
    }
    stack.pop();
    if(stack.isEmpty()){
        cout << "Is empty" << endl;
    }









    return 0;
}
*/