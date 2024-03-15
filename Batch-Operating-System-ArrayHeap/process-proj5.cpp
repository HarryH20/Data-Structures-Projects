/* CSI 3334
 * Project 5 - Real-Time Batch Operating System Simulator
 * Filename: process-proj5.cpp
 * Student Name: Harrison Hassler
 * Due Date: 11/9/2023
 * Description: This file implements the functions in
 *    process-proj5.h
 */


#include "process-proj5.h"

/*
 * Process
 *
 * This is the default constructor for the process class
 * it initializes all of the data members to reasonable defaults.
 *
 * Parameters:
 *   theId: the unique id of each process created
 *
 * Return value: none
 */
Process::Process(int theId) {
    this->id = theId;
    this->submissionTime = 0;
    this->deadline = 0;
    this->requiredTime = 0;
    this->information = "";

}

/*
 * run
 *
 * This method prints out the information contained in this process,
 * and then returns the system time plus the required time
 * (which is the new system time).
 *
 * Parameters:
 *   currentSystemTime: the current system time
 *
 * Return value: returns the new system time
 */
int Process::run(int currentSystemTime) const {
    cout << "running process id " << this->id << " at " << currentSystemTime;
    cout << endl << information << endl;

    return currentSystemTime + requiredTime;
}

/*
 * canComplete
 *
 * The canComplete method returns true if the method
 * would be able to complete if it starts now,
 * or false if it could not finish by its deadline.
 *
 * Parameters:
 *   currentSystemTime: the current system time
 *
 * Return value: returns true if it can complete the
 *               process
 */
bool Process::canComplete(int currentSystemTime) const {
    return (currentSystemTime + requiredTime <= deadline);
}

/*
 * getId
 *
 * The getId method returns the id of the process object.
 *
 * Parameters: none
 *
 * Return value: returns the id
 */
int Process::getId() const {
    return this->id;
}

/*
 * getSubmissionTime
 *
 * The getSubmissionTime method returns the submission time
 *
 * Parameters: none
 *
 * Return value: returns the submission time
 */
int Process::getSubmissionTime() const {
    return this->submissionTime;
}

/*
 * operator <
 *
 * The operator < method is used to order processes by
 * their deadline then required time then id.
 *
 * Parameters: p: process object to be compared
 *
 * Return value: The operator< method returns true
 *                if (*this) < p, false otherwise.
 */
bool Process::operator<(const Process &p) const {
    if(this->deadline < p.deadline){
        return true;
    }
    if(this->deadline == p.deadline){
        if(this->requiredTime < p.requiredTime){
            return true;
        }
    }
    if(this->deadline == p.deadline && this->requiredTime == p.requiredTime){
        if(this->id < p.id){
            return true;
        }

    }
    return false;

}

/*
 * operator >>
 *
 * The operator>> method is used to read in the submissionTime, deadline,
 * requiredTime, and information from an istream.
 *
 * Parameters: p: process object
 *             is: istream used to stream in the objects information
 *
 * Return value: is: the istream
 */
istream &operator>>(istream &is, Process &p){
    is >> p.submissionTime >> p.deadline >> p.requiredTime;
    getline(is >> ws, p.information);
    return is;
}