#include <iostream>
#include <string>

namespace ll{

template <typename T>
class Node
{

private:
        T data;
        Node *next;

    public:
        Node()
        {
            this->next = NULL;
        }

        Node(T da)
        {
            this->data = da;
            this->next = NULL;
        }

        ~Node()
        {
            this->next = NULL;
        }

        void setData(T da)
        {
            this->data = da;
        }

        T getData()
        {
            return this->data;
        }

        void setNext(Node *next)
        {
            this->next = next;
        }

        Node<T>* getNext()
        {
            return this->next;
        }
};


template <typename T>
class List
{
    private:
        Node<T>* head;
        
        int length;

    public:
        enum {error = 0, ok = 1};
        
        List();

        ~List();
        
        void print();
        void print_tree();
        
        T pop();
        
        T get(int position);
        
        bool insert(T data, int position = -1);
        
        bool remove(int position);

        bool remove(T data);
        
        bool change(T data, int position);
        
        bool contains(T data);
        
        void reserve();
        
        int size();
    };
    
template <typename T>
List<T>::List()
{
    this->length = 0;
    this->head = NULL;
    // head = new Node<T>;
}

template <typename T>
List<T>::~List()
{
    delete head;
}

template<typename T>
T List<T>::get(int position)
{
    if(this->length<1)
    {
        return NULL;
    }
    if(position < 1)
        position = 1;
    if(position > this->length)
        position = this->length;

    Node<T> *p = this->head;
    int j = 1;
    while(j<position && p != NULL)
    {
        j++;
        p = p->getNext();
    }
    return p->getData();
}

template<typename T>
T List<T>::pop()
{
    T a;
    if(this->length > 0)
    {
        Node<T> *p = head;
        head = head->getNext();
        this->length--;
        a = p->getData();
        delete p;
    }
    return a;
}

//在第position个元素前插入da
template <typename T>
bool List<T>::insert(T data, int position)
{
    Node<T> *p = new Node<T>(data);
    Node<T> *v = NULL;
    // 直接放入head
    if(this->length == 0)
    {
        this->head = p;
        this->length++;

        p = NULL;
        return ok;
    }

    // position为-1,插入末尾
    if(position == -1)
    {
        v = this->head;
        while(v->getNext() != NULL)
        {
            v = v->getNext();
        }
        v->setNext(p);
        this->length++;
        p = v = NULL;
        return ok;
    }

    //插入位置超出范围
    if(position < 1 || position > this->length)
    {
        return error;
    }

    // 按位置插入
    v= this->head;
    if(position == 1)
    {
        p->setNext(this->head);
        this->head = p;
    }
    else
    {
        int j = 1;
        while(j<position-1 && v != NULL)
        {
            v = v->getNext();
            j++;
        }
        if(j!=position-1)
            return error;
        p->setNext(v->getNext());
        v->setNext(p);
    }

    this->length++;
    p = v = NULL;
    return ok;
}

// 替换第position处的数据
template <typename T>
bool List<T>::change(T data, int position)
{
    if(position < 1 || position > this->length)
        return error;
    Node<T> *p = head;
    int j = 1;
    while(j < position && p != NULL)
    {
        p = p->getNext();
        j++;
    }
    if(j!=position)
        return error;
    p->setData(data);
    p = NULL;
    return ok;
}

//移除某个节点
template <typename T>
bool List<T>::remove(int position)
{
    if(position < 1 || position > this->length)
        return error;

    Node<T> *p = this->head, *v;
    if(position == 1)
    {
        v = this->head;
        this->head = v->getNext();
    }
    else
    {
        int j=1;
        while(j<position-1 && p != NULL)
        {
            p = p->getNext();
            j++;
        }
        if(j != position -1 || p->getNext() == NULL)
            return error;

        v = p->getNext();
        p->setNext(p->getNext()->getNext());
    }

    delete v;
    p = v = NULL;
    this->length--;
    return ok;
}

//链表逆序
template <typename T>
void List<T>::reserve()
{
    Node<T> *top, *p, *j;
    top = NULL;
    p = this->head;
    while(p != NULL)
    {
        j = p->getNext();
        p->setNext(top);
        top = p;
        p = j;
    }
    this->head = top;
    top = p = j = NULL;
}


template <typename T>
bool List<T>::contains(T data)
{
    Node<T> *p = this->head;
    while(p != NULL)
    {
        if(p->getData() == data)
        {
            return ok;
        }
        p = p->getNext();
    }
    return error;
}


//获取链表节点个数
template <typename T>
int List<T>::size()
{
    return this->length;
}

template <typename T>
void List<T>::print()
{
    Node<T> *p = this->head;
    std::cout<<"debug: length="<<this->length<<std::endl;
    while(p != NULL)
    {
        std::cout<< p->getData() <<" ";
                p=p->getNext();

    }
    std::cout<<std::endl;
}
// template <typename T>
// void List<T>::print_tree()
// {
//     Node<T> *p = this->head;
//     if(p == NULL)
//     {
//         return ;
//     }
//     std::cout<<"debug: length="<<this->length<<std::endl;
//     while(p != NULL)
//     {
//         p=p->getNext();
//         // std::cout<<p->child->data<<" ";
//     }
//     std::cout<<std::endl;
// }
}