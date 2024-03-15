/* CSI 3334
 * Project 2 -- WordMelt
 * Filename: location-proj2.cpp
 * Student name: Harrison Hassler
 * Due Date: Sept 15, 2023
 * Description: This file implements the functions in
 *     location-proj2.h
 */


#include "location-proj2.h"


Location::Location() {
    indexToChange = 0;
    iterationMode = CHANGE_LETTER;
    nextLetter = 'a';
    word = "";

}


void Location::iterationBegin(void) {
    indexToChange = 0;
    iterationMode = CHANGE_LETTER;
    nextLetter = 'a';
    if(nextLetter == word[indexToChange]){
        nextLetter++;
    }
}

void Location::iterationAdvance(void) {
    if(iterationMode == CHANGE_LETTER){
        if(nextLetter != 'z') {
            nextLetter++;
            if(word[indexToChange] == nextLetter && nextLetter != 'z'){
                nextLetter++;
            }
            else if(word[indexToChange] == nextLetter && nextLetter == 'z'){
                indexToChange++;
                nextLetter = 'a';
            }
        }
        else if(nextLetter =='z'){
            indexToChange++;
            nextLetter = 'a';
        }


        if(indexToChange >= word.length() ){
            iterationMode++;
            indexToChange = 0;
        }

    }

    else if(iterationMode == INSERT_LETTER ){
        if(nextLetter != 'z'){
            nextLetter++;
        }
        else if(nextLetter == 'z'){
            indexToChange++;
            nextLetter = 'a';
        }
        if(indexToChange >= word.length() + 1){
            iterationMode++;
            indexToChange = 0;
        }

    }

    else if(iterationMode == DELETE_LETTER){
        if(indexToChange >= word.length()-1 ){
            iterationMode++;
        }
        indexToChange++;
    }

}

bool Location::iterationDone(void) const {
    return iterationMode == DONE;
}

Location Location::iterationCurrent(void) const {
    Location neighbor = *this;
    if(iterationMode == CHANGE_LETTER){
        neighbor.word[indexToChange] = nextLetter;
    }
    else if(iterationMode == INSERT_LETTER){
        neighbor.word.insert(indexToChange, 1, nextLetter);

    }
    else if(iterationMode == DELETE_LETTER){
        neighbor.word.erase(indexToChange, 1);
    }
    return neighbor;

}

ostream &operator<<(ostream &os, const Location &loc){
    os << loc.word;
    return os;

}

istream &operator>>(istream &is, Location &loc){
    is >> loc.word;
    return is;

}

bool Location::operator<(const Location &loc) const{
    return word < loc.word;
}


bool Location::operator==(const Location &loc) const {
    return word == loc.word;
}





