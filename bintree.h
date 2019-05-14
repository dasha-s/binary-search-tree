// -------------------Binary Search Tree -----------------------
// Daria Sykuleva 
// Date created: January 23, 2019
// Date last modified: January 29, 2019
// -------------------------------------------------------------
// Purpose: This project is to create a binary search tree class
// along with some additional functions.
// -------------------------------------------------------------

#ifndef BST_BINTREE_H
#define BST_BINTREE_H

#endif //BST_BINTREE_H

#include <iostream>
#include "treenode.h"
#include <stddef.h>

using namespace std;

class BinTree {
public:
    // constructors:
    BinTree ();
    BinTree (BinTree &A);
    ~BinTree ();

    //operator overloading:
    BinTree& operator=(const BinTree&);
    bool operator==(const BinTree&) const;
    bool operator!=(const BinTree&) const;

    // accessors
    friend ostream& operator<<(ostream&, const BinTree&);
    bool retrieve(const NodeData &, NodeData* &);

    int getHeight(const NodeData &) const;
    void bstreeToArray(NodeData* []);
    void arrayToBSTree(NodeData* []);

    bool insert(NodeData *);
    void makeEmpty();
    void displaySideways() const;

private:
    TreeNode *root;
    void sideways(TreeNode*, int) const;
};
