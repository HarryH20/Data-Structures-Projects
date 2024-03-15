/* CSI 3334
 * Project 4 - AVL-Balanced Encryption
 * Filename: avl-tree-student-proj4.h
 * Student Name: Harrison Hassler
 * Due Date: October 27, 2023
 * Description: This file implements the functions in
 *     avl-tree-prof-proj4.h
 */


#ifndef AVL_TREE_STUDENT_PROJ4
#define AVL_TREE_STUDENT_PROJ4

#include "avl-tree-prof-proj4.h"
#include <queue>


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
const AVLNode<Base> *AVLNode<Base>::minNode() const {
    if(this->left == nullptr){
        return this;
    }
    else{
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
const AVLNode<Base> *AVLNode<Base>::maxNode() const {
    if(this->right == nullptr){
        return this;
    }
    else{
        return this->right->maxNode();
    }
}

/*
 * ~AVLNode
 *
 * This function is the destructor for the
 * AVLNode class and it recursively deletes the
 * left and right subtrees.
 *
 * Parameters:
 *   None
 *
 * Return value: None
 */
template <class Base>
AVLNode<Base>::~AVLNode(){
    delete this->left;
    delete this->right;
    this->left = nullptr;
    this->right = nullptr;
}

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
void AVLNode<Base>::printPreorder(ostream &os, string indent) const {
    os << indent <<  this->data << endl;
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
 * singleRotateRight
 *
 * This function does a single right rotation on
 * the node it is called on and updates the heights
 * of the nodes along the path.
 *
 * Parameters:
 *   None
 *
 * Return value: leftChild: a pointer to the node that takes its place
 */
template <class Base>
 AVLNode<Base> *AVLNode<Base>::singleRotateRight() {
    AVLNode<Base> *leftChild = this->left;
    this->left = leftChild->right;
    leftChild->right = this;
    this->updateHeight();
    leftChild->updateHeight();
    return leftChild;

}

/*
 * singleRotateLeft
 *
 * This function does a single left rotation on
 * the node it is called on and updates the heights
 * of the nodes along the path.
 *
 * Parameters:
 *   None
 *
 * Return value: rightChild: a pointer to the node that takes its place
 */
template <class Base>
AVLNode<Base> *AVLNode<Base>::singleRotateLeft() {
    AVLNode<Base> *rightChild = this->right;
    this->right = rightChild->left;
    rightChild->left = this;
    this->updateHeight();
    rightChild->updateHeight();
    return rightChild;

}

/*
 * doubleRotateRightLeft
 *
 * This function does a single right rotation at the
 * right child of the node called on then a single
 * left rotation at the node. It updates the height of
 * the nodes along the path.
 *
 * Parameters:
 *   None
 *
 * Return value: this->singleRotateLeft(): a pointer to the node that takes its place
 */
template <class Base>
AVLNode<Base> *AVLNode<Base>::doubleRotateRightLeft() {
    this->right = this->right->singleRotateRight();
    return this->singleRotateLeft();
}

/*
 * doubleRotateLeftRight
 *
 * This function does a single left rotation at the
 * left child of the node called on then a single
 * right rotation at the node. It updates the height of
 * the nodes along the path.
 *
 * Parameters:
 *   None
 *
 * Return value: this->singleRotateRight(): a pointer to the node that takes its place
 */
template <class Base>
AVLNode<Base> *AVLNode<Base>::doubleRotateLeftRight() {
    this->left = this->left->singleRotateLeft();
    return this->singleRotateRight();
}

/*
 * insert
 *
 * This function inserts an item into the
 * tree unless the item is already in the tree.
 * The function does this by comparing the item
 * to each node in the tree along a path until
 * a spot is found. The tree is rebalanced when
 * necessary using a vector of pointers to AVLNode objects
 * that store the path the node is along and pass the path to
 * rebalancePathToRoot.
 *
 * Parameters:
 *   item: the base that is inserted into the tree.
 *
 * Return value: None
 */
template <class Base>
void AVLTree<Base>::insert(const Base &item) {
    bool flag = true;
    vector<AVLNode<Base>*> vector1;
    if(this->root == nullptr){
        this->root = new AVLNode<Base>(item);
    }
    else{
        AVLNode<Base> *current = this->root;
        while(flag) {
            vector1.push_back(current);
            if (item < current->data) {
                if (current->left == nullptr) {
                    current->left = new AVLNode<Base>(item);
                    vector1.push_back(current->left);
                    flag = false;
                }
                else{
                    current = current->left;
                }

            }
            else if(current->data < item){
                if(current->right == nullptr){
                    current->right = new AVLNode<Base>(item);
                    vector1.push_back(current->right);
                    flag = false;
                }
                else{
                    current = current->right;
                }

            }
            else{
                flag = false;
            }
        }
    }
    this->rebalancePathToRoot(vector1);


}

/*
 * remove
 *
 * This function removes the item in the tree if
 * it is in the tree. The remove function does this by
 * first searching for the item in the tree. If the
 * item is found the item is removed in 3 different ways
 * based on the number of children it has. If the root is null
 * nothing is removed. The tree is rebalanced when
 * necessary using a vector of pointers to AVLNode objects
 * that store the path the node is along and pass the path to
 * rebalancePathToRoot.
 *
 * Parameters:
 *   item: the base that is to be removed from the tree.
 *
 * Return value: None
 */
template <class Base>
void AVLTree<Base>::remove(const Base &item) {
    AVLNode<Base> *toRemove = this->root;
    AVLNode<Base> *parent = nullptr;
    bool isFound = false;
    vector<AVLNode<Base>*> vector1;
    while (!isFound && toRemove != nullptr) {
        vector1.push_back(toRemove);
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
            AVLNode<Base> *leftMost = toRemove->right;
            AVLNode<Base> *leftMostParent = toRemove;
            int replace = vector1.size()-1;
            if (leftMost->left != nullptr) {
                while (leftMost->left != nullptr) {
                    vector1.push_back(leftMost);
                    leftMostParent = leftMost;
                    leftMost = leftMost->left;
                }
                leftMostParent->left = leftMost->right;
                leftMost->right = toRemove->right;
            }
            leftMost->left = toRemove->left;
            vector1.at(replace) = leftMost;
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
            this->rebalancePathToRoot(vector1);
            delete toRemove;
        }
        else if (toRemove->left != nullptr || toRemove->right != nullptr) {
            AVLNode<Base> *child = nullptr;
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
            this->rebalancePathToRoot(vector1);

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


            if(parent == nullptr) {
                this->root = nullptr;
            }
            this->rebalancePathToRoot(vector1);
            delete toRemove;
            toRemove = nullptr;

        }

    }

}

/*
 * rebalancePathToRoot
 *
 * This function takes a vector of pointers to AVLNode
 * objects that represents the path that needs rebalancing after an
 * insert or remove. This method should walk from the bottom of the path to the root,
 * checking for imbalances, and correcting any it finds by calling rotation
 * methods as necessary to correct imbalances.
 *
 * Parameters:
 *   path: a vector of pointers to AVLNode objects
 *
 * Return value: None
 */
template <class Base>
void AVLTree<Base>::rebalancePathToRoot(const vector<AVLNode<Base> *> &path) {
    for(int i = path.size() -1; i >= 0; i-- ){
        AVLNode<Base> *node = path.at(i);
        AVLNode<Base> *pNode = nullptr;
        if(i > 0){
            pNode = path.at(i-1);
        }

        int leftHeight = node->getHeight(node->left);
        int rightHeight = node->getHeight(node->right);
        int balance = leftHeight - rightHeight;

        if(balance > 1){
            if(node->getHeight(node->left->left) < node->getHeight(node->left->right)){
                if(i == 0){
                    this->root = node->doubleRotateLeftRight();
                }
                else{
                    if(pNode->right == node){
                        pNode->right = node->doubleRotateLeftRight();
                    }
                    else{
                        pNode->left = node->doubleRotateLeftRight();
                    }
                }
            }
            else{
                if(i == 0){
                    this->root = node->singleRotateRight();
                }
                else{
                    if(pNode->right == node){
                        pNode->right = node->singleRotateRight();
                    }
                    else{
                        pNode->left = node->singleRotateRight();
                    }

                }
            }
        }
        else if(balance < -1){
            if(node->getHeight(node->right->left) > node->getHeight(node->right->right)){
                if(i == 0){
                    this->root = node->doubleRotateRightLeft();
                }
                else{
                    if(pNode->right == node){
                        pNode->right = node->doubleRotateRightLeft();
                    }
                    else{
                        pNode->left = node->doubleRotateRightLeft();
                    }
                }
            }
            else{
                if(i == 0){
                    this->root = node->singleRotateLeft();
                }
                else{
                    if(pNode->right == node){
                        pNode->right = node->singleRotateLeft();
                    }
                    else{
                        pNode->left = node->singleRotateLeft();
                    }
                }
            }
        }
        node->updateHeight();

    }
}

/*
 * printLevelOrder
 *
 * This function prints the nodes in the
 * tree in level order iteratively using an STL queue
 *
 * Parameters:
 *   os: the given ostream
 *
 * Return value: None
 */
template <class Base>
void AVLTree<Base>::printLevelOrder(ostream &os) const {
    if(this->root != nullptr){
        queue<AVLNode<Base>*> path;
        const int MAX_NUMBER = 20;
        int number = 0;
        path.push(this->root);
        while(!path.empty()){
            AVLNode<Base>* current = path.front();
            path.pop();
            number++;
            if(current != nullptr){
                os << current->data;
                path.push(current->left);
                path.push(current->right);
            }
            else{
                os << "NULL";
            }
            if(!path.empty()){
                if(number >= MAX_NUMBER){
                    os << endl;
                    number = 0;
                }
                else{
                    os << " ";
                }
            }

        }
        os << endl;
    }
    else{
        os << "NULL" << endl;
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
    const AVLNode<Base> *current = this->root;
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
    const AVLNode<Base> *current = this->root;
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

