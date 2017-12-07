#include <iostream>
#include <string>
#include "graph.h"

int main()
{
    gv::Graph<int, std::string> *graph = new gv::Graph<int ,std::string>();
        std::cout<<"in1"<<std::endl;

    int a= graph->insert("A");

    int b = graph->insert("B");

    int c = graph->insert("C");

    int d = graph->insert("D");

    int e = graph->insert("E");

    int f = graph->insert("F");

    int g = graph->insert("G");

    int h = graph->insert("H");


    graph->addArc(a, b, 1);

    graph->addArc(a, c, 2);

    graph->addArc(b, e, 5);

    graph->addArc(b,d, 4);

    graph->addArc(c, e, 3);

    graph->addArc(c, f, 5);

    graph->addArc(d, g, 9);

    graph->addArc(e, g, 7);

    graph->addArc(e, h, 10);

    graph->addArc(f, h, 3);



 graph->addArc(e, f, 1);


    graph->printVroots();


    // graph->removeArc(1,3);
    // graph->remove(b);


    std::cout<<"------"<<std::endl;
        graph->remove(e);

    graph->printVroots();
        std::cout<<"------"<<std::endl;
    graph->get_shortest_route(a, h);
    
    return 0;
}