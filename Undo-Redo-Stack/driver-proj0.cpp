/* CSI 3334
 * Project 0 -- Undo Redo
 * Filename: driver-proj0.cpp
 * Student name: Harrison Hassler
 * Due Date: August 25, 2023
 * Description: This file makes use of an undo
 *     and redo function while writing text.
 */
#include <iostream>
#include <string>
#include <stack>
#include <cassert>
#include <cctype>

using namespace std;

/*
 * lineNumber
 *
 * This function tests to see if
 *     the number of lines that the
 *     user entered is between
 *     1 and 1000.
 *
 * parameters: userLines which is the number
 *     of lines that the user enters.
 *
 * return values: checks to see if the number
 *     of lines is between 1 and 1000.
 */
bool lineNumber(int userLines){
    const int MIN_LINES = 1;
    const int MAX_LINES = 1000;
    return( userLines >= MIN_LINES && userLines <= MAX_LINES);
}

/*
 * correctCommand
 *
 * This function tests to see if
 *     the user enters u,t,or r
 *     which are the only commands used.
 *
 * parameters: a which is the command
 *     that the user enters.
 *
 * return values: returns if the user
 *     enters an acceptable command.
 */
bool correctCommand (char a){
    return(a == 't' || a == 'u' || a == 'r' );
}

/*
 * wordLength
 *
 * This function tests to see if
 *     the user enters a word between 1 and 10
 *     characters long.
 *
 * parameters: &words which is a reference to the
 *     original string the user enters.
 *
 * return values: returns if the string is the correct length.
 */
bool wordLength(const string &words) {
    const int MIN_LENGTH = 1;
    const int MAX_LENGTH = 10;
    return (words.length() >= MIN_LENGTH && words.length() <= MAX_LENGTH);
}

/*
 * correctWords
 *
 * This function tests to see if
 *     the users string is all letters
 *     by looping through the string and
 *     comparing each character in the array.
 *
 * parameters: &words which is a reference to
 *     the original string the user enters.
 *
 * return values: checks if the string is all letters (a-z).
 */
bool correctWords(const string &words){
    for(int i = 0; i < words.size(); i++){
        char letter = words[i];
        if( !isalpha(letter)){
            return false;
        }
    }
    return true;
}

/*
 * reverseStack
 *
 * This function reverses the stack
 *     to print it out correctly by placing the
 *     contents in a temporary stack then setting
 *     it equal to the original.
 *
 * parameters: *original which points to the original stack
 *     the program is making from user input.
 *
 * return values: No value is returned but the stack
 *     is reversed.
 */
void reverseStack(stack<string> *original){
    stack<string> temp;
    while(!original->empty()){
        temp.push(original->top());
        original->pop();

    }
    *original = temp;
}

/*
 * printStack
 *
 * This function prints the contents
 *     of the stack out.
 *
 * parameters: *original which points to the original stack
 *     the program is making from user input.
 *
 * return values: No value is returned but the stack
 *     is printed out.
 */
void printStack(stack<string> *original){
    while (!original->empty()) {
        cout << original->top();
        original->pop();
        if(!original->empty()){
            cout << " ";
        }
    }
    cout << endl;
}
/*
 * main
 *
 * This function takes user input as the
 *     number of commands the user enters.
 *     Then takes user input as a command that
 *     either adds text, undos text, or redos text
 *     until all the commands are entered. The function
 *     takes the users text and prints out the typing stack
 *     and the undo stack at the end.
 *
 * parameters: none
 *
 * return values: return 0 if the function
 *     runs successfully.
 */
int main() {
    stack<string> typing, undo;
    char input;
    string words;
    int lineNum;
    int commandCount = 0;

    //Input
    cin >> lineNum;
    assert(lineNumber(lineNum));

    //Loops through until all the commands are entered
    for (int i = 0; i < lineNum; i++) {
        cin >> input;
        commandCount++;
        assert (correctCommand(input));
        if (input == 't') {
            cin >> words;
            assert (wordLength(words) && correctWords(words));
            typing.push(words);
        }
            //If u is entered the top of the typing
            //stack is pushed onto the undo stack
        else if (input == 'u') {
            if (!typing.empty()) {
                undo.push(typing.top());
                typing.pop();
            } else {
                cout << "nothing to undo on command " << commandCount << endl;
            }
        }
            //If r is entered the top of the undo stack
            //is pushed onto the typing stack
        else if (input == 'r') {
            if (!undo.empty()) {
                typing.push(undo.top());
                undo.pop();
            } else {
                cout << "nothing to redo on command " << commandCount << endl;
            }
        }

    }

    reverseStack(&typing);
    reverseStack(&undo);

    //Output
    printStack(&typing);
    printStack(&undo);

    return 0;
}
