#include <iostream>
#include "graph.h"

int main()
{
    gv::Graph<int, int> *graph = new gv::Graph<int ,int>();
        std::cout<<"in1"<<std::endl;

    int a= graph->addVroot(3);

    int b = graph->addVroot(4);

    int c = graph->addVroot(11);
    std::cout<<"in2"<<std::endl;


    graph->change(c, 12);

    graph->addArc(a, b, 10);

    graph->addArc(a, c, 11);


    graph->addArc(b,c, 1);

    graph->addArc(c, a, 3);


    graph->printVroots();
    return 0;
}