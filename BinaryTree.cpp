#include<iostream>
#include <string>
#include "BinaryTree.h"

using namespace std;

//creating a BinaryTree
template<class T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
    length = 0;
}

//destructor
template<class T>
BinaryTree<T>::~BinaryTree()
{

}

//inserting a number/node into a binary tree
template<class T>
void BinaryTree<T>::insert(T &key)
{
    struct Node<T> *newNode = new struct Node<T>;
    struct Node<T> *t = root; // pointer to root
    Node<T> *r = NULL; //trailing pointer

        //check if tree is empty
        if(root == NULL)
        {
            newNode->key = key;
            newNode->left = newNode->right = NULL;
            return;
        }

    //check if key is already in the tree
    while(t != NULL)
    {
        //start by checking root
        r = t;
        if(key == t->key)
        {
            return;
        }

        //if key isn't in the list check if it is bigger or small than root
        else if(key < t->key)
        {
            t = t->left;
        }

        else
        {
            t = t->right;
        }

        if(newNode->key < t->key)
        {
            t->left = newNode;
        } else if(newNode->key > t->key)
            {
                t->right = newNode;
            }
        else
            return;
    }

    //if there are not duplicates then insert the node
    if(key < r->key)
    {
        r->left = newNode;
    }
    else
    {
        r->right = newNode;
    }
}

//deleting a number/node from a BinaryTree
template<class T>
void BinaryTree<T>::deleteItm(T &key)
{

}

//retrieving a node/number from a binaryTree
template<class T>
void BinaryTree<T>::retrieve(T &item, bool &found) const
{

}

template<class T>
void BinaryTree<T>::preOrder() const
{

}

template<class T>
void BinaryTree<T>::inOrder() const
{

}

template<class T>
void BinaryTree<T>::postOrder() const
{

}

template<class T>
void BinaryTree<T>::getLength() const
{

}

template<class T>
void BinaryTree<T>::getNumLeafNodes()
{

}

template<class T>
void BinaryTree<T>::getNumSingleParent()
{

}

template<class T>
void BinaryTree<T>::getSumOfSubtrees()
{

}

template<class T>
void BinaryTree<T>::initialize(int number)
{
    this->value = number;
}

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<string>;