#include <iostream>
#include <string>

using namespace std;

class Data
{
    public:
        int data;
        Data(int da = 0)
        {
            this->data = da;
        }
};

class Node
{
    public:
        Data data;
        Node *next;
        Node(Data da, Node *p=NULL)
        {
            this->data = da;
            this->next = p;
        }
        void setData(Data da)
        {
            this->data = da;
        }
};

class List
{
    private:
        Node *head,*tail;
        int length;

    public:
        enum {error = 0, ok = 1};
        List()
        {
            length = 0;
            head = new Node(NULL, NULL);
            tail = NULL;
        }
        ~List()
        {
            delete head;
            delete tail;
        }
        void print();
        bool Insert(Data da, int position);
        bool Delete(int position, Data &da);
        bool Change(Data da, int position);
};

//在第position个元素前插入da
bool List::Insert(Data da, int position)
{
    cout<<"in"<<endl;
    if(this->length == 0)
    {
        cout<<"head=null"<<endl;
        Node *node = new Node(da);
        head->next = node;
        this->length++;
        return 1;
    }
    //插入位置超出范围
    if(position < 1 || position > this->length){
        cout<<"位置超出范围"<<endl;
        return 0;
    }

    Node *p = head;

    int j = 0;
    while(j<position-1 && p->next != NULL)
    {
        p = p->next;
        j++;
    }
    if(j!=position-1)
        return 0;
    Node *node = new Node(da, p->next);
    p->next = node;
    this->length++;
    return 1;
}

// 替换第position处的数据
bool List::Change(Data da, int position)
{
    if(position < 1 || position > length)
        return error;
    Node *p = head;
    int j = 0;
    while(j < position && p->next != NULL)
    {
        p = p->next;
        j++;
    }
    if(j!=position)
        return error;

    p->setData(da);
    return ok;
}

bool List::Delete(int position, Data &da)
{
    if(position < 1 || position > this->length)
        return error;

    Node *p = this->head;
    int j=0;
    while(j<position-1 && p->next != NULL)
    {
        p = p->next;
        j++;
    }
    if(j != position -1 || p->next == NULL)
        return error;
    da = p->next->data;
    p->next = p->next->next;
    this->length--;
    return ok;
}

void List::print()
{
    Node *p = this->head;
    cout<<"debug: length="<<this->length<<endl;
    while(p->next != NULL)
    {
        p=p->next;
        cout<<p->data.data<<" ";
    }
    cout<<endl;
}

int main()
{
    List list;
    Data da(1);
    Data da2(2);
    list.Insert(da, 1);
    list.print();
    list.Insert(da2, 1);
    list.print();
    list.Insert(da2,1);
    list.Insert(da2,1);
    list.Insert(da,1);
    list.print();
    Data da3(3);
    list.Change(da3, 3);
    list.print();

    list.Delete(1, da);
    cout<<da.data<<endl;
    list.print();
    return 0;
}
