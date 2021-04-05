# BinaryTree
CSCI 2720 - Assignment 4
Date: April 04, 2021

Faisal Hossain
fh64801@uga.edu

Jeffrey Awuku-Boateng
jka56880@uga.edu

Contribution:
Jeffrey - Created BinaryTree.h and BinaryTree.cpp; Helped with the main.cpp
Faisal - Created the main.cpp; Helped with BinaryTree.h and BinaryTree.cpp
Together - Debugged the code and created the README file

Pseudocode for getNumSingleParent:
We initialized the node to the root. Then we have a conditional if statment checking if the node is NULL,
and if it is we return 0. If the the left or right child nodes are NULL then return 1. If both of those
conditional statements fail, then we recursively sum the leaf count of the tree by adding lead count of left subtree
plus the leaf count of right subtree.

Time Complexity of getNumSingleParent:

template<class T>
int BinaryTree<T>::getNumSingleParent() { O(n)
    return getSingleParents(root); O(1)
}

template<class T>
int BinaryTree<T>::getSingleParents(NodeType<T> *node) { O(n)
    node = root; O(1)
    if(node == nullptr){
        return 0;} O(1)
    if(node->left != nullptr || node->right != nullptr){
        return 1;} O(1)
    else{
        return getLeafNodes(node->left) + getLeafNodes(node->right);} O(1)
}

Big O: O(n)
Recurrence Relation: T(n) = T(n/2) + T(n/2) + 1 = 2T(n/2) + 1
Master Method: 2 = 2^k, T(n) = O(n^log_b(a)) = O(n^log_2(2)) = O(n)

---
Pseudocode for getNumLeafNodes:
We initialized the node to the root. Then we have a conditional if statment checking if the node is NULL,
and if it is we return 0. If the the left and right child nodes are NULL then return 1. If both of those
conditional statements fail, then we recursively sum the leaf count of the tree by adding lead count of left subtree
plus the leaf count of right subtree.

Time Complexity of getNumLeafNodes:

template<class T>
int BinaryTree<T>::getNumLeafNodes() {O(n)
    return getLeafNodes(root);O(1)
}

template<class T>
int BinaryTree<T>::getLeafNodes(NodeType<T> *node) { O(n)
    root = node; O(1)
    if(node == nullptr){
        return 0;} O(1)
    if(node->left == nullptr && node->right == nullptr){
        return 1;} O(1)
    else{
        return getLeafNodes(node->left) + getLeafNodes(node->right);} O(1)
}

Big O: O(n)
Recurrence Relation: T(n) = T(n/2) + T(n/2) + 1 = 2T(n/2) + 1
Master Method: 2 = 2^k, T(n) = O(n^log_b(a)) = O(n^log_2(2)) = O(n)

---
Pseudocode for getSumOfSubtrees:


Time Complexity of getSumOfSubtrees:

Big O: O(n)
Recurrence Relation: T(n) = T(n/2) + T(n/2) + 1 = 2T(n/2) + 1
Master Method: 2 = 2^k, T(n) = O(n^log_b(a)) = O(n^log_2(2)) = O(n)
