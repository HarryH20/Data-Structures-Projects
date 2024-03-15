/* CSI 3334
 * Project 6 - Network Broadcasting
 * Filename: arrayheap-student-proj6.h
 * Student Name: Harrison Hassler
 * Due Date: 12/8/2023
 * Description: This file implements the functions in
 *    arrayheap-prof-proj6.h
 */
#ifndef ARRAY_HEAP_STUDENT_PROJ6_H
#define ARRAY_HEAP_STUDENT_PROJ6_H

#include "arrayheap-prof-proj6.h"
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

/*
 * ArrayHeap
 *
 * This is the default constructor constructs an empty
 * arrayheap.
 *
 * Parameters: none
 *
 * Return value: none
 */
template <typename T>
ArrayHeap<T>::ArrayHeap(){
    this->numItems = 0;
    this->capacity = 10;
    this->data = new T[this->capacity];
    this->heapAndFreeStack = new int[this->capacity];
    this->dataToHeap = new int[this->capacity];
    for(int i = 0; i < this->capacity; i++){
        this->heapAndFreeStack[i] = i;
    }
}

/*
 * ArrayHeap
 *
 * The copy constructor creates a logical copy of the given ArrayHeap,
 * storing the values in its own copy.
 *
 * Parameters: h: the arrayheap to be copied
 *
 * Return value: none
 */
template <typename T>
ArrayHeap<T>::ArrayHeap(ArrayHeap<T> const &h){
    this->numItems = h.numItems;
    this->capacity = h.capacity;
    this->data = new T[this->capacity];
    this->heapAndFreeStack = new int[this->capacity];
    this->dataToHeap = new int[this->capacity];

    for(int i = 0; i < this->capacity; i++){
        this->data[i] = h.data[i];
        this->heapAndFreeStack[i] = h.heapAndFreeStack[i];
        this->dataToHeap[i] = h.dataToHeap[i];

    }
}

/*
 * ~ArrayHeap
 *
 * The destructor cleans up any memory that the ArrayHeap has dynamically
 * allocated, and sets the data members to look like the heap is empty.
 *
 * Parameters: none
 *
 * Return value: none
 */
template <typename T>
ArrayHeap<T>::~ArrayHeap(){
    delete[] this->data;
    delete[] this->heapAndFreeStack;
    delete[] this->dataToHeap;
    this->numItems = 0;
    this->capacity = 10;
}

/*
 * operator =
 *
 * The operator= method makes this object have the same logical structure
 * as the given heap. It resizes the heap as necessary so that the
 * two have the same capacity.
 *
 * Parameters: ah: array heap being copied from
 *
 * Return value: this: an arrayheap
 */
template <typename T>
ArrayHeap<T> const &ArrayHeap<T>::operator=(const ArrayHeap<T> &ah) {
    if(this != &ah){
        delete[] this->data;
        delete[] this->heapAndFreeStack;
        delete[] this->dataToHeap;

        this->capacity = ah.capacity;
        this->numItems = ah.numItems;
        this->data = new T[this->capacity];
        this->heapAndFreeStack = new int[this->capacity];
        this->dataToHeap = new int[this->capacity];

        for(int i = 0; i < this->capacity; i++){
            this->data[i] = ah.data[i];
            this->heapAndFreeStack[i] = ah.heapAndFreeStack[i];
            this->dataToHeap[i] = ah.dataToHeap[i];
        }

    }
    return *this;
}

/*
 * insert
 *
 * The insert method inserts the given item into the heap (at the bottom),
 * and then restores the heap order property by bubbling the item up.
 *
 * Parameters: item: the item inserted into the heap
 *
 * Return value: index: the index where the new item is inserted into
 *                      the data array
 */
template <typename T>
int ArrayHeap<T>::insert(const T &item) {
    if(this->capacity <= this->numItems){
        this->doubleCapacity();
    }
    int index = this->heapAndFreeStack[this->numItems];

    this->data[this->heapAndFreeStack[this->numItems]] = item;
    this->dataToHeap[this->heapAndFreeStack[this->numItems]] = numItems;
    this->bubbleUp(numItems);
    numItems++;

    return index;

}

/*
 * removeMinItem
 *
 * The removeMinItem method removes the minimum item at the root of the
 * heap, places the last element in the root's position, and bubbles it
 * down to restore the heap property.
 *
 * Parameters: none
 *
 * Return value: none
 */
template <typename T>
void ArrayHeap<T>::removeMinItem() {
    int min = 0;
    this->numItems--;
    swap(dataToHeap[this->heapAndFreeStack[min]], dataToHeap[this->heapAndFreeStack[numItems]] );
    swap(this->heapAndFreeStack[min], this->heapAndFreeStack[this->numItems]);
    bubbleDown(min);

}

