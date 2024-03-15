#include "maze-proj2.h"
#include "arrayqueue-student-proj2.h"
#include <iostream>
#include <map>
#include <stack>
using namespace std;
int main(){
    Maze maze1;
    Location neighbor;
    ArrayQueue<Location> locQ;
    map<Location, Location> locMap, pathMap;
    cin >> maze1;

    Location m = maze1.getStartLocation();
    locQ.add(m);
    locMap[m] = m;

    while(!maze1.isEndLocation(neighbor) && locQ.getLength() > 0){
        m = locQ.getFront();
        locQ.remove();
        m.iterationBegin();
        while(!m.iterationDone() && !maze1.isEndLocation(neighbor)){
            neighbor = m.iterationCurrent();
            if(maze1.isValidLocation(neighbor) && locMap.find(neighbor) == locMap.end()){
                locQ.add(neighbor);
                locMap[neighbor] = m;
            }
            m.iterationAdvance();
        }

    }

    stack<Location> locStack;
    if(maze1.isEndLocation(neighbor)){
        locMap[neighbor] = m;
        while(!(neighbor == maze1.getStartLocation())){
            locStack.push(neighbor);
            neighbor = locMap[neighbor];
        }
        locStack.push(neighbor);

        cout << "Solution found" << endl;
        while(!locStack.empty()) {
            cout << locStack.top() << endl;
            locStack.pop();
        }


    }
    else{
    cout << "No solution" << endl;
    }
    return 0;
}

