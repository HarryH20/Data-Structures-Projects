/* CSI 3334
 * Project 4 - AVL-Balanced Encryption
 * Filename: driver-proj4.cpp
 * Student Name: Harrison Hassler
 * Due Date: October 27, 2023
 * Description: This file is a program
 *              that implements encryption and decryption
 *              using word substitutions.
 */

#include <iostream>
#include <sstream>
#include <string>
#include "avl-tree-student-proj4.h"
using namespace std;

/*
 * main
 *
 * This function implements encryption and
 * decryption using word substitutions. The
 * codebook for this substitution cipher is
 * an AVL-Balanced binary search tree of words. The tree stores
 * all possible words that can be encrypted or decrypted.
 * The program uses a loop to read in each line. The istringstream
 * parses the line to a word and a command. Based on what the
 * command is the word is either inserted, removed, encrypted or decrypted.
 * The command p is used to print out the AVL-Balanced binary search tree in pre-order
 * format and l is used for level order. When q is pressed the function is ended.
 *
 * Parameters:
 *   None
 *
 * Return value: 0 if successful run
 */
int main() {
    string input;
    string command;
    string word;
    EncryptionTree<string> tree;
    while(command != "q") {
        getline(cin, input);
        istringstream line(input);
        line >> command;
        line >> word;
        if(command == "i"){
            tree.insert(word);
        }
        else if(command == "r"){
            tree.remove(word);
        }
        else if(command == "e"){
            if(word.back()  == '\'' ){
                word.erase(0, 1);
                word.pop_back();
                cout << tree.encrypt(word) << endl;
            }
            else {
                word.erase(0, 1);
                cout << tree.encrypt(word) << " ";

                while (line >> word) {
                    if (word.back() == '\'') {
                        word.pop_back();
                        cout << tree.encrypt(word) << endl;
                    } else {
                        cout << tree.encrypt(word) << " ";
                    }
                }
            }
        }
        else if(command == "d"){
            if(word.back()  == '\'' ){
                word.erase(0,1);
                word.pop_back();
                if(tree.decrypt(word) != nullptr){
                    cout << *tree.decrypt(word) << endl;
                }
                else{
                    cout << "?" << endl;
                }
            }
            else {
                word.erase(0, 1);
                if (tree.decrypt(word) != nullptr) {
                    cout << *tree.decrypt(word);
                } else {
                    cout << "?";
                }

                while (line >> word) {
                    if (word.back() != '\'') {
                        if (tree.decrypt(word) != nullptr) {
                            cout << " " << *tree.decrypt(word);
                        } else {
                            cout << " ?";
                        }
                    } else {
                        word.pop_back();
                        if (tree.decrypt(word) != nullptr) {
                            cout << " " << *tree.decrypt(word) << endl;
                        } else {
                            cout << " ?" << endl;
                        }
                    }
                }
            }
        }
        else if(command == "p"){
            tree.printPreorder();
        }
        else if(command == "l"){
            tree.printLevelOrder();
        }
    }

    return 0;
}
