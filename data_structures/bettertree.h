// 树工具类
#include "linkedlist.h"
#include <iostream>
 
template <typename T, typename L>
class Tree
{
 
public:
    T *root = NULL;

    enum {error = 0, ok = 1};
    Tree()
    {
    }
    ~Tree()
    {
        delete root;
    }
    bool insert(T *treeNode, T *parent);
    bool contains(T *treenode, T *parentNode);
    bool remove(T *parentNode, int position);
    void print();
    void print2(T *node, int i);
    int depth();
    int dfs(T *tnode);
    // void tobinarytree();
    // void createhuffumentree();
};

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
        // this->myTreeNode = myTreeNode;
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
        this->length++;
        return 1;
    }
    // 移除第position(1~n)个子树
    bool removeChildNode(int position)
    {
        if(position < 1 || position > this->length)
            return 0;
        ListNode<TreeNode> *listNode = NULL;
        this->length--;
        return this->root->remove(listNode, position);
    }
};

template <typename T, typename L>
bool Tree<T, L>::contains(T *node, T *parentNode)
{
    L *lnode = NULL;
    List<L> *list = parentNode->root;
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

template <typename T, typename L>
bool Tree<T, L>::insert(T *node, T *parentNode)
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

template <typename T, typename L>
bool Tree<T, L>::remove(T *parentNode, int position)
{
    return parentNode->removeChildNode(position);
}

template <typename T, typename L>
int Tree<T, L>::depth()
{
    return this->dfs(this->root);
    
}

template <typename T, typename L>
int Tree<T, L>::dfs(T *node)
{
    std::cout<<node->data<<"   "<<node->length<<std::endl;
    int sum=0, a=0;
    if(node->length > 0)
    {
        List<L> *list = node->root;
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

template <typename T, typename L>
void Tree<T, L>::print()
{
    T *p = this->root;
    std::cout<<"第一层:"<<std::endl;
    std::cout<<this->root->data<<std::endl;
    if(p!=NULL)
        this->print2(p,2);
}

template <typename T, typename L>
void Tree<T, L>::print2(T *node,int i)
{
    std::cout<<"第"<<i<<"层:"<<std::endl;
    if(node->length > 0||node!=NULL)
    {
        for(int j=1; j<= node->length ;j++)
        {
            T * tnode = node->root->get(j)->child;
            std::cout<<tnode->data<<",";
        }
        std::cout<<std::endl;

        for(int j=1; j<= node->length ;j++)
        {
            T * tnode = node->root->get(i)->child;
            print2(tnode, i+1);
        }
    } 
}
