/* CSI 3334
 * Project 3 -- Tree Based Encryption
 * Filename: bst-student-proj3.h
 * Student name: Harrison Hassler
 * Due Date: October 6, 2023
 * Description: This file implements the functions in
 *     bst-prof-proj3.h
 */


#ifndef BST_STUDENT_PROJ3
#define BST_STUDENT_PROJ3
#include "bst-prof-proj3.h"

/*
 * printPreorder
 *
 * This function traverses the node and its children
 * recursively in printPreorder and prints each node it
 * visits to the ostream.
 *
 * Parameters:
 *   os: the given ostream
 *   indent: the 2 space indent used to show each
 *   level of the tree
 *
 * Return value: None
 */
template <class Base>
void BSTNode<Base>::printPreorder(ostream &os, string indent) const {
    os << indent << this->data << endl;
    if(this->left != nullptr){
        this->left->printPreorder(os, indent + "  ");
    }
    else{
        os << indent << "  NULL" << endl;
    }
    if(this->right != nullptr){
        this->right->printPreorder(os, indent + "  ");
        
    }
    else{
        os << indent << "  NULL" << endl;
    }


}

/*
 * minNode
 *
 * This function recursively uses the minNode
 * function to find the leftMost node at or below
 * the node called on.
 *
 * Parameters:
 *   None
 *
 * Return value:
 *   this->left->minNode: Returns the leftMost node
 */
template <class Base>
const BSTNode<Base> *BSTNode<Base>::minNode() const {
    if(this->left == nullptr){
        return this;
    }
    else {
        return this->left->minNode();
    }

}

/*
 * maxNode
 *
 * This function recursively uses the maxNode
 * function to find the rightMost node at or below
 * the node called on.
 *
 * Parameters:
 *   None
 *
 * Return value:
 *   this->right->maxNode: Returns the rightMost node
 */
template <class Base>
const BSTNode <Base> *BSTNode<Base>::maxNode() const {
    if(this->right == nullptr){
        return this;
    }
    else {
        return this->right->maxNode();
    }
}

/*
 * ~BSTNode
 *
 * This function is the destructor for the
 * BSTNode class and it recursively deletes the
 * left and right subtrees.
 *
 * Parameters:
 *   None
 *
 * Return value: None
 */
template <class Base>
BSTNode<Base>::~BSTNode(){
    delete this->left;
    delete this->right;
    this->right = nullptr;
    this->left = nullptr;

}

/*
 * insert
 *
 * This function inserts an item into the
 * tree unless the item is already in the tree.
 * The function does this by comparing the item
 * to each node in the tree until a spot is found.
 *
 * Parameters:
 *   item: the base that is inserted into the tree.
 *
 * Return value: None
 */
template <class Base>
void BST<Base>::insert(const Base &item) {
    bool flag = true;
    if (this->root == nullptr) {
        this->root = new BSTNode<Base>(item);
    }
    else {
        BSTNode<Base> *current = this->root;
        while (flag) {
            if (item < current->data) {
                if (current->left == nullptr) {
                    current->left = new BSTNode<Base>(item);
                    flag = false;
                }
                else {
                    current = current->left;
                }
            } else if (current->data < item) {
                if (current->right == nullptr) {
                    current->right = new BSTNode<Base>(item);
                    flag = false;
                }
                else {
                    current = current->right;
                }
            } else {
                flag = false;
            }
        }
    }
}

/*
 * remove
 *
 * This function removes the item in the tree if
 * it is in the tree. The remove function does this by
 * first searching for the item in the tree. If the
 * item is found the item is removed in 3 different ways
 * based on the number of children it has. If the root is null
 * nothing is removed.
 *
 * Parameters:
 *   item: the base that is to be removed from the tree.
 *
 * Return value: None
 */
