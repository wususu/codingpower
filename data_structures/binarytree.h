// 二叉树 / 哈夫曼书 / 普通书转二叉树
#include <iostream>
#include <string>
#include <typeinfo>
#include "normaltree.h"


namespace bt{

template <typename T>
class Node
{
private:
    T data;
    Node *leftChild;
    Node *rightChild;
    Node *parent;

public:
    Node(T data):Node(data, NULL, NULL, NULL){};
    
    Node(T data, Node *P):Node(data, P, NULL, NULL){};
    
    Node(T data, Node *P, Node *L, Node *R)
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

    T getD()
    {
        return this->data;
    }

    void setParent(Node *P)
    {
        this->parent = P;
    }

    void setLchild(Node *L)
    {
        this->leftChild = L;
    }
    
    void setRchild(Node *R)
    {
        this->rightChild = R;
    }

    Node<T>* getLchild()
    {
        return this->leftChild;
    }

    Node<T>* getRchild()
    {
        return this->rightChild;
    }

    bool equals(Node<T> *node)
    {
        return this->data == node->data;
    }

};


template <typename T>
class BinaryTree
{  
private:
    Node<T> *root;
    // 前序遍历二叉树
    void firstRootReserve(Node<T> *rootNode);
    // 中序遍历二叉树
    void midRootReserve(Node<T> *rootNode);
    // 后序遍历二叉树
    void lastRootReserve(Node<T> *rootNode);

    Node<T>* getNode(T data);

    Node<T>* find(T data, Node<T> *root);

    void doBinaryTree(nt::TreeNode<T> * bNode, Node<T> * binaryNode);
    
    void qsort(Node<T> **nodeArr, int low, int hight);

    void printHaffumanTree(Node<T> *rootNode, std::string n);

    // 获取二叉树所有节点放入数组中,并计数(n)

    Node<T>** getTreeNodes(int &n) ;

    void getAllTreeNodes(Node<T> *root, Node<T> *nodeArr[10000], int &n);

public:
    BinaryTree()
    {
        this->root = NULL;
    }
    BinaryTree(Node<T> *root)
    {
        this->root = root;
    }
    ~BinaryTree()
    {

    }
    
    bool insert(T data, T parent, int side);
    
    bool contains(T data);
    
    bool remove(T data);
    
    bool change(T new_v, T old_v);
    
    // 打印输出二叉树
    void print();

    // 普通树转二叉树
    BinaryTree<T>* toBinaryTree(nt::Tree<T>* tree);

    // 二叉树转哈夫曼树
    BinaryTree<T>* toHaffumanTree();
    
