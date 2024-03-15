/* CSI 3334
 * Project 5 - Real-Time Batch Operating System Simulator
 * Filename: driver-proj5.cpp
 * Student Name: Harrison Hassler
 * Due Date: 11/9/2023
 * Description: This file implement a program
 *              which simulates a batch operating system
 *              with real-time guarantees about when
 *              processes will finish.
 */


#include "arrayheap-student-proj5.h"
#include "process-proj5.h"
using namespace std;

/*
 * main()
 *
 * This function implements a program that simulates a batch
 * operating system. This uses a while loop to read all the processes
 * then uses a second while loop to only insert into the heap until the
 * submission time has been reached or passed. If there is something
 * in the heap and the submission time has not been reached the program
 * either runs or skips the highest priority item in the heap.
 *
 *
 * Parameters: none
 *
 * Return value: return 0 is successful
 */
int main(){
    int n;
    int time = 0;
    int numRun = 0;
    int numSkip = 0;
    int procId = 0;
    Process *proc = new Process();
    ArrayHeap<Process> procHeap;
    cin >> n;
    cin >> *proc;
    int readIn = n;
    // Loops over total number of processes
    while(n > 0){
        // only inserts when submission time has been reached
        // or there is nothing left to read in
        while(proc->getSubmissionTime() <= time && readIn > 0){
            procHeap.insert(*proc);
            readIn--;
            procId++;
            delete proc;
            // reads one ahead to get submission time
            proc = new Process(procId);
            if(readIn > 0){
                cin >> *proc;
            }


        }
        // If there are no processes on the heap it
        // moves the clock forward
        if(procHeap.getNumItems() == 0){
            ++time;
        }
        //Removes highest priority item and either skips or runs it
        else{
            Process curr = procHeap.getMinItem();
            procHeap.removeMinItem();
            n--;
            if(curr.canComplete(time)){
                time = curr.run(time);
                numRun++;
            }
            else{
                cout << "skipping process id " << curr.getId() << " at " << time << endl;
                numSkip++;
                time++;
            }
        }


    }
    delete proc;
    cout << "final clock is                 " << time << endl;
    cout << "number of processes run is     " << numRun << endl;
    cout << "number of processes skipped is " << numSkip << endl;
    return 0;

}
