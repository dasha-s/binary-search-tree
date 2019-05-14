// -------------------Binary Search Tree -----------------------
// Daria Sykuleva 
// Date created: January 23, 2019
// Date last modified: January 29, 2019
// -------------------------------------------------------------
// Purpose: This project is to create a binary search tree class
// along with some additional functions.
// -------------------------------------------------------------

#include "treenode.h"

//-----------------------constructors---------------------------
TreeNode::TreeNode() {
    left = NULL;
    right = NULL;
    data = NULL;
}

TreeNode::TreeNode(const TreeNode &A) {
    data = new NodeData(*A.data);
    left = NULL;
    if (A.left != NULL) {
        left = new TreeNode(*A.left);
    }
    right = NULL;
    if (A.right != NULL) {
        right = new TreeNode(*A.right);
    }
}

TreeNode::TreeNode(NodeData* data) {
    left = NULL;
    right = NULL;
    this->data = data;
}

TreeNode::~TreeNode() {
    makeEmpty();
}
// --------------------------------------------------------------


//----------------------operator =-------------------------------
//assignment operator
//---------------------------------------------------------------
TreeNode& TreeNode::operator=(const TreeNode& rhs) {
    if (this != &rhs) {       //check if the TreeNode is not the same
        *data = *rhs.data;
        left = NULL;
        if (rhs.left != NULL) {
            left = new TreeNode(*rhs.left);
        }
        right = NULL;
        if (rhs.right != NULL) {
            right = new TreeNode(*rhs.right);
        }
    }
    return *this;
}

//----------------------operator ==------------------------------
//equality operator
//---------------------------------------------------------------
bool TreeNode::operator==(const TreeNode& rhs) const {
    bool left_equals = false;    //to check if this left side equals to the left side of rhs
    bool right_equals = false;   //to check if this right side equals to the right side of rhs
    if (left == NULL && rhs.left == NULL) {
        left_equals = true;     //left side is empty in both cases
    }
    if (left != NULL && rhs.left != NULL && *left == *rhs.left) {
        left_equals = true;     //both left sides are not empty and are the same
    }
    if (right == NULL && rhs.right == NULL) {
        right_equals = true;
    }
    if (right != NULL && rhs.right != NULL && *right == *rhs.right) {
        right_equals = true;
    }
    return *data == *rhs.data && left_equals && right_equals;
}

//----------------------operator !=------------------------------
//inequality operator
//---------------------------------------------------------------
bool TreeNode::operator!=(const TreeNode& rhs) const {
    return !(*this == rhs);
}

//----------------------operator <<------------------------------
//displays a tree using inorder traversal
//---------------------------------------------------------------
ostream& operator<<(ostream &output, const TreeNode &bt) {
    if (bt.left != NULL) {   //print the left side
        output << *bt.left;
    }
    output << *bt.data << " ";
    if (bt.right != NULL) {   //print the right side
        output << *bt.right;
    }
    return output;
}

//-------------------------insert--------------------------------
//inserts an element into a tree
//---------------------------------------------------------------
bool TreeNode::insert(NodeData* ptr) {
    if (*ptr > *(this->data)) {     //when the data to insert is bigger than root (going right)
        if (right != NULL) {
            return right->insert(ptr);  //recursively go right until the place to insert is found
        } else {
            right = new TreeNode(ptr);
            return true;
        }
    }
    if (*ptr < *(this->data)) {     //if the data to insert is smaller than the root (going left)
        if (left != NULL) {
            return left->insert(ptr);
        } else {
            left = new TreeNode(ptr);
            return true;
        }
    }
    return false;
}

//-------------------------retrieve------------------------------
//gets the NodeData* of a given object in a tree
//---------------------------------------------------------------
bool TreeNode::retrieve(const NodeData & nd, NodeData* & nd_to_return) {
    if (nd == *(this->data)) {  //if found
        nd_to_return = this->data;
        return true;
    }
    else if (nd < *(this->data)) { //going left
        if (left == NULL) {
            return false;
        } else {
            return left->retrieve(nd, nd_to_return);
        }
    } else if (nd > *(this->data)) { //going right
        if (right == NULL) {
            return false;
        } else {
            return right->retrieve(nd, nd_to_return);
        }
    }
    return false;
};


