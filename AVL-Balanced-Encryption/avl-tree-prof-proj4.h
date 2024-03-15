#ifndef AVL_TREE_PROF_PROJ4
#define AVL_TREE_PROF_PROJ4

#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;

/* Declare an AVLTree class so that the AVLNode class can reference it as a
 * friend.  This avoids the chicken-and-egg problem of declaring two classes
 * that must refer to one another.
 */
template <class Base>
class AVLTree;

/* An AVLNode represents a node in an AVL-balanced binary search tree. Each
 * AVLNode object stores a single item (called "data"). Each object also has
 * left and right pointers, which point to the left and right subtrees, and it
 * knows its own height (the path length to its deepest descendant).
 *
 * The AVLTree is a friend of the AVLNode class, so that the AVLTree may make
 * changes to the internals of an AVLNode.
 *
 * Many of the methods in this class are virtually identical to those in the
 * BSTNode in the previous project, including the constructor, destructor,
 * getLeft(), getRight(), getData(), printPreorder(), verifySearchOrder(),
 * minNode(), maxNode(), and the copy constructor and assignment operator.
 *
 * The function verifyBalance() can be used to do verifications that the AVL
 * balance property holds at each node. It also can and should be used for
 * testing purposes. What is its running time?
 *
 * The singleRotateLeft() and singleRotateRight() methods do a single rotation
 * on the node they are called on, and return a pointer to the node that takes
 * its place (so that the node's parent's pointer can be changed).  Note that
 * these methods should update the heights of some nodes as necessary.
 *
 * The doubleRotateLeftRight() and doubleRotateRightLeft() methods do a double
 * rotation on the node they are called on. This is really simple if you have
 * implemented the single rotation methods; my double rotation methods are two
 * lines each. These methods return a pointer to the node which took the place
 * of the node the method was called on (so that the node's parent's pointer can
 * be changed).
 *
 * The getHeight() method is a static method which takes a pointer to a node,
 * and returns the height of that node (or -1 if the pointer is NULL). This
 * makes it easy to find the height of any node with a pointer, without having
 * to check for NULL.
 *
 * The updateHeight() method calculates and updates the value of the height on
 * the node it's called on. It assumes that the height values for the two
 * children of this node are correct, and uses them.
 */
template <class Base>
class AVLNode {
public:
    friend class AVLTree<Base>;
    AVLNode(const Base &d = Base(), AVLNode *l = NULL, AVLNode *r = NULL,
            int h = 0) : data(d), left(l), right(r), height(h) {}
    ~AVLNode();

    const AVLNode *getLeft() const { return left; }
    const AVLNode *getRight() const { return right; }
    const Base &getData() const { return data; }

    void printPreorder(ostream &os = cout, string indent = "") const;

    pair<AVLNode<Base> const *, AVLNode<Base> const *> verifySearchOrder() const;
    void verifyBalance() const;

    const AVLNode *minNode() const;
    const AVLNode *maxNode() const;

protected:
    AVLNode(const AVLNode &t) { assert(false); }
    const AVLNode &operator=(const AVLNode &n) { assert(false); return *this; }

    Base data;
    AVLNode *left, *right;
    int height;

    AVLNode *singleRotateLeft();
    AVLNode *singleRotateRight();
    AVLNode *doubleRotateLeftRight();
    AVLNode *doubleRotateRightLeft();

    static int getHeight(AVLNode const *n) { return n ? n->height : -1; }
    void updateHeight() {
        int lh = getHeight(left), rh = getHeight(right);
        height = (lh > rh ? lh : rh) + 1;
    }
};

/* professor's implementation of verifySearchOrder(); don't change it */
template <class Base>
pair<AVLNode<Base> const *, AVLNode<Base> const *> AVLNode<Base>::verifySearchOrder() const {
    auto min_max = make_pair(this, this);
    if (left) {
        auto left_min_max = left->verifySearchOrder();
        min_max.first = left_min_max.first;
        assert(left_min_max.second->data < data);
    }
    if (right) {
        auto right_min_max = right->verifySearchOrder();
        min_max.second = right_min_max.second;
        assert(data < right_min_max.second->data);
    }
    return min_max;
}

