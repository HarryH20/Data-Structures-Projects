#ifndef BST_PROF_PROJ3
#define BST_PROF_PROJ3

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

/* Declare a BST class so that the BSTNode class can reference it as a friend.
 * This avoids the chicken-and-egg problem of declaring two classes that must
 * refer to one another.
 */
template <class Base>
class BST;

/* A BSTNode represents a node in a binary search tree. Each BSTNode object
 * stores a single item (called "data"). Each object also has left and right
 * pointers, which point to the left and right subtrees.
 *
 * The BST is a friend of the BSTNode class, so that the BST may make changes to
 * the internals of a BSTNode.
 *
 * The constructor is provided for you; read it carefully.
 *
 * The destructor should recursively deallocate its subtrees.
 *
 * The getLeft(), getRight(), and getData() methods are useful for the
 * EncryptionTree class (or any class that wants to have read-only access to the
 * nodes of a BST).
 *
 * The printPreorder() traverses this node and its children recursively in
 * pre-order and prints each node it visits to a given ostream (default is
 * cout). It presumes that "data" can be printed; that is, "cout << this->data"
 * is a statement that makes sense. At each level of the tree it adds two spaces
 * of indentation to show the structure of the tree. The run-time of
 * printPreorder() is O(n). Can you figure out why?  Could it be made more
 * efficient?
 *
 * The minNode() and maxNode() methods are useful in verifySearchOrder(). They
 * should find the leftmost and rightmost node at or below the node they are
 * called on. These can be implemented recursively or iteratively.
 *
 * The function verifySearchOrder() can be used to do verifications of the
 * binary search tree's order. It can and should be used for testing purposes.
 * If you implement minNode() and maxNode() efficiently, the run-time of
 * verifySearchOrder() is O(n^2) for this (potentially unbalanced) tree. Can you
 * figure out why?  Could it be made more efficient using different techniques?
 *
 * No one may call the copy constructor or the assignment operator on a BSTNode,
 * so they are protected and will crash the program if called.
 */
template <class Base>
class BSTNode {
public:
    friend class BST<Base>;

    BSTNode(const Base &d = Base(), BSTNode *l = NULL, BSTNode *r = NULL) :
            data(d), left(l), right(r) {}
    ~BSTNode();

    const BSTNode *getLeft() const { return left; }
    const BSTNode *getRight() const { return right; }
    const Base &getData() const { return data; }

    void printPreorder(ostream &os = cout, string indent = "") const;

    void verifySearchOrder() const;

    const BSTNode *minNode() const;
    const BSTNode *maxNode() const;

protected:
    BSTNode(const BSTNode &t) { assert(false); }
    const BSTNode &operator=(const BSTNode &n) { assert(false); return *this; }

    Base data;
    BSTNode *left, *right;
};

/* professor's implementation of verifySearchOrder(); don't change it */
template <class Base>
void BSTNode<Base>::verifySearchOrder() const {
    if (left) {
        assert(left->maxNode()->data < data);
        left->verifySearchOrder();
    }
    if (right) {
        assert(data < right->minNode()->data);
        right->verifySearchOrder();
    }
}

/* A BST is a templated class that represents a binary search tree. It has one
 * data member, "root", which is a pointer to the root of the tree.
 *
 * The constructor and destructors are provided for you. Read over them
 * carefully.
 *
 * The insert() method places the given item in the tree, unless the item is
 * already in the tree. The insertion should follow the algorithm we discuss in
 * class.
 *
 * The remove() method removes the given item from the tree, if it is in the
 * tree. The remove should follow the algorithm we discuss in class.
 *
 * The printPreorder() and verifySearchOrder() methods simply calls the relevant
 * per-node methods on the root.
 *
 * No one may call the copy constructor or the assignment operator on a BST, so
 * they are protected and will crash the program if called.
 */
template <class Base>
class BST {
public:
    BST() : root(NULL) {}
    virtual ~BST() { BSTNode<Base> *r = root; root = NULL; delete r; }

    void insert(const Base &item);
    void remove(const Base &item);

    void printPreorder(ostream &os = cout) const { if (root) root->printPreorder(os); }
    void verifySearchOrder() const { if (root) root->verifySearchOrder(); }

protected:
    BST(const BST &t) { assert(false); }
    const BST &operator=(const BST &t) { assert(false); return *this; }

    BSTNode<Base> *root;
};

/* An EncryptionTree is a special type of BST which knows how to encrypt an
 * object (e.g. word) into a string that represents the path to the object in
 * the tree, and decrypt a path into the object (e.g. word) it leads to.
 *
 * The constructor and destructor methods are provided for you.
 *
 * The encrypt() method takes an object and returns a string of the form "rX"
 * where "r" is a literal letter r, and X is a sequence of 0 and 1 characters
 * (which may be empty). The r stands for "root", and each 0 and 1 represent the
 * left/right path from the root to the given object, with 0 indicating a
 * left-branch and 1 indicating a right-branch. If the object is not in the
 * dictionary, an empty string (or the string "?") should be returned.
 *
 * The decrypt() method takes an encrypted string (or path through the tree) in
 * the form provided by encrypt(). It should return a pointer to the associated
 * string for the given path (or NULL if the path is invalid).
 *
 * For this project the most likely candidate for the Base is an STL string, but
 * any orderable object could be used.
 *
 * This class has a virtual destructor (since its parent does), but no operator=
 * or copy constructor, since the defaults will be fine (the class does not
 * dynamically allocate any memory). Further, the parent class' copy constructor
 * and operator= prevent this class' from being used.
 */
template <class Base>
class EncryptionTree : public BST<Base> {
public:
    EncryptionTree() {}
    virtual ~EncryptionTree() {}

    string encrypt(const Base &item) const;
    const Base *decrypt(const string &path) const;
};

#endif
