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
    struct Node<T> *node = new struct Node<T>;
    struct Node<T> *t;
    node->key = item;
    found = node->key == t->key;

    if(length == 0)
    {
        cout<<"You can not retrieve from an empty tree.";
        return;
    }

    //loop through the tree
    while(t != NULL)
    {
        if(node->key < t->key)
        {
            t = t->left;
        }
        else if(node->key > t->key)
        {
            t = t->right;
        }

        if(found)
        {
            cout<<"Item found in tree.";
            return;
        }
        else
            {
              return;
            }
    }

    //key not in the tree
    if(node->key != t->key)
    {
        found = false;
        cout<<"Item not in tree.";
        return;
    }

}

//traversing the tree preOrderly
template<class T>
void BinaryTree<T>::preOrderTraversal(Node<T> *node) const
{
    if(node != NULL)
    {
        cout<< node->key<<endl;
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

//using the preOrderTraversal method to traverse the tree
template<class T>
void BinaryTree<T>::preOrder() const
{
    preOrderTraversal(root);
    cout<<endl;

}
//traversing the tree inOrderly
template<class T>
void BinaryTree<T>::inOrderTraversal(Node<T> *node) const
{
    if(node != NULL)
    {
        inOrderTraversal(node->left);
        cout<<node->key;
        inOrderTraversal(node->right);
    }
}
//using the inOrderTraversal method to traverse the tree
template<class T>
void BinaryTree<T>::inOrder() const
{
    inOrderTraversal(root);
    cout<<endl;
}
//traversing the tree postOrderly
template<class T>
void BinaryTree<T>::postOrderTraversal(Node<T> *node) const
{
    if(node != NULL)
    {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout<<node->key;
    }
}

//using the postOrderTraversal method to traverse the tree
template<class T>
void BinaryTree<T>::postOrder() const
{
    postOrderTraversal(root);
    cout<<endl;
}

template<class T>
 int BinaryTree<T>::getLength() const
{
    return this->length;
}

//prints the number of leaf nodes in the tree
template<class T>
void BinaryTree<T>::getNumLeafNodes()
{
    int count = 0;
    Node<T> *t;
    while(t!= NULL)
    {
        if(t->left == NULL && t->right == NULL)
        {
            count += 1;
            return;
        }
        cout<<"Number of leaf nodes are: "<<count;
    }
}

template<class T>
void BinaryTree<T>::getNumSingleParent()
{

}

//polish this method
template<class T>
void BinaryTree<T>::getSumOfSubtrees(Node<T> *t)
{
    T element;
    T sum;
    cout<<"Item to get sum of subtrees: ";
    cin>>element;

    while(t != NULL)
    {
        //if element is not in the tree
        if(t == NULL && t->key != element)
        {
            cout<<element<<" can not be found in the tree.";
            cout<<endl;
        }

        //when element is found in the tree, add it's sub nodes
        if(t->key == element)
        {
             sum = t->left->key + t->right->key;
            cout<<"Sum of subnodes: "<<sum;
            cout<<endl;
            return;
        }

        //return 0 when key doesn't have subNodes
        if(t->key == element && t->left == NULL && t->right == NULL)
        {
           cout<<"Sum of subnodes: "<< 0;
           cout<<endl;
        }

    }

}

template<class T>
void BinaryTree<T>::initialize(int number)
{
    this->value = number;
}

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<string>;
