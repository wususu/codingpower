#include <iostream>

namespace gv
{

/**
 * 与顶点相连的实体信息
 * */
template <typename T, typename K>
class Vertex
{
private:
    // 权重
    T weight;
    //　点值
    K name;
    // 头顶点编号
    int number;
    // 下一个相连的头顶点编号
    Vertex<T, K> *next = NULL;
public:
    enum{
        error = 0,
        ok = 1
    };

    Vertex(int number, K name):Vertex(number,name, NULL, NULL){};

    Vertex(int number, K name, T weight):Vertex(number, name, weight, NULL){};

    Vertex(int number,K name, T weight, Vertex<T, K>* next)
    {
        this->number = number;
        this->name = name;
        this->weight = weight;
        this->next = next;
    }

    void setW(int weight)
    {
        this->weight = weight;
    }

    Vertex<T, K>* getNext()
    {
        return this->next;
    }

    K getName()
    {
        return this->name;
    }

    T getW()
    {
        return this->weight;
    }

    int getN()
    {
        return this->number;
    }

    void setNext(Vertex<T, K> *next)
    {
        this->next = next;
    }


};



/**
 * 顶点类
 * */
template <typename T, typename K>
class Vroot
{
private:
    
    // 顶点(即尾顶点)编号
    int number;
    // 该点的信息;
    K name;
    // 该顶点的连线数;
    int arcN = 0;
    // 链表头
    Vertex<T, K> *root;
    Vroot<T, K> *next;

public:
    enum {error = 0, ok = 1};

    Vroot():Vroot(0, NULL, NULL){};

    Vroot(int number, K name):Vroot(number, NULL, name){};

    Vroot(int number, Vertex<T, K>* root, K name)
    {
        this->number = number;
        this->root = root;
        this->name = name;
        this->next = NULL;
    }

    void setName(K name)
    {
        this->name = name;
    }

    K getName()
    {
        return this->name;
    }

    void setNext(Vroot *next)
    {
        this->next = next;
    }

    Vroot<T, K> * getNext()
    {
        return this->next;
    }

    int getN()
    {
        return this->number;
    }

    Vertex<T, K>* getVertexRoot()
    {
        return this->root;
    }

    bool addVertex(int head, K name, T weight);
    bool contain(int head);

};





/**
 * 添加头顶点的记录结点
 * */
template <typename T, typename K>
bool Vroot<T, K>::addVertex(int head, K name, T weight)
{
    Vertex<T, K> *v = new Vertex<T, K>(head, name, weight);

    Vertex<T, K> *p = this->root;
    // root为NULL直接替换
    if(p == NULL)
    {
        this->root = v;
        return ok;
    }
    if(this->contain(head))
    {
        return error;
    }
    else
    {
        // 查找尾结点
        while(p->getNext() != NULL)
        {
            p = p->getNext();
        }
        p->setNext(v);
        return ok;
    }
}

template <typename T, typename K>
bool Vroot<T, K>::contain(int head)
{
    Vertex<T, K> *p = this->root;
    while(p != NULL)
    {
        if(p->getN() == head)
        {
            return ok;
        } 
        p = p->getNext();
    }
    return error;
}



/**
 * 图
 * */
template <typename T, typename K>
class Graph
{
private:
Vroot<T, K> *vhead;
// 当前顶点数
int num = 0;

public:
    enum {error = 0, ok = 1};

    Graph();
    ~Graph();
    int getN();
    void incN();
    bool contains(K name);
    Vroot<T, K>* getVroot(int n);
    int addVroot(K weight);
    bool insert(Vroot<T, K>* vroot);
    bool remove(int num);
    bool change(int num, K name);
    /**
     * 给编号为bottom与head的顶点添加一条权重为weight的有向边
     * */
    bool addArc(int bottom, int head, T weight);

    //debug
    void printVroots();
};


template <typename T, typename K>
Graph<T, K>::Graph()
{
    this->vhead = NULL;
}

template <typename T, typename K>
int Graph<T, K>::getN()
{
    return this->num;
}

template <typename T, typename K>
void Graph<T, K>::incN()
{
    this->num++;
}

template <typename T, typename K>
bool Graph<T, K>::insert(Vroot<T, K>* vroot)
{
    vroot->setNext(NULL);
    Vroot<T, K> *p = this->vhead;
    if(p == NULL)
    {
        this->vhead = vroot;
        return true;
    }
    while(p->getNext() != NULL)
    {
        p = p->getNext();
    }
    p->setNext(vroot);
    return true;
}

template <typename T, typename K>
bool Graph<T, K>::contains(K name)
{
    Vroot<T, K> *p = this->vhead;
    while(p != NULL)
    {
        if(p->getName() == name)
        {
            return true;
        }
        p = p->getNext();
    }
    return false;
}

template <typename T, typename K>
bool Graph<T, K>::change(int number, K name)
{
    Vroot<T, K> *vroot = this->getVroot(number);
    if(vroot == NULL)
    {
        return false;
    }
    vroot->setName(name);
    return true;
}

/**
 * 获取第n(1~n)个顶点 
 **/
template <typename T, typename K>
Vroot<T, K>* Graph<T, K>::getVroot(int n)
{
    if(n>0 && n<=this->num)
    {
        int i=1;
        Vroot<T, K> *p = this->vhead;
       while(i<n && p->getNext()!=NULL)
       {
           p = p->getNext();
           i++;
        }
        return p;
    }
    return NULL;
}

/**
 * 插入新的顶点,成功返回该点的序号码,否则返回0
 **/
template <typename T, typename K>
int Graph<T, K>::addVroot(K name)
{

    if(this->contains(name))
    {
        return error;
    }

    this->incN();
    Vroot<T, K> *vRoot = new Vroot<T, K>(this->getN(), name);

    if(this->insert(vRoot))
    {

        return this->getN();
        
    }
    return error;
}

template <typename T, typename K>
bool Graph<T, K>::addArc(int bottom, int head, T weight)
{
    if(bottom < 1 || bottom > this->num || head < 1 || head > this->num)
    {
        return error;
    }
    Vroot<T, K>* vRoot_b = this->getVroot(bottom);
    Vroot<T, K>* vRoot_h = this->getVroot(head);
    return vRoot_b->addVertex(head, vRoot_h->getName(), weight);
}

template <typename T, typename K>
void Graph<T, K>::printVroots()
{
    Vroot<T, K> *p = this->vhead;
    while(p != NULL)
    {
        std::cout<<"点：　"<<p->getN()<<" :"<<p->getName()<<std::endl;
        Vertex<T, K> *v = p->getVertexRoot();
        while(v!=NULL)
        {
            std::cout<<p->getName()<<"->"<<v->getName()<<" 权值："<<v->getW()<<std::endl;
            v = v->getNext();
        }
        p = p->getNext();
    }
}


}