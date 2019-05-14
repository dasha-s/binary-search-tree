// -------------------Binary Search Tree -----------------------
// Daria Sykuleva 
// Date created: January 23, 2019
// Date last modified: January 29, 2019
// -------------------------------------------------------------
// Purpose: This project is to create a binary search tree class
// along with some additional functions.
// -------------------------------------------------------------

#ifndef BST_TREENODE_H
#define BST_TREENODE_H

#endif //BST_TREENODE_H

#include "nodedata.h"

class TreeNode {
public:
    //constructors:
    TreeNode();
    TreeNode(const TreeNode &A);
    TreeNode(NodeData *data);
    ~TreeNode();

    TreeNode& operator=(const TreeNode&);
    bool operator==(const TreeNode &) const;
    bool operator!=(const TreeNode &) const;

    friend ostream& operator<<(ostream&, const TreeNode&);
    bool insert(NodeData*);
    bool retrieve(const NodeData &, NodeData* &);
    int getHeight();
    void bstreeToArray(NodeData* [], int&);
    void arrayToBSTree(NodeData* [], int, int);
    int treeSize();
    TreeNode* findNode(const NodeData*);
    void makeEmpty();

    //accesors
    TreeNode* getRight() const;
    TreeNode* getLeft() const;
    NodeData* getData() const;

private:
    TreeNode *left;
    TreeNode *right;
    NodeData *data;
};
