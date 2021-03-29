#ifndef BINARYTREEPROJECT_BINARYTREE_H
#define BINARYTREEPROJECT_BINARYTREE_H

using namespace std;

template<class T>
struct Node
{
    T key;
    Node<T> *left;
    Node<T> *right;

};

template<class T>
class BinaryTree {
    struct Node<T> *root;

public:
BinaryTree();
~BinaryTree();
void insert(T &key);
void deleteItm(T &key);
void retrieve(T &item, bool &found)const;
void preOrder()const;
void inOrder()const;
void postOrder()const;
void getLength()const;
void initialize(int number);
//check return type
void getNumSingleParent();
void getNumLeafNodes();
void getSumOfSubtrees();

private:
    int length;
    int value;


};


#endif //BINARYTREEPROJECT_BINARYTREE_H
