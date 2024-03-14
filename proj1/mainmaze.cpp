/* CSI 3334
 * Project 1 -- Maze
 * Filename: mainmaze.cpp
 * Student name: Harrison Hassler
 * Due Date: Sept 8, 2023
 * Description: This file tests the functions in
 *     maze-proj1.cpp
 */




/*#include <iostream>
#include "maze-proj1.h"
#include <sstream>
using namespace std;


    int main() {
        Maze maze;

        //Testing istream
        string input = "4\n 0 0\n 0 1\n 0 2\n 1 2\n 0 0\n 1 2\n";
        istringstream  is(input);
        is >> maze;

        //Testing getStartLocation
        cout << "Start Location: " << maze.getStartLocation() << endl;
        cout << "Should be 0 0" << endl;

        //Testing is isValidLocation
        Location loc;
        string input2 = "1 2";
        is.clear();
        is.str(input2);
        is >> loc;

        //Should be a part of the maze
        if(maze.isValidLocation(loc)){
            cout << "Is a part of the maze" << endl;
        }

        is.clear();
        input2 = "1 1";
        is.str(input2);
        is >> loc;

        //Should not be a part of the maze
        if(!maze.isValidLocation(loc)){
            cout << "Is not a part of the maze" << endl;
        }

        //Testing isEndLocation
        //Should not be end location
        if(!maze.isEndLocation(loc)){
            cout << "Is not end location" << endl;
        }

        is.clear();
        input2 = "1 2";
        is.str(input2);
        is >> loc;

        //Should be end location
        if(maze.isEndLocation(loc)){
            cout << "Is end location" << endl;
        }
        is.clear();

        //Testing default
        Maze maze2;
        cout << maze2.getStartLocation() << endl;






        return 0;
    }


*/
