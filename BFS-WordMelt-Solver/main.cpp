/* CSI 3334
 * Project 2 -- WordMelt
 * Filename: main.cpp
 * Student name: Harrison Hassler
 * Due Date: Sept 15, 2023
 * Description: This file tests the functions
 */



/*#include <iostream>
#include <cassert>
#include <sstream>
#include "location-proj2.h"
#include "maze-proj2.h"
#include "arrayqueue-student-proj2.h"
using namespace std;
int main() {
    Location loc1;
    Location loc2;

    //Tests default constructor
    //Tests == operator
    //Tests >> operator
    string input = "";
    istringstream iss(input);
    iss>> loc2;
    iss.clear();
    assert(loc1 == loc2);

    //Testing iterationBegin
    //Testing iterationCurrent
    //Testing << operator
    input = "hello";
    iss.str(input);
    iss >> loc2;
    iss.clear();
    loc2.iterationBegin();
    cout << loc2.iterationCurrent();
    cout << endl;
    cout << "Should be aello" <<endl;

    //Testing special case with iterationBegin
    input = "aello";
    iss.str(input);
    iss >> loc2;
    iss.clear();
    loc2.iterationBegin();
    cout << loc2.iterationCurrent();
    cout << endl;
    cout << "Should be bello" <<endl;



    //Testing iteration advance
    //Testing iterationDone
    input = "zzzz";
    iss.str(input);
    iss >> loc2;
    iss.clear();
    loc2.iterationBegin();

    while(!loc2.iterationDone()){
        cout << loc2.iterationCurrent() << endl;
        loc2.iterationAdvance();
    }

    //Testing < operator
    assert(loc1 < loc2);

    //Testing Maze Class;
    //Testing >> operator
    Maze maze1;
    input = "4 bye hello new yolo bye yolo";
    iss.str(input);
    iss >> maze1;
    iss.clear();
    //Testing getStartLocation
    cout << maze1.getStartLocation() << endl;

    //Testing isValidLocation
    if(maze1.isValidLocation(loc2)){
        cout << "True" << endl;
    }

    //Testing isEndLocation
    iss.clear();
    input = "yolo";
    iss.str(input);
    iss >> loc2;
    if(maze1.isEndLocation(loc2)){
        cout << "True" << endl;
    }

    //Testing arrayqueue
    //Testing default constructor
    ArrayQueue<int> queue1;
    cout << queue1.getLength() << endl;

    //Testing add
    ArrayQueue<int> queue2;
    queue2.add(1);
    queue2.add(2);
    queue2.add(3);

    //Testing getFront
    cout << queue2.getFront() << endl;

    //Testing getLength and remove
    cout << queue2.getLength() << endl;
    queue2.remove();
    cout << queue2.getLength() << endl;
    queue2.remove();
    cout << queue2.getLength() << endl;
    queue2.remove();
    cout << queue2.getLength() << endl;

    queue2.add(1);
    queue2.add(2);
    queue2.add(3);

    //Testing copy constructor
    ArrayQueue<int> copy(queue2);
    cout << copy.getLength() << endl;
    cout << copy.getFront() << endl;

    //Testing == operator
    queue1 = copy;
    cout << queue1.getLength() << endl;
    cout << queue1.getFront() << endl;







    return 0;
}
*/