//------------------------getHeight------------------------------
//finds the height of a given value in a tree
//---------------------------------------------------------------
int TreeNode::getHeight() {
    int left_height = 0;   //to keep track of the height of the left side
    int right_height = 0;  //to keep track of the height of the right side
    if (left != NULL) {
        left_height = left->getHeight(); //recursively find the height
    }
    if (right != NULL) {
        right_height = right->getHeight();
    }
    if (left_height > right_height) {   //return the greatest side
        return left_height + 1;   // +1 adds the root
    } else {
        return right_height + 1;  // +1 adds the root
    }
}


//----------------------bstreeToArray----------------------------
//fills an array of NodeData*, leaving the tree empty
//---------------------------------------------------------------
void TreeNode::bstreeToArray(NodeData* bst[], int& index) {
    //inorder traversal
    if (left != NULL) {
        left->bstreeToArray(bst, index);  //recursively get the elements from the left side
    }
    bst[index] = new NodeData(*data);
    index++;
    if (right != NULL) {
        right->bstreeToArray(bst, index); //recursively get the elements from the right side
    }
}

//----------------------arrayToBSTree----------------------------
//builds a balanced BinTree from a sorted array, leaving the array
//filled with NULLs
//---------------------------------------------------------------
void TreeNode::arrayToBSTree(NodeData* bst[], int begin, int end) {
    if (begin > end) {
        return;
    }
    int mid = (begin+end)/2;    //divide the array in half (middle is the root)
    data = bst[mid];
    if (mid - 1 >= begin) {     //fill in the left side with the elements smaller than mid
        left = new TreeNode();
        left->arrayToBSTree(bst, begin, mid - 1); //continue dividing the sub array from the beginning to the middle
    }
    if (mid + 1 <= end) {    //fill in the right side
        right = new TreeNode();
        right->arrayToBSTree(bst, mid + 1, end);  //continue dividing the right sub array from the middle to the end
    }
}

//-------------------------treeSize------------------------------
//returns the size of a tree
//---------------------------------------------------------------
int TreeNode::treeSize() {
    int left_size = 0;     //to keep track of the size of the left side
    int right_size = 0;    //to keep track of the size of the right side
    if (left != NULL) {
        left_size = left->treeSize();  //count the amount of nodes on the left side
    }
    if (right != NULL) {
        right_size = right->treeSize();
    }
    return right_size + left_size + 1; //the amount of nodes on the right, on the left + the root
}


//-------------------------findNode------------------------------
//finds the given node in a tree
//---------------------------------------------------------------
TreeNode* TreeNode::findNode(const NodeData* dta) {
    if (*dta == *(this->data)) {
        return this;
    }
    //left
    if (this->left != NULL) {
        TreeNode* left_found = left->findNode(dta);
        if (left_found != NULL) {
            return left_found;
        }
    }
    //right
    if (this->right != NULL) {
        TreeNode* right_found = right->findNode(dta);
        if (right_found != NULL) {
            return right_found;
        }
    }
    return NULL;
}

//-----------------------makeEmpty-------------------------------
//deletes all the elements from the tree
//---------------------------------------------------------------
void TreeNode::makeEmpty() {
    if (this->data != NULL) {
        delete this->data;    //delete "data"
        this->data = NULL;    //set the data to NULL
    }
    if (this->left != NULL) {
        left->makeEmpty();    //delete everything from the left
        delete left;
        left = NULL;      //set the left to NULL
    }
    if (this->right != NULL) {
        right->makeEmpty();   //delete everything from the right
        delete right;
        right = NULL;     //set the right to NULL
    }
}

//------------------------accessors------------------------------
//to be able to access the private variables of the class
//---------------------------------------------------------------
TreeNode* TreeNode::getLeft() const {
    return left;
}

TreeNode* TreeNode::getRight() const {
    return right;
}

NodeData* TreeNode::getData() const {
    return data;
}
