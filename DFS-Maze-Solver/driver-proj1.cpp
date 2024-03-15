/* CSI 3334
 * Project 1 -- Maze
 * Filename: driver-proj1.cpp
 * Student name: Harrison Hassler
 * Due Date: Sept 8, 2023
 * Description: This program searches through a maze
 *     using depth first search and prints
 *     the path out from start to end based on
 *     the maze the user makes
 */

#include <iostream>
#include "stack-proj1.h"
#include "maze-proj1.h"


/*
 * Main
 *
 * This function takes user input to a maze
 *     and uses a while loop to loop through different
 *     locations by popping and pushing values onto the stack
 *     until the end location is found or no solution is found.
 *     The program then prints the stack from bottom to top.
 *
 * parameters: None
 *
 * return values: Return 0 if successful
 */
int main() {
    Maze maze;
    Location m;
    Location neighbor;
    LocationStack stack;

    bool noSolution = false;

    //Gets input for the maze
    // and sets the start location and begins
    // iteration
    cin >> maze;

    m = maze.getStartLocation();
    m.iterationBegin();
    stack.push(m);

    while(!noSolution && !maze.isEndLocation(stack.getTop())){
        m = stack.getTop();
        stack.pop();

        //Gets its neighbor and updates nextDirection
        //If the iteration is done it pops it off the stack and
        //    backtracks
        if(!m.iterationDone()){
            neighbor = m.iterationCurrent();
            m.iterationAdvance();
            neighbor.iterationBegin();
            stack.push(m);

            //Checks validity of neighbor and
            //    if its valid pushes it onto the stack
            if(maze.isValidLocation(neighbor) && !stack.isOn(neighbor) ){
                stack.push(neighbor);
            }

        }
        if(stack.isEmpty()){
            noSolution = true;
        }


    }
    //Output
    if(noSolution){
        cout << "No solution" << endl;
    }
    else{
        cout << "Solution found" << endl;
        cout << stack;
    }
    return 0;



}

