// 二叉树 / 哈夫曼书 / 普通书转二叉树
#include <iostream>
#include <string>
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
    Node()
    {
        this->data = 0;
        this->leftChild = NULL;
        this->rightChild = NULL;
        this->parent = NULL;
    }
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

    // 前序遍历二叉树
    void firstRootReserve(Node *rootNode);

    // 普通树转二叉树
    BinaryTree* toBinaryTree(NT::Tree* tree);

    // 二叉树转哈夫曼树
    BinaryTree* toHaffumanTree();
    Node** getTreeNodes(int &n) ;
    void getAllTreeNodes(Node *root, Node *nodeArr[10000], int &n);
    void printHaffumanTree(Node *rootNode, std::string n);
    void printHaffumanTree(BinaryTree *rootNode);
};

// 构建二叉树
void doBinaryTree(NT::TreeNode * bNode, BT::Node * binaryNode)
{

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

// 快排
void qsort(Node **nodeArr, int low, int hight)
{
    int l = low, h = hight;
    if(l<h)
    {
        Node *key = nodeArr[l];

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

    return new BT::BinaryTree(binaryNodeC);
}

// 二叉树转哈夫曼树
BT::BinaryTree* BT::BinaryTree::toHaffumanTree()
{
    int n = 0;
    BT::Node **nodeArr = this->getTreeNodes(n);
    std::cout<<std::endl<<n<<std::endl;
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
        BT::qsort(nodeArr, 0,n-1);
         
        BT::Node *newNode = new BT::Node(nodeArr[n-1]->getD() + nodeArr[n-2]->getD(), nodeArr[n-1], nodeArr[n-2], NULL);
        nodeArr[n-1]->setParent(newNode);
        nodeArr[n-2]->setParent(newNode);
        nodeArr[n-2] = newNode;
        n--;
    }

    return new BT::BinaryTree(nodeArr[0]);
}

// 获取所有结点及其数目n
BT::Node** BT::BinaryTree::getTreeNodes(int &n)
{
    if(this->root != NULL)
    {
        BT::Node **nodeArr = new BT::Node*[10000];
        n = 0;
        this->getAllTreeNodes(this->root, nodeArr, n);
        return nodeArr;
    }
    return NULL;
}

// 遍历所有结点存到nodeArr数组
void BT::BinaryTree::getAllTreeNodes(BT::Node *root, BT::Node **nodeArr, int &n)
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


// 遍历输出哈夫曼树及其编码
void BT::BinaryTree::printHaffumanTree(Node *rootNode, std::string s)
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

void BT::BinaryTree::printHaffumanTree(BT::BinaryTree *tree)
{
    this->printHaffumanTree(tree->root, "");
}