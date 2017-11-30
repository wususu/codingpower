#include <iostream>
#include "bettertree.h"

namespace BT{


class Node
{
private:
    int data;
    Node *leftChild;
    Node *rightChild;
    Node *parent;

public:
    Node(int data, Node *P)
    {
        this->leftChild = NULL;
        this->rightChild = NULL;
        this->parent = P;
    }
    Node(int data, Node *L, Node *R, Node *P)
    {
        this->leftChild = L;
        this->rightChild = R;
        this->parent = P;
    }
    ~Node()
    {
        delete leftChild;
        delete rightChild;
        delete parent;
    }

    int getD()
    {
        return this->data;
    }
    
    void setLchild(Node *L)
    {
        this->leftChild = L;
    }
    
    void setRchild(Node *R)
    {
        this->rightChild = R;
    }

};


template<typename T>
class BinaryTree
{
private:
    T *root;
    
public:
    BinaryTree()
    {

    }
    ~BinaryTree()
    {

    }

    bool insert(T *node, T *parent, bool side);
    bool remove(T *parent, bool side);
    bool change(T *parent, bool side);
    BinaryTree createHalfmanTree();

};

}