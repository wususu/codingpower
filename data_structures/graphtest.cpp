#include <iostream>
#include "graph.h"

int main()
{
    gv::Graph<int, int> *graph = new gv::Graph<int ,int>();
        std::cout<<"in1"<<std::endl;

    int a= graph->insert(3);

    int b = graph->insert(4);

    int c = graph->insert(11);

    graph->change(c, 12);

    graph->addArc(a, b, 10);

    graph->addArc(a, c, 11);


    graph->addArc(b,c, 1);

    graph->addArc(c, a, 3);


    graph->printVroots();


    graph->removeArc(1,3);
    graph->remove(b);


    std::cout<<"------"<<std::endl;
    graph->printVroots();
    return 0;
}