    void printHaffumanTree(BinaryTree<T> *rootNode);
};

// 快排
template <typename T>
void BinaryTree<T>::qsort(Node<T> **nodeArr, int low, int hight)
{
    int l = low, h = hight;
    if(l<h)
    {
        Node<T> *key = nodeArr[l];

        while(l<h)
        {
            while(l<h && nodeArr[h]->getD() <= key->getD())
                h--;
            nodeArr[l] = nodeArr[h];

            while(l<h && nodeArr[l]->getD() >= key->getD())
                l++;
            nodeArr[h] = nodeArr[l];
        }
        nodeArr[l] = key;

        qsort(nodeArr, low, l-1);
        qsort(nodeArr, h+1, hight);
    }
}

template<typename T>
bool BinaryTree<T>::contains(T data)
{
    if(this->find(data, this->root) != NULL)
    {
        return true;
    }
    return false;
}

template <typename T>
Node<T>* BinaryTree<T>::getNode(T data)
{
    return this->find(data, this->root);
}

// 递归查找data是否存在于root子树中
template <typename T>
Node<T>* BinaryTree<T>::find(T data, Node<T> *root)
{
    Node<T> *p = NULL;
    if(root->getD() == data)
    {
        return root;
    }
    if(root->getLchild() != NULL)
    {
        p = this->find(data, root->getLchild());
        if(p != NULL)
        {
            return p;
        }
    }
    if(root->getRchild() != NULL)
    {
        p = this->find(data, root->getRchild());
        if(p!=NULL)
        {
            return p;
        }
    }
    return NULL;
}



template<typename T>
bool BinaryTree<T>::insert(T data, T parent, int side)
{

    Node<T> *p = NULL;

    if(this->root == NULL)
    {
        Node<T> *node = new Node<T>(data, NULL);
        this->root = node;
        return true;
    }
    else
    {
        p = this->getNode(parent);

        if(p != NULL && !this->contains(data))
        {
            Node<T> *node = new Node<T>(data, p);
            if(side == 0)
            {
                p->setLchild(node);
            }
            else
            {
                p->setRchild(node);
            }
            return true;
        }
        else
        {
            return false;
        }
    }
}


// 普通树转二叉树
template <typename T>
BinaryTree<T>* BinaryTree<T>::toBinaryTree(nt::Tree<T> *tree)
{
    nt::TreeNode<T> *bTreeRoot = tree->root;
    if(bTreeRoot == NULL)
    {
        return NULL;
    }

    Node<T> *binaryNode = new Node<T>(bTreeRoot->getData(), NULL);
    Node<T> *binaryNodeC = binaryNode;

    doBinaryTree(bTreeRoot, binaryNode);

    return new BinaryTree<T>(binaryNodeC);
}

// 构建二叉树
template <typename T>
void BinaryTree<T>::doBinaryTree(nt::TreeNode<T> * bNode, Node<T> * binaryNode)
{

    if(bNode->length == 0)
    {
        binaryNode->setLchild(NULL);
        binaryNode->setRchild(NULL);
    }
    else
    {
        // 第一个子结点
        nt::TreeNode<T> *firstbChild = bNode->getChild(1);
        Node<T> *leftChild = new Node<T>(firstbChild->getData(), binaryNode);
        binaryNode->setLchild(leftChild);
        doBinaryTree(firstbChild, leftChild);

        for(int i=2; i<=bNode->length; i++)
        {
            nt::TreeNode<T> *child = bNode->getChild(i);
            Node<T> *rightChild = new Node<T>(child->getData(), binaryNode);
            binaryNode->setRchild(rightChild);
            doBinaryTree(child, rightChild);

            binaryNode = binaryNode->getRchild();
        }
    }
}

// 二叉树转哈夫曼树
template <typename T>
BinaryTree<T>* BinaryTree<T>::toHaffumanTree()
{
    if(this->root == NULL)
    {
        return NULL;
    }
    if(typeid(this->root->getD()) != typeid(1) && typeid(this->root->getD()) != typeid(1.1))
    {
        return NULL;
    }
    int n = 0;
    bt::Node<T> **nodeArr = this->getTreeNodes(n);
    // 初始化
    for(int i=0;i<n;i++)
    {
        nodeArr[i]->setLchild(NULL);
        nodeArr[i]->setRchild(NULL);
        nodeArr[i]->setParent(NULL);
    }

    // 哈夫曼树构建
    while(n>1)
    {
        this->qsort(nodeArr, 0,n-1);
         
        Node<T> *newNode = new Node<T>(nodeArr[n-1]->getD() + nodeArr[n-2]->getD(), NULL, nodeArr[n-1], nodeArr[n-2]);
        nodeArr[n-1]->setParent(newNode);
        nodeArr[n-2]->setParent(newNode);
        nodeArr[n-2] = newNode;
        n--;
    }

    return new BinaryTree<T>(nodeArr[0]);
}

// 获取所有结点及其数目n
template <typename T>
Node<T>** BinaryTree<T>::getTreeNodes(int &n)
{
    if(this->root != NULL)
    {
        Node<T> **nodeArr = new Node<T>*[10000];
        n = 0;
        this->getAllTreeNodes(this->root, nodeArr, n);
        return nodeArr;
    }
    return NULL;
}

// 遍历所有结点存到nodeArr数组
template <typename T>
void BinaryTree<T>::getAllTreeNodes(Node<T> *root, Node<T> **nodeArr, int &n)
{
    nodeArr[n] = root;
    n++;
    if(root->getLchild() != NULL)
    {
        this->getAllTreeNodes(root->getLchild(), nodeArr, n);
    }
    if(root->getRchild() != NULL)
    {
        this->getAllTreeNodes(root->getRchild(), nodeArr, n);
    }
}

template <typename T>
void BinaryTree<T>::print()
{
    std::cout<<"前序遍历: ";
    this->firstRootReserve(this->root);
    std::cout<<std::endl<<"中序遍历: ";
    this->midRootReserve(this->root);
    std::cout<<std::endl<<"后序遍历: ";
    this->lastRootReserve(this->root);
    std::cout<<std::endl;
}

// 前序遍历
template <typename T>
void BinaryTree<T>::firstRootReserve(Node<T> *node)
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

// 中序遍历
template <typename T>
void BinaryTree<T>::midRootReserve(Node<T> *node)
{
    if(node->getLchild() != NULL)
    {
        this->midRootReserve(node->getLchild());
    }
    std::cout<<node->getD()<<" ";
    if(node->getRchild() != NULL)
    {
        this->midRootReserve(node->getRchild());
    }
}

// 后序遍历
template <typename T>
void BinaryTree<T>::lastRootReserve(Node<T> *node)
{
    if(node->getLchild() != NULL)
    {
        this->lastRootReserve(node->getLchild());
    }
    std::cout<<node->getD()<<" ";
    if(node->getRchild() != NULL)
    {
        this->lastRootReserve(node->getRchild());
    }
}



// 遍历输出哈夫曼树及其编码
template <typename T>
void BinaryTree<T>::printHaffumanTree(Node<T> *rootNode, std::string s)
{
    if(rootNode->getLchild() == NULL && rootNode->getRchild() == NULL)
    {
        std::cout<<rootNode->getD()<<"  编码:"<<s<<std::endl;
    }
    if(rootNode->getLchild() != NULL)
    {
        this->printHaffumanTree(rootNode->getLchild(), s+"0");
    }
    if(rootNode->getRchild() != NULL)
    {
        this->printHaffumanTree(rootNode->getRchild(), s+"1");
    }
}

template <typename T>
void BinaryTree<T>::printHaffumanTree(BinaryTree<T> *tree)
{
    this->printHaffumanTree(tree->root, "");
    std::cout<<std::endl;
}
}