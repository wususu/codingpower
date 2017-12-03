// 链表工具类
#include <iostream>
#include <string>
#include "linkedlist.h"


class Node
{
    public:
        int data;
        Node *next;
        Node()
        {
            this->next = NULL;
        }
        Node(int da)
        {
            this->data = da;
            this->next = NULL;
        }
        void setData(int da)
        {
            this->data = da;
        }
};
int main()
{

    List<Node> list;
    Node *da = new Node(1);
    Node *da2 = new Node(2);
    
    list.insert(da, 1);
    list.print();
    list.insert(da2, 1);
    list.print();
    list.insert(new Node(1),1);
    list.insert(new Node(1),1);
    list.insert(new Node(10),-1);
    list.print();
    Node *da3 = new Node(3);
    list.change(da3, 1);
    list.print();
    list.reserve();
    list.print();
    std::cout<<list.size()<<std::endl;
        std::cout<<list.contains(da2)<<std::endl;
                std::cout<<list.contains(new Node(10))<<std::endl;
    std::cout<<list.pop()->data<<std::endl;
    list.print();
        std::cout<<list.get(3)->data<<std::endl;
        list.insert(new Node(100),1);
        list.insert(new Node(99), -1);
        list.print();

    return 0;
}
