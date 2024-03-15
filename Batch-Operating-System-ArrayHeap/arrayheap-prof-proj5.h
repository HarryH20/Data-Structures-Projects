#ifndef ARRAY_HEAP_PROJ5_PROF_H
#define ARRAY_HEAP_PROJ5_PROF_H

/* An ArrayHeap is a binary heap that is implemented using arrays. The heap can
 * grow dynamically if it gets full (it should double in capacity each time it
 * gets full).
 *
 * The default constructor constructs an empty ArrayHeap.
 *
 * The copy constructor creates a logical copy of the given ArrayHeap,
 * storing the values in its own copy. The copy constructor may call
 * operator= *after* it has initialized all the data members appropriately.
 *
 * The destructor cleans up any memory that the ArrayHeap has dynamically
 * allocated, and sets the data members to look like the heap is empty.
 *
 * The operator= method makes this object have the same logical structure
 * as the given heap. It should resize the heap as necessary so that the
 * two have the same capacity.
 *
 * The insert method inserts the given item into the heap (at the bottom),
 * and then restores the heap order property by bubbling the item up.
 *
 * The removeMinItem method removes the minimum item at the root of the
 * heap, places the last element in the root's position, and bubbles it
 * down to restore the heap property.
 *
 * The getMinItem method returns the minimum item at the top of the heap.
 *
 * The getNumItems method returns the number of items that are on the heap.
 *
 * The doubleCapacity method doubles the capacity of the heap (the data and
 * heapAndFreeStack data members).
 *
 * The bubbleUp method can be implemented iteratively or recursively. It
 * starts at the item given by ndx, and moves it up the heap towards the
 * root in order to preserve the heap order property.
 *
 * The bubbleDown method can be implemented iteratively or recursively. It
 * starts at the item given by ndx, and moves it down the heap towards the
 * leaves in order to preserve the heap order property.
 *
 * The data member "data" contains the items that are stored in the heap.
 * Once an item is placed in data, it should not move.
 *
 * The data member "heapAndFreeStack" describes the structure of the heap (in
 * heapAndFreeStack[0] through heapAndFreeStack[numItems-1]), and it has a stack
 * of the indexes in data that are not being used (in heapAndFreeStack[numItems]
 * through heapAndFreeStack[capacity-1]).  Every value in this array (whether in
 * the heap or stack region) is an index into the array "data".
 *
 * The data member "numItems" contains the number of items on the heap, and
 * serves as the dividing line between the heap structure and the stack of free
 * items.
 *
 * The data member "capacity" represents the number of items that the heap can
 * contain before requiring extra space. The data and heapAndFreeStack arrays
 * both are capacity long.
 */
template <typename T>
class ArrayHeap {
public:
    ArrayHeap();
    ArrayHeap(ArrayHeap<T> const &h);
    ~ArrayHeap();

    ArrayHeap<T> const &operator=(ArrayHeap<T> const &ah);

    void insert(T const &item);
    void removeMinItem();
    T const &getMinItem() const;
    int getNumItems() const;

protected:
    T *data;
    int *heapAndFreeStack;

    int numItems;
    int capacity;

    void doubleCapacity();
    void bubbleUp(int ndx);
    void bubbleDown(int ndx);
};

#endif
