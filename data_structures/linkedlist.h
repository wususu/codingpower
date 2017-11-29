#include <iostream>
#include <string>

template <typename T>
class List
{
    private:
        T *head,*tail;
        int length;

    public:
        enum {error = 0, ok = 1};
        List()
        {
            length = 0;
            head = new T();
            tail = NULL;
        }
        ~List()
        {
            delete head;
            delete tail;
        }
        void print();
        void print_tree();
        T* pop();
        T* get(int position);
        bool insert(T *node, int position);
        bool remove(T *node, int position);
        bool change(T *node, int position);
        bool contains(T *node);
        void reserve();
        int size();
};
    

template<typename T>
T* List<T>::get(int position)
{
    if(position < 1)
        position = 1;
    if(position > this->length)
        position = this->length;
    T *p = head;
    int j = 0;
    while(j<position && p->next != NULL)
    {
        p = p->next;
        j++;
    }
    return p;
}

template<typename T>
T* List<T>::pop()
{
    if(this->head == NULL)
    {
        return NULL;
    }
    T *p = head->next;
    head = head->next;
    this->length--;
    return p;
}

//在第position个元素前插入da
template <typename T>
bool List<T>::insert(T *node, int position)
{
    if(this->length == 0)
    {
        node->next = this->head->next;

        this->head->next = node;
        this->length++;

        return ok;
    }

    if(position == -1)
    {
        T *p = this->head;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = node;
        node->next = NULL;
        this->length++;
        return ok;
    }

    //插入位置超出范围
    if(position < 1 || position > this->length)
    {
        return error;
    }

    T *p = head;

    int j = 0;
    while(j<position-1 && p->next != NULL)
    {
        p = p->next;
        j++;
    }
    if(j!=position-1)
        return error;
    node->next = p->next;
    p->next = node;
    this->length++;
    return ok;
}

// 替换第position处的数据
template <typename T>
bool List<T>::change(T *node, int position)
{
    if(position < 1 || position > length)
        return error;
    T *p = head,*q = NULL;
    int j = 0;
    while(j < position && p->next != NULL)
    {
        q = p;
        p = p->next;
        j++;
    }
    if(j!=position)
        return error;
    node->next = q->next->next;
    q->next = node;
    return ok;
}


//移除某个节点
template <typename T>
bool List<T>::remove(T *node, int position)
{
    if(position < 1 || position > this->length)
        return error;

    T *p = this->head;
    int j=0;
    while(j<position-1 && p->next != NULL)
    {
        p = p->next;
        j++;
    }
    if(j != position -1 || p->next == NULL)
        return error;
    node = p->next;
    p->next = p->next->next;
    this->length--;
    return ok;
}

//链表逆序
template <typename T>
void List<T>::reserve()
{
    T *top, *p, *j;
    top = NULL;
    p = head->next;
    while(p != NULL)
    {
        j = p->next;
        p->next = top;
        top = p;
        p = j;
    }
    head->next = top;
}


template <typename T>
bool List<T>::contains(T *node)
{
    T *p = head;
    while(p->next != NULL)
    {
        p = p->next;
        if(p == node)
        {
            return ok;
        }
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
    T *p = this->head;
    std::cout<<"debug: length="<<this->length<<std::endl;
    while(p->next != NULL)
    {
        p=p->next;
        std::cout<< p->data <<" ";
    }
    std::cout<<std::endl;
}
template <typename T>
void List<T>::print_tree()
{
    T *p = this->head;
    if(p == NULL)
    {
        return ;
    }
    std::cout<<"debug: length="<<this->length<<std::endl;
    while(p->next != NULL)
    {
        p=p->next;
        std::cout<<p->child->data<<" ";
    }
    std::cout<<std::endl;
}