// 基于链表的普通树实现
#include "linkedlist.h"
#include <iostream>

namespace NT{


template <typename T>
class TreeNode
{
private:

    
public:
    int length;
    T data;
    TreeNode *parent;
    ll::List<TreeNode<T>*> *child_list = new ll::List<TreeNode<T>*>;
    TreeNode(T data)
    {
        this->data = data;
        this->parent = NULL;
        this->length = 0;
    }

    void setData(T data)
    {
        this->data = data;
    }

    T getData()
    {
        return this->data;
    }

    void setParent(TreeNode<T> *p)
    {
        this->parent = p;
    }

    TreeNode<T>* getParent()
    {
        return this->parent;
    }

    TreeNode<T>* getChild(int position)
    {
        if(position > 1 || position <= this->length)
        {
            return this->child_list->get(position);
        }
        return NULL;
    }

    TreeNode<T> *contains(T data)
    {
        for(int i=1; i<=this->length; i++)
        {
            TreeNode<T> *p = this->getChild(i);
            if(p->getData() == data)
            {
                return p;
            }
        }
        return NULL;
    }

    // 保留节点
    int addChildNode(TreeNode<T> *node)
    {
        node->setParent(this);

        this->child_list->insert(node);
        return this->length = this->child_list->size();
    }

    // 新建节点
    int appendChildNode(T data)
    {
        TreeNode<T> *childNode = new TreeNode<T>(data);
        childNode->setParent(this);

        this->child_list->insert(childNode);
        int index = this->length = this->child_list->size();
        // std::cout<<"length: "<<this->length<<std::endl;
        return index;
    }

    // 移除第position(1~n)个子树
    bool removeChildNode(T data)
    {
        for(int i=1; i<=this->length; i++)
        {
            if(this->getChild(i)->getData() == data)
            {
                this->child_list->remove(i);
            }
        }
        this->length = this->child_list->size();
        return true;
    }

    // 替换第position(1~n)个子树
    bool changeChildNode(T data, int position)
    {
        if(position < 1 || position > this->length)
            return 0;
        TreeNode<T> *p = new TreeNode<T>(data);
        p->setParent(this);
        return this->root->change(p, position);
    }
};

template <typename T>
class Tree
{
 
public:
    TreeNode<T> *root;

    enum {error = 0, ok = 1};
    Tree()
    {
        this->root = NULL; 
    }
    ~Tree()
    {
    }
    bool insert(T data,T parent);

    bool c_dfs(TreeNode<T> *node, T data);

    int d_dfs(TreeNode<T> *node);

    int depth();

    void print();

    void print2(TreeNode<T> *node,int i);

    // 通过data获取该节点
    TreeNode<T>* getNode(T data)
    {
        return this->getNode(this->root, data);
    }

    TreeNode<T>* getNode(TreeNode<T> *node,  T data)
    {
        TreeNode<T> *p = NULL;
        if(node->getData() == data)
        {
            return node;
        }
        for(int i=1; i<=node->length && p==NULL; i++)
        {
            p = this->getNode(node->getChild(i), data);
        }
        return p;
    }

    bool contains(T data)
    {
        return this->c_dfs(this->root, data);
    }
    bool remove(T data);
    bool change(T new_v, T old_v);
    // int depth();
    // int dfs(TreeNode<T> *tnode);
    // void print();
    // void print2(TreeNode<T> *node, int i);
};

template<typename T>
bool Tree<T>::remove(T data)
{
    TreeNode<T> *p = NULL, *v = NULL;
    int j=1;
    p = this->getNode(data);
    if(p != NULL)
    {
        v = p->getParent();
        if(v == NULL && p->length > 1)
        {
            v = this->root = p->getChild(1);
            j = 2;
        }
        v->removeChildNode(data);
        for(int i = j; i<=p->length; i++)
        {
            v->addChildNode(p->getChild(i));
        }
        v = NULL;
        delete p;
        return true;
    }
    return false;
}


template<typename T>
bool Tree<T>::insert(T data, T parent)
{
    TreeNode<T> *p = new TreeNode<T>(data);
    //更节点为空，直接替换
    if(this->root == NULL)
    {
        p->setParent(NULL);
        this->root = p;
        p = NULL;
        return true;
    }
    else
    {
        if(!this->contains(data) && this->contains(parent))
        {
            this->getNode(parent)->appendChildNode(data);
            return true;
        }
    }
    return false;
}

//深度优先遍历查询是否存在值为data的节点
template <typename T>
bool Tree<T>::c_dfs(TreeNode<T> *node, T data)
{
    bool is = false;

    if(node->getData() == data)
    {
        is = is||true;
        return is;
    }
    for(int i = 1; i<=node->length && !is; i++)
    {
        TreeNode<T> *p = node->getChild(i);

        is = is||this->c_dfs(p, data);
    }
    return is;
}

template <typename T>
bool Tree<T>::change(T new_v, T old_v)
{
    TreeNode<T> *p = NULL;
    p = this->getNode(old_v);
    
    if(p != NULL && !this->contains(new_v))
    {
        p->setData(new_v);
        return true;
    }
    return false;
}

template <typename T>
int Tree<T>::depth()
{
    return this->d_dfs(this->root);
}

template <typename T>
int Tree<T>::d_dfs(TreeNode<T> *node)
{
    int count = 0, temp;
    if(node->length == 0)
    {
        return 1;
    }
    for(int i=1; i<=node->length; i++)
    {
        temp = this->d_dfs(node->getChild(i)) + 1;
        if(temp > count)
        {
            count = temp;
        }
    }
    return count;
}

template <typename T>
void Tree<T>::print()
{
    TreeNode<T> *p = this->root;
    std::cout<<"第一层:"<<std::endl;
    std::cout<<this->root->data<<std::endl;
    if(p!=NULL)
        this->print2(p,2);
}

template <typename T>
void Tree<T>::print2(TreeNode<T> *node,int i)
{
    if(node->length > 0 && node!=NULL)
    {
        std::cout<<"第"<<i<<"层:"<<std::endl;
        for(int j=1; j<= node->length ;j++)
        {
            std::cout<<node->getChild(j)->getData()<<",";
        }
        std::cout<<std::endl;

        for(int j=1; j<= node->length; j++)
        {            
            print2(node->getChild(j), i+1);
        }
    } 
}

}