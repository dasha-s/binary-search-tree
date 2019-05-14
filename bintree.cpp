// -------------------Binary Search Tree -----------------------
// Daria Sykuleva 
// Date created: January 23, 2019
// Date last modified: January 29, 2019
// -------------------------------------------------------------
// Purpose: This project is to create a binary search tree class
// along with some additional functions.
// -------------------------------------------------------------

#include "bintree.h"
using namespace std;

//---------------------------------------------------------------
//creates an empty tree
BinTree::BinTree() {
    root = NULL;
}

//copy constructor
BinTree::BinTree(BinTree &A) {
    root = NULL;
    if (A.root != NULL) {
        root = new TreeNode(*A.root);
    }
}

//destructor
BinTree::~BinTree() {
    makeEmpty();
}
//---------------------------------------------------------------


//----------------------operator =-------------------------------
//assignment operator
//---------------------------------------------------------------
BinTree& BinTree::operator=(const BinTree &bt) {
    if (this != &bt) {     //delete the BinTree to which the new BinTree is going to be assigned
        delete root;
        root = NULL;
        if (bt.root != NULL) {
            root = new TreeNode(*bt.root);   //call the function for the branches
        }
    }
    return *this;
}

//----------------------operator ==------------------------------
//equality operator
//---------------------------------------------------------------
bool BinTree::operator==(const BinTree &bt) const {
    return *root == *bt.root;
}

//----------------------operator !=------------------------------
//equality operator
//---------------------------------------------------------------
bool BinTree::operator!=(const BinTree &bt) const {
    return !(*root == *bt.root);
}

//----------------------operator <<------------------------------
//displays the tree
//---------------------------------------------------------------
ostream& operator<<(ostream &output, const BinTree &bt) {
    output << *bt.root << endl;
    return output;
}

//--------------------------insert-------------------------------
//inserts an elements into the tree
//---------------------------------------------------------------
bool BinTree::insert(NodeData* data_to_insert) {
    if (root == NULL) {
        root = new TreeNode(data_to_insert);  //when root is empty, insert the element into the root
        return true;
    }
    return root->insert(data_to_insert);
}

//--------------------------retrieve-----------------------------
//gets the NodeData* of a given object in the tree
//---------------------------------------------------------------
bool BinTree::retrieve(const NodeData & nd, NodeData* & nd_to_return) {
    if (root == NULL) {
        return false;
    } else {
        return root->retrieve(nd, nd_to_return);
    }
}

//------------------------getHeight------------------------------
//finds the height of a given value in a tree
//---------------------------------------------------------------
int BinTree::getHeight(const NodeData & dt) const {
    TreeNode* found = root->findNode(&dt);  //find the element first
    if (found == NULL) {   //if there's no element found, return 0
        return 0;
    }
    return found->getHeight();
}

//----------------------bstreeToArray----------------------------
//fills an array of NodeData*, leaving the tree empty
//---------------------------------------------------------------
void BinTree::bstreeToArray(NodeData* bst[]) {
    int index = 0;
    if (root == NULL) {
        return;
    } else {
        root->bstreeToArray(bst, index);
    }
}

//----------------------arrayToBSTree----------------------------
//builds a balanced BinTree from a sorted array, leaving the array
//filled with NULLs
//---------------------------------------------------------------
void BinTree::arrayToBSTree(NodeData* bst[]) {
    int size = 0;
    for (int i = 0; i < 100; i++) {   //to find the size of the array
        if (bst[i] == NULL) {   //go through the array until NULL is reached
            size = i;
            break;
        }
    }
    int begin = 0;
    int end = size - 1;
    if (end >= begin) {
        makeEmpty();
        root = new TreeNode();
        root->arrayToBSTree(bst, begin, end);
    }
}

//-----------------------makeEmpty-------------------------------
//deletes all the elements from the tree
//---------------------------------------------------------------
void BinTree::makeEmpty() {
    delete root;
    root = NULL;
}

//---------------------------------------------------------------
//the function provided
void BinTree::displaySideways() const {
    sideways(root, 0);
}

void BinTree::sideways(TreeNode* current, int level) const {
    if (current != NULL) {
        level++;
        sideways(current->getRight(), level);

        // indent for readability, 4 spaces per depth level
        for (int i = level; i >= 0; i--) {
            cout << "    ";
        }

        cout << *current->getData() << endl;        // display information of object
        sideways(current->getLeft(), level);
    }
}
//---------------------------------------------------------------
