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

    Vertex(int number,K name, T weight, Vertex<T, K>* next);

    void setW(int weight);

    Vertex<T, K>* getNext();

    K getName();

    T getW();

    int getN();

    void setNext(Vertex<T, K> *next);
};

/**
 * 顶点类
 * */
template<typename T, typename K>
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

    Vroot(int number, Vertex<T, K>* root, K name);

    ~Vroot();

    void setName(K name);

    K getName();

    void setNext(Vroot *next);

    Vroot<T, K> * getNext();

    int getN();

    void setVertexRoot(Vertex<T, K> *v);

    Vertex<T, K>* getVertexRoot();

    bool addVertex(int head, K name, T weight);

    bool contain(int head);

    // 移除该顶点指向第head个顶点的弧
    bool remove(int head);
};



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

    void decN();
    
    bool contains(int name);
    
    Vroot<T, K>* getVroot(int n);
    
    bool addVroot(Vroot<T, K>* vroot);
    
    int insert(K name);
    /**
     * 移除第num个顶点及所有指向该点的弧
     **/
    
    bool remove(int num);
    
    bool change(int num, K name);
    
    /**
     * 给编号为bottom与head的顶点添加一条权重为weight的有向边
     * */
    bool addArc(int bottom, int head, T weight);
    
    bool removeArc(int bottom, int head);
    
    //debug
    void printVroots();
};

template <typename T, typename K>
Vertex<T, K>::Vertex(int number,K name, T weight, Vertex<T, K>* next)
{
    this->number = number;
    this->name = name;
    this->weight = weight;
    this->next = next;
}

template <typename T, typename K>
void Vertex<T, K>::setW(int weight)
{
    this->weight = weight;
}

template <typename T, typename K>
Vertex<T, K>* Vertex<T, K>::getNext()
{
    return this->next;
}

template<typename T, typename K>
K Vertex<T, K>::getName()
{
    return this->name;
}

template<typename T, typename K>
T Vertex<T, K>::getW()
{
    return this->weight;
}

template<typename T, typename K>
int Vertex<T, K>::getN()
{
    return this->number;
}

template<typename T, typename K>
void Vertex<T, K>::setNext(Vertex<T, K> *next)
{
    this->next = next;
}



template<typename T, typename K>
Vroot<T, K>::Vroot(int number, Vertex<T, K>* root, K name)
{
    this->number = number;
    this->root = root;
    this->name = name;
    this->next = NULL;
}

template <typename T, typename K>
Vroot<T, K>::~Vroot()
{
    Vertex<T, K> *p = this->root;
    if(p != NULL)
    {
        p = p->getNext();
        delete this->root;
        this->root = p;
    }
    delete p, this->root;
}

template<typename T, typename K>
void Vroot<T, K>::setName(K name)
{
    this->name = name;
}

template <typename T, typename K>
K Vroot<T, K>::getName()
{
    return this->name;
}

template <typename T, typename K>
void Vroot<T, K>::setNext(Vroot *next)
{
    this->next = next;
}

template <typename T, typename K>
Vroot<T, K>* Vroot<T ,K>::getNext()
{
    return this->next;
}

template <typename T, typename K>
int Vroot<T, K>::getN()
{
    return this->number;
}

template <typename T, typename K>
void Vroot<T, K>::setVertexRoot(Vertex<T, K> *v)
{
    this->root = v;
}

template <typename T, typename K>
Vertex<T, K>* Vroot<T, K>::getVertexRoot()
{
    return this->root;
}

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
        return true;
    }
    if(this->contain(head))
    {
        return false;
    }
    else
    {
        // 查找尾结点
        while(p->getNext() != NULL)
        {
            p = p->getNext();
        }
        p->setNext(v);
        return true;
    }
    return false;
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

template <typename T, typename K>
bool Vroot<T, K>::remove(int head)
{
    Vertex<T, K> *v = this->getVertexRoot();
    Vertex<T, K> *w = v->getNext();
    if(v->getN() == head)
    {
        this->setVertexRoot(v->getNext());
    }
    while(w != NULL)
    {
        if(w->getN() == head)
        {
            v->setNext(w->getNext());
            delete w;
            w = v->getNext();            
            continue;
        }
        v = w;
        w = v->getNext();
    }
    return true;
}

template <typename T, typename K>
Graph<T, K>::Graph()
{
    this->vhead = NULL;
}

template <typename T, typename K>
Graph<T, K>::~Graph()
{
    Vroot<T, K> *p = this->vhead;
    while(p != NULL)
    {
        p = p->getNext();
        delete this->vhead;
        this->vhead = p;
    }
    delete p, this->vhead;
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
void Graph<T, K>::decN()
{
    if(this->num > 0)
    {
        this->num--;
    }
}

/**
 * 插入新的顶点,成功返回该点的序号码,否则返回0
 **/
template <typename T, typename K>
int Graph<T, K>::insert(K name)
{

    this->incN();
    Vroot<T, K> *vRoot = new Vroot<T, K>(this->getN(), name);

    if(this->addVroot(vRoot))
    {
        return this->getN();
    }
    return error;
}

template <typename T, typename K>
bool Graph<T, K>::contains(int num)
{
    Vroot<T, K> *p = this->vhead;
    while(p != NULL)
    {
        if(p->getN() == num)
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

template <typename T, typename K>
bool Graph<T, K>::remove(int num)
{
    if(num<1 || num>this->num)
    {
        return error;
    }
    if(!this->contains(num))
    {
        return error;
    }
    Vroot<T, K> *p = this->vhead;
    Vroot<T, K> *q = p->getNext();
    if(p->getN() == num)
    {
        this->vhead = p->getNext();
    }
    p->remove(num);
    while(q!=NULL)
    {
        if(q->getN() == num)
        {
            this->decN();
            p->setNext(q->getNext());
            delete q;
            q = p->getNext();
            continue;
        }
        q->remove(num);

        p = q;
        q = p->getNext();
    }
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

template <typename T, typename K>
bool Graph<T, K>::addVroot(Vroot<T, K> *vroot)
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
bool Graph<T, K>::removeArc(int bottom, int head)
{
    if(bottom <1 || bottom > this->num || head < 1 || head > this->num)
        return false;
    return this->getVroot(bottom)->remove(head);
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
            std::cout<<p->getN()<<"("<<p->getName()<<")->"<<v->getN()<<"("<<v->getName()<<") 权值："<<v->getW()<<std::endl;
            v = v->getNext();
        }
        p = p->getNext();
    }
}
}