// 基于链表的普通树实现
#include "linkedlist.h"
#include <iostream>

namespace NT{

template<typename T>
class ListNode
{
public:
    // T *myTreeNode;
    T *child;
    ListNode *next;
    ListNode()
    {
        this->child = NULL;
        this->next = NULL;
    }
    ListNode(T *child)
    {
        this->child = child;
        this->next = NULL;
    }
    ListNode(T *child, ListNode *next)
    {
        this->child = child;
        this->next = next;
    }
};


class TreeNode
{
private:

    
public:
    int length;
    int data;
    TreeNode *parent;
    List< ListNode<TreeNode> > *root = new List< ListNode<TreeNode> >;
    TreeNode(int data)
    {
        this->data = data;
        this->length = 0;
    }

    void setParent(TreeNode *p)
    {
        this->parent = p;
    }

    bool appendChildNode(TreeNode *childNode)
    {
        ListNode<TreeNode> *listNode = new ListNode<TreeNode>();
        listNode->child = childNode;
        childNode->parent = this;
        this->root->insert(listNode, -1);
        this->length = this->root->size();
        // std::cout<<"length: "<<this->length<<std::endl;
        return 1;
    }

    // 移除第position(1~n)个子树
    bool removeChildNode(int position)
    {
        if(position < 1 || position > this->length)
            return 0;
        
        ListNode<TreeNode> *listNode = NULL;
        this->length = this->root->size();
        return this->root->remove(listNode, position);
    }

    // 替换第position(1~n)个子树
    bool changeChildNode(TreeNode *treeNode, int position)
    {
        if(position < 1 || position > this->length)
            return 0;
        
        ListNode<TreeNode> *listNode = new ListNode<TreeNode>(treeNode);
        return this->root->change(listNode, position);
    }
};


class Tree
{
 
public:
    TreeNode *root;

    enum {error = 0, ok = 1};
    Tree()
    {
        this->root = NULL; 
    }
    ~Tree()
    {
    }
    bool insert(TreeNode *treeNode, TreeNode *parent);
    bool contains(TreeNode *treenode, TreeNode *parentNode);
    bool remove(TreeNode *parentNode, int position);
    bool change(TreeNode *node, TreeNode *parentNode, int position);
    int depth();
    int dfs(TreeNode *tnode);
    void print();
    void print2(TreeNode *node, int i);
};



// template <typename T, typename L>
bool Tree::contains(TreeNode *node, TreeNode *parentNode)
{
    ListNode<TreeNode> *lnode = NULL;
    List<ListNode<TreeNode> > *list = parentNode->root;
    int p = 1;
    while(p < list->size())
    {
        p++;
        lnode = list->get(p);
        if(lnode->child == node)
            return ok;
    }
    return error;
}

// template <typename T, typename L>
bool Tree::insert(TreeNode *node, TreeNode *parentNode)
{
    if(parentNode == NULL)
    {

        node->parent = NULL;
        this->root = node;

        return ok;
    }
    if(this->contains(node, parentNode))
    {
        std::cout<<"结点已存在"<<std::endl;
        return error;
    }
    else
    {
        parentNode->appendChildNode(node);
        return ok;
    }

    return error;
}

// template <typename T, typename L>
bool Tree::change(TreeNode *node, TreeNode *parentNode, int position)
{
    return parentNode->changeChildNode(node, position);
}

// template <typename T, typename L>
bool Tree::remove(TreeNode *parentNode, int position)
{
    return parentNode->removeChildNode(position);
}

// template <typename T, typename L>
int Tree::depth()
{
    return this->dfs(this->root);
    
}

// template <typename T, typename L>
int Tree::dfs(TreeNode *node)
{
    std::cout<<node->data<<"   "<<node->length<<std::endl;
    int sum=0, a=0;
    if(node->length > 0)
    {
        List<ListNode<TreeNode> > *list = node->root;
        for(int i=1; i<=node->length; i++)
        {
            a = dfs(list->get(i)->child) + 1;
            sum = a>sum ? a: sum;
        }
        return sum;
    }
    else
    {
        return 1;
    }
}

// template <typename T, typename L>
void Tree::print()
{
    TreeNode *p = this->root;
    std::cout<<"第一层:"<<std::endl;
    std::cout<<this->root->data<<std::endl;
    if(p!=NULL)
        this->print2(p,2);
}

// template <typename T, typename L>
void Tree::print2(TreeNode *node,int i)
{
    std::cout<<"第"<<i<<"层:"<<std::endl;
    if(node->length > 0||node!=NULL)
    {
        for(int j=1; j<= node->length ;j++)
        {
            TreeNode * tnode = node->root->get(j)->child;
            std::cout<<tnode->data<<",";
        }
        std::cout<<std::endl;

        for(int j=1; j<= node->length; j++)
        {
            TreeNode * tnode = node->root->get(j)->child;
            print2(tnode, i+1);
        }
    } 
}

}