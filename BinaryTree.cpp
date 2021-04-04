#include<iostream>
#include <string>
#include "BinaryTree.h"

using namespace std;

//creating a BinaryTree
template<class T>
BinaryTree<T>::BinaryTree()
{
    root = nullptr;
    length = 0;
}

//destructor
template<class T>
BinaryTree<T>::~BinaryTree()
{
    clear(root);
}

template<class T>
void BinaryTree<T>::clear(NodeType<T> *node)
{
    if (node == nullptr)
        return;

    clear(node->left); // left subtree
    clear(node->right); // right subtree
    delete node;
}

//inserting a number/node into a binary tree
template<class T>
void BinaryTree<T>::insert(T &key)
{
    struct NodeType<T> *newNode = new struct NodeType<T>;
    newNode->key = key;
    newNode->right = newNode->left = nullptr;

    struct NodeType<T> *curr = root; // pointer to root
    struct NodeType<T> *parent = nullptr;

        //check if tree is empty
        if(root == nullptr)
        {
            root = newNode;
	    // cout<<"Root Key is "<<root->key<<"\n";
            return;
        }

    //check if key is already in the tree
    while(curr != nullptr)
    {
        //traverse the tree
        parent = curr;

        if (key < curr->key) {
            curr = curr->left;
        } else {
            curr= curr->right;
        }
    }

    //insert new node
        if(key < parent->key)
        {
            parent->left = newNode;
        } else
          {
            parent->right = newNode;
          }
}

//deleting a number/node from a BinaryTree
template<class T>
void BinaryTree<T>::deleteItem(T key)
{
    searchAndDelete(root, key);
}

template<class T>
bool BinaryTree<T>::searchAndDelete(NodeType<T> *&node, T key) {
    if(node == nullptr) { // item does not exist
        cout << "\nItem not in tree." << endl;

        return false;
    }

    //found the node, now delete it
    else if(key== node->key)
    {
        deleteNode(node);
        return true;
    }

    else{
        if(key < node->key)
        searchAndDelete(node->left, key);

        else if(key > node->key)
           searchAndDelete(node->right, key);
    }
    return false;
}
template<class T>
void BinaryTree<T>::deleteNode(NodeType<T>*& targetNode) {
    NodeType<T>* temp = targetNode;

    // targetNode has two children
    if(targetNode->left != nullptr && targetNode->right != nullptr) {
        T predecessorItem = getPredecessor(targetNode->left);
        targetNode->key = predecessorItem;
        searchAndDelete(targetNode->left, predecessorItem);
    }

        // targetNode has one child
    else if(targetNode->left != nullptr) {
        targetNode = targetNode->left;

        delete temp;
    }

        // targetNode has one child
    else if(targetNode->right != nullptr) {
        targetNode = targetNode->right;

        delete temp;
    }

        // targetNode has no children
    else {
        targetNode = nullptr;

        delete temp;
    }
}

template<class T>
T BinaryTree<T>::getPredecessor(NodeType<T>*& node) const
{
    // keep going right until we get to null
    if(node->right == nullptr)
        return node->key;
    else
        return getPredecessor(node->right);
}

//retrieving a node/number from a binaryTree
template<class T>
void BinaryTree<T>::retrieve(T &item, bool &found) const
{
    struct NodeType<T> *node = new struct NodeType<T>;
    struct NodeType<T> *t = root;
    node->key = item;
    found = false;
    
    if(root == nullptr)
    {
        cout<<"You can not retrieve from an empty tree.";
        return;
    } else
    {
      while(t != nullptr)
        {
            if (node->key < t->key)
            {
                t = t->left;
            }

            else if (node->key > t->key)
            {
                t = t->right;
            }
            
            else
            {
                found = true;
                cout << "Item found in tree.";
		return;
               
            }
	    //cout<<"Item found in tree";
        }
      if(t == nullptr)
	{
	   //key not in the tree
            found = false;
            cout << "Item not in tree.";
            cout << endl;
            return;
	}
           
    }
}

//traversing the tree preOrderly
template<class T>
void BinaryTree<T>::preOrderTraversal(NodeType<T> *node) const
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
void BinaryTree<T>::inOrderTraversal(NodeType<T> *node) const
{
    if(node != NULL)
    {
        inOrderTraversal(node->left);
        cout<<node->key<<" ";
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
void BinaryTree<T>::postOrderTraversal(NodeType<T> *node) const
{
    if(node != NULL)
    {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout<<node->key<<" ";
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
    return calculateLength(root);
}

template<class T>
int BinaryTree<T>::calculateLength(NodeType<T> *node)const
{
    if(node == nullptr)
    {
        return 0;
    }
    return calculateLength(node->left)+calculateLength(node->right)+1;

}

//prints the number of leaf nodes in the tree
template<class T>
void BinaryTree<T>::getNumLeafNodes()
{
    int count = 0;
    NodeType<T> *t = nullptr;
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


template<class T>
int BinaryTree<T>::getSumOfSubtrees(T &value)
{
    
}

/*//polish this method
template<class T>
void BinaryTree<T>::getSumOfSubtrees()
{
    NodeType<T> *t = nullptr;
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

}*/

template<class T>
void BinaryTree<T>::initialize(T number)
{
    this->value = number;
}

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<string>;