/*
 * getMinItem
 *
 * This method returns the minimum item at the top of the heap
 *
 * Parameters: none
 *
 * Return value: returns the minimum item at the
 *               top of the heap
 */
template <typename T>
T const &ArrayHeap<T>::getMinItem() const {
    return this->data[this->heapAndFreeStack[0]];
}

/*
 * getNumItems
 *
 * This method returns the number of items on the heap
 *
 * Parameters: none
 *
 * Return value: returns the number of items
 *               on the heap
 */
template <typename T>
int ArrayHeap<T>::getNumItems() const {
    return this->numItems;
}

/*
 * isOnHeap
 *
 * This method checks to see if the given key is
 * on the heap
 *
 * Parameters: key: the index in data
 *
 * Return value: returns true if key is on the heap
 */
template <typename T>
bool ArrayHeap<T>::isOnHeap(int key) const {
    if (0 <= key && key < this->capacity) {
        if (0 <= dataToHeap[key] && dataToHeap[key] < numItems) {
            if (heapAndFreeStack[dataToHeap[key]] == key) {
                return true;
            }
        }
    }
    return false;
}

/*
 * changeItemAtKey
 *
 * This method takes a key and a new item, uses the new item
 * to replace the old item at data[key], and performs bubble operations as
 * necessary to maintain heap order
 *
 * Parameters: key: the index in data
 *             newItem: new item replacing data[key]
 *
 * Return value: none
 */
template <typename T>
void ArrayHeap<T>::changeItemAtKey(int key, const T &newItem) {
    if(isOnHeap(key)){
        this->data[key] = newItem;
        bubbleUp(dataToHeap[key]);
        bubbleDown(dataToHeap[key]);

    }
}

/*
 * doubleCapacity
 *
 * The doubleCapacity method doubles the capacity of the heap
 *
 * Parameters: none
 *
 * Return value: none
 */
template <typename T>
void ArrayHeap<T>::doubleCapacity() {
    T *tempData = new T[this->capacity * 2];
    int *tempHeap = new int[this->capacity * 2];
    int* tempDataToHeap = new int[this->capacity *2];
    for(int i = 0; i < this->capacity; i++){
        tempData[i] = this->data[i];
        tempHeap[i] = this->heapAndFreeStack[i];
        tempDataToHeap[i] = this->dataToHeap[i];
    }

    for(int i = this->capacity; i < this->capacity *2; i++){
        tempHeap[i] = i;
    }
    this->capacity*=2;
    delete[] this->data;
    delete[] this->heapAndFreeStack;
    delete[] this->dataToHeap;
    this->data = tempData;
    this->heapAndFreeStack = tempHeap;
    this->dataToHeap = tempDataToHeap;
}

/*
 * bubbleUp
 *
 * This method bubbles up the item at the index given.
 * It starts at the item given by ndx, and moves it up the heap towards the
 * root in order to preserve the heap order property.
 *
 * Parameters: ndx: the index of the item in the arrayheap
 *
 * Return value: none
 */
template<typename T>
void ArrayHeap<T>::bubbleUp(int ndx){
    if(ndx <= 0){
        return;
    }

    int parent = floor((ndx -1)/ 2);
    if(data[heapAndFreeStack[ndx]] < data[heapAndFreeStack[parent]]){
        swap(dataToHeap[heapAndFreeStack[parent]], dataToHeap[heapAndFreeStack[ndx]]);
        swap(heapAndFreeStack[parent], heapAndFreeStack[ndx]);
        bubbleUp(parent);
    }

}

/*
 * bubbleDown
 *
 * This method bubbles down the item at the index given.
 * It starts at the item given by ndx, and moves it down the heap towards the
 * leaves in order to preserve the heap order property
 *
 * Parameters: ndx: the index of the item in the arrayheap
 *
 * Return value: none
 */

template <typename T>
void ArrayHeap<T>::bubbleDown(int ndx) {
    int child1 = (2 * ndx) + 1;
    int child2 = (2 * ndx )+ 2;

    if(child1 < this->numItems) {
        int lesserChild = child1;
        if ((data[heapAndFreeStack[child2]] < data[heapAndFreeStack[child1]]) &&
            (child2 < this->numItems)) {
            lesserChild = child2;
        }

        if (data[heapAndFreeStack[lesserChild]] < data[heapAndFreeStack[ndx]]) {
            swap(dataToHeap[heapAndFreeStack[lesserChild]], dataToHeap[heapAndFreeStack[ndx]]);
            swap(heapAndFreeStack[lesserChild], heapAndFreeStack[ndx]);
            bubbleDown(lesserChild);
        }
    }

}

#endif