template <class Base>
void BST<Base>::remove(const Base &item) {
    BSTNode<Base> *toRemove = this->root;
    BSTNode<Base> *parent = nullptr;
    bool isFound = false;
    while (!isFound && toRemove != nullptr) {
        if (item < toRemove->data) {
            parent = toRemove;
            toRemove = toRemove->left;

        }
        else if (toRemove->data < item) {
            parent = toRemove;
            toRemove = toRemove->right;
        }
        else {
            isFound = true;
            }
    }

    if (isFound) {
        if (toRemove->right != nullptr && toRemove->left != nullptr) {
            BSTNode<Base> *leftMost = toRemove->right;
            BSTNode<Base> *leftMostParent = toRemove;
            if (leftMost->left != nullptr) {
                while (leftMost->left != nullptr) {
                    leftMostParent = leftMost;
                    leftMost = leftMost->left;
                }
                leftMostParent->left = leftMost->right;
                leftMost->right = toRemove->right;
            }
            leftMost->left = toRemove->left;
            if(parent != nullptr) {
                if (parent->left == toRemove) {
                    parent->left = leftMost;
                } else {
                    parent->right = leftMost;
                }
            }
            else{
                this->root = leftMost;
            }
            toRemove->left = nullptr;
            toRemove->right = nullptr;
            leftMostParent = nullptr;
            delete toRemove;
        }
        else if (toRemove->left != nullptr || toRemove->right != nullptr) {
            BSTNode<Base> *child = nullptr;
            if (toRemove->left != nullptr) {
                child = toRemove->left;
                toRemove->left = nullptr;
                }
            else {
                child = toRemove->right;
                toRemove->right = nullptr;
            }
            if(parent != nullptr) {
                if (parent->left == toRemove) {
                    parent->left = child;
                } else {
                    parent->right = child;
                }
            }
            else{
                this->root = child;
            }
            delete toRemove;
        }
        else {
            if(parent != nullptr) {
                if (parent->left == toRemove) {
                    parent->left = nullptr;
                }
                else {
                    parent->right = nullptr;
                }

            }
            delete toRemove;
            if(parent == nullptr) {
                this->root = nullptr;
            }

        }
    }
}

/*
 * encrypt
 *
 * This function takes an object to be encrypted
 * and returns the encrypted string. If the object to
 * be encrypted is not in the dictionary it returns a ?.
 * The function does this by searching for the item and
 * adding a 0 or 1 based on where it is in the tree.
 *
 * Parameters:
 *   item: the base that is to be encrypted.
 *
 * Return value:
 *   r: the encrypted string
 */
template <class Base>
string EncryptionTree<Base>::encrypt(const Base &item) const {
    string r = "r";
    const BSTNode<Base> *current = this->root;
    bool encrypt = false;
    while(current != nullptr){
        if(item < current->getData()){
            r += '0';
            current = current->getLeft();
        }
        else if(current->getData() < item){
            r += '1';
            current = current->getRight();
        }
        else{
            current = nullptr;
            encrypt = true;

        }
    }

    if(!encrypt){
        r = "?";
    }
    return r;


}

/*
 * decrypt
 *
 * This function takes an encrypted string and decrypts
 * it. It does this by searching for the string in the tree
 * based on the 0's and 1's in the encrypted string to find
 * the word. It returns a pointer to the base for
 * the given path or nullptr if the path is invalid.
 *
 *
 * Parameters:
 *   path: the string to be decrypted
 *
 * Return value:
 *   &current->getData: a pointer to a base
 */
template <class Base>
const Base* EncryptionTree<Base>::decrypt(const string &path) const {
    const BSTNode<Base> *current = this->root;
    if(this->root == nullptr){
        return nullptr;
    }
    else if(path == "r"){
        return &current->getData();
    }
    else if(path != "r"){
        for(int i = 1; i < path.length(); i++){
            if(path[i] == '0'){
                if(current->getLeft() != nullptr) {
                    current = current->getLeft();
                }
                else{
                    return nullptr;
                }
            }
            else {
                if(current->getRight() != nullptr) {
                    current = current->getRight();
                }
                else{
                    return nullptr;
                }
            }

        }
    }
    return &current->getData();
}

#endif
