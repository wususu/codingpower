// 二叉树 / 哈夫曼书 / 普通书转二叉树
#include <iostream>
#include "normaltree.h"

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
        this->data = data;
        this->leftChild = NULL;
        this->rightChild = NULL;
        this->parent = P;
    }
    Node(int data, Node *L, Node *R, Node *P)
    {
        this->data = data;
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

    Node* getLchild()
    {
        return this->leftChild;
    }

    Node* getRchild()
    {
        return this->rightChild;
    }

    bool equals(Node *node)
    {
        return this->data == node->data;
    }

};


class BinaryTree
{  
public:
    Node *root = NULL;
    BinaryTree()
    {

    }
    BinaryTree(Node *root)
    {
        this->root = root;
    }
    ~BinaryTree()
    {

    }
    bool insert(int data, Node *parent, int side);
    bool find(Node *node, Node *root);
    bool contains(Node *node);
    bool remove(Node *parent, int side);
    bool change(Node *parent, int side);
    void firstRootReserve(Node *rootNode);
    BinaryTree* toBinaryTree(NT::Tree* tree);
    BinaryTree* createHalfmanTree();

};


void doBinaryTree(NT::TreeNode * bNode, BT::Node * binaryNode)
{

    std::cout<<bNode->data<<"  "<<bNode->length<<" | "<<std::endl;
    std::cout<<binaryNode->getD()<<std::endl;
    if(bNode->length == 0)
    {
        binaryNode->setLchild(NULL);
        binaryNode->setRchild(NULL);
    }
    else
    {
        // 第一个子结点
        NT::TreeNode *firstbChild = bNode->root->get(1)->child;
        BT::Node *leftChild = new BT::Node(firstbChild->data, binaryNode);
        binaryNode->setLchild(leftChild);
        doBinaryTree(firstbChild, leftChild);

        for(int i=2; i<=bNode->length; i++)
        {
            NT::TreeNode *child = bNode->root->get(i)->child;
            BT::Node *rightChild = new BT::Node(child->data, binaryNode);
            binaryNode->setRchild(rightChild);
            doBinaryTree(child, rightChild);

            binaryNode = binaryNode->getRchild();
        }
    }
}
}

// template<typename T>
bool BT::BinaryTree::contains(Node *node)
{
    return this->find(node, this->root);
}

// template <typename T>
bool BT::BinaryTree::find(Node *node, Node *root)
{
    if(root == NULL)
    {
        return false;
    }
    if(root == node)
    {
        return true;
    }
    if(root->getLchild() != NULL)
    {
        return this->find(node, root->getLchild());
    }
    if(root->getRchild() != NULL)
    {
        return this->find(node, root->getRchild());
    }
    return false;
}



// template<typename T>
bool BT::BinaryTree::insert(int data, Node *parent, int side)
{
    if(this->root = NULL)
    {
        Node *node = new Node(data, NULL);
        this->root = node;
    }
    else
    {
        if(this->contains(parent))
        {
            Node *node = new Node(data, parent);
            if(side == 0)
            {
                parent->setLchild(node);
            }
            else
            {
                parent->setRchild(node);
            }
        }
        else
        {
            return false;
        }
    }
}


// 普通树转二叉树
BT::BinaryTree* BT::BinaryTree::toBinaryTree(NT::Tree *tree)
{
    NT::TreeNode *bTreeRoot = tree->root;
    if(bTreeRoot == NULL || !bTreeRoot->data)
    {
        return NULL;
    }

    std::cout<<bTreeRoot->data<<std::endl;
    BT::Node *binaryNode = new BT::Node(bTreeRoot->data, NULL);
    BT::Node *binaryNodeC = binaryNode;

    BT::doBinaryTree(bTreeRoot, binaryNode);

    // return NULL;
    return new BT::BinaryTree(binaryNodeC);
}

// 前序遍历
void BT::BinaryTree::firstRootReserve(BT::Node *node)
{
    std::cout<<node->getD()<<" ";
    if(node->getLchild() != NULL)
    {
        this->firstRootReserve(node->getLchild());
    }
    if(node->getRchild() != NULL)
    {
        this->firstRootReserve(node->getRchild());
    }
}