/* professor's implementation of verifyBalance(); don't change it */
template <class Base>
void AVLNode<Base>::verifyBalance() const {
    int heightDiff = abs(getHeight(left) - getHeight(right));
    assert(heightDiff <= 1);
    if (left) left->verifyBalance();
    if (right) right->verifyBalance();
}


/* An AVLTree is a templated class that represents an AVL-balanced binary search
 * tree. It has one data member, "root", which is a pointer to the root of the
 * tree.
 *
 * Many of the methods in this class are virtually identical to methods in the
 * BST from the previous project, including the constructor, destructor,
 * printPreorder(), verifySearchOrder(), copy constructor, and assignment
 * operator.
 *
 * The insert() and remove() methods behave as in the plain BST, but both
 * methods should rebalance the tree as necessary. This is best done by creating
 * a vector of pointers to AVLNode objects as the insert/remove methods search
 * for the place to do their work.  This vector of pointers represents the path
 * taken to get from the root to the place where a change occurs in the tree.
 * Note that for remove(), this path might go deeper than the node removed, in
 * the case of removing a node with two children (think carefully about this).
 * After insert/remove finish updating the tree, they can pass the path to
 * rebalancePathToRoot() which actually does the rebalancing. Think about how
 * large the vector of pointers needs to be, at its largest. An AVL tree with
 * height 30 must have at least 3,524,577 nodes, and if it has height 50, it
 * must have at least 53,316,291,172 nodes -- probably more than we care to put
 * in the tree. These results come from the minimum size of an AVL tree of
 * height h, which is described in your book as: S(h) = S(h - 1) + S(h - 2) + 1
 * (and base cases S(0) = 1, S(1) = 2).
 *
 * The printLevelOrder() method prints out all the nodes in the tree in
 * level-order (root, then the root's children, then their children, etc.). This
 * is like performing a breadth-first search of the tree. The method should put
 * up to 20 nodes on each line, and use multiple lines as necessary. This method
 * should use an STL queue, and it is iterative (not recursive). This method is
 * useful if we want to transmit the information for building exactly the same
 * tree to our correspondent. If we were to take all the non-NULL nodes and
 * insert them in the order printed by this method, we would get the exact same
 * tree. We would not always be able to construct the exact same tree if we were
 * to use printPreorder() instead.
 *
 * The rebalancePathToRoot() method takes a vector of pointers to AVLNode
 * objects. This vector represents the path that needs rebalancing after an
 * insert or remove. It's probably best to have the root at the start of the
 * vector. This method should walk from the bottom of the path to the root,
 * checking for imbalances, and correcting any it finds by calling rotation
 * methods as necessary to correct imbalances.
 */
template <class Base>
class AVLTree {
public:
    AVLTree() : root(NULL) {}
    virtual ~AVLTree() { delete root; }

    void insert(const Base &item);
    void remove(const Base &item);

    void printLevelOrder(ostream &os = cout) const;
    void printPreorder(ostream &os = cout) const { if (root) root->printPreorder(os); }
    void verifySearchOrder() const { if (root) root->verifySearchOrder(); }
    void verifyBalance() const { if (root) root->verifyBalance(); }

protected:
    AVLTree(const AVLTree &t) { assert(false); }
    const AVLTree &operator=(const AVLTree &t) { assert(false); return *this; }

    void rebalancePathToRoot(vector<AVLNode<Base> *> const &path);

    AVLNode<Base> *root;
};

/* The EncryptionTree for this project is exactly the same as for the previous
 * project, except that it now has an AVLTree as its parent class.
 */
template <class Base>
class EncryptionTree : public AVLTree<Base> {
public:
    EncryptionTree() {}
    virtual ~EncryptionTree() {}

    string encrypt(const Base &item) const;
    const Base *decrypt(const string &path) const;
};

#endif