/* CSI 3334
 * Project 2 -- WordMelt
 * Filename: arrayqueue-student-proj2.h
 * Student name: Harrison Hassler
 * Due Date: Sept 18, 2023
 * Description: This file implements the functions in
 *     arrayqueue-prof-proj2.h
 */


#ifndef ARRAY_QUEUE_STUDENT_PROJ2_H
#define ARRAY_QUEUE_STUDENT_PROJ2_H

#include "arrayqueue-prof-proj2.h"
#include <cassert>

template <class Base>
ArrayQueue<Base>::ArrayQueue() {
    this->length = 0;
    this->capacity = 5;
    this->front = 0;
    this->data = new Base[this->capacity];


}

template <class Base>
ArrayQueue<Base>::ArrayQueue(const ArrayQueue<Base> &q) {
    this->length = q.length;
    this->capacity = q.capacity;
    this->front = 0;
    this->data = new Base[this->capacity];
    for(int i = this->front; i < this->length; i++){
        this->data[i] = q.data[(q.front + i) % this->capacity];
    }

}

template <class Base>
ArrayQueue<Base>::~ArrayQueue(){
    delete []this->data;
    this->front = 0;
    this->capacity = 0;
    this->length = 0;
}

template <class Base>
const Base &ArrayQueue<Base>::getFront() const {
    return this->data[this->front];
}

template <class Base>
void ArrayQueue<Base>::add(const Base &item) {
    if(this->length >= this->capacity){
        this->doubleCapacity();

    }
    this->data[(this->length + this->front)% this->capacity] = item;
    this->length++;

}

template <class Base>
void ArrayQueue<Base>::remove() {
    assert(this->length > 0);
    this->front = (this->front + 1) % this->capacity;
    this->length--;
}

template <class Base>
int ArrayQueue<Base>::getLength() const {
    return this->length;
}

template <class Base>
const ArrayQueue<Base> &ArrayQueue<Base>::operator=(const ArrayQueue <Base> &q){
    if(this != &q){
        delete[] this->data;
        this->length = q.length;
        this->capacity = q.capacity;
        this->front = 0;
        this->data = new Base[this->capacity];
        for(int i = this->front; i < this->length; i++){
            this->data[i] = q.data[(q.front + i) % this->capacity];
        }
    }
    return *this;
}

template <class Base>
void ArrayQueue<Base>::doubleCapacity() {
    Base *temp = this->data;
    int original = this->capacity;
    this->capacity *= 2;
    this->data = new Base[this->capacity];
    for(int i = 0; i < this->length; i++){
        this->data[i] = temp[(this->front + i) % original];
    }
    delete[] temp;
    this->front = 0;
}

#endif

