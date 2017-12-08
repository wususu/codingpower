#include <iostream>
#include <string>
#include "graph.h"

int main()
{
    gv::Graph<int, std::string> *graph = new gv::Graph<int ,std::string>();

    std::cout<<"插入结点【A, B, C, D, E ,F ,G, H】"<<std::endl;
    int a= graph->insert("A");

    int b = graph->insert("B");

    int c = graph->insert("C");

    int d = graph->insert("D");

    int e = graph->insert("E");

    int f = graph->insert("F");

    int g = graph->insert("G");

    int h = graph->insert("H");

    std::cout<<"添加弧 A——>B"<<std::endl;

    graph->addArc(a, b, 1);
    std::cout<<"添加弧 A——C"<<std::endl;

    graph->addArc(a, c, 2);

    std::cout<<"添加弧 B——>E"<<std::endl;
    graph->addArc(b, e, 5);

    std::cout<<"添加弧 B——>D"<<std::endl;
    graph->addArc(b,d, 4);

    std::cout<<"添加弧 C——>E"<<std::endl;
    graph->addArc(c, e, 3);

    std::cout<<"添加弧 C——>F"<<std::endl;
    graph->addArc(c, f, 5);

    std::cout<<"添加弧 D——>G"<<std::endl;
    graph->addArc(d, g, 9);

    std::cout<<"添加弧 E——>G"<<std::endl;
    graph->addArc(e, g, 7);

    std::cout<<"添加弧 E——>H"<<std::endl;
    graph->addArc(e, h, 10);

    std::cout<<"添加弧 F——>H"<<std::endl;
    graph->addArc(f, h, 3);

    std::cout<<"添加弧 E——>F"<<std::endl;
    graph->addArc(e, f, 3);

    
    std::cout<<"移除结点E"<<std::endl;
    graph->remove(e);

    // graph->printVroots();
    std::cout<<"------"<<std::endl;
    graph->get_shortest_route(a, h);
    graph->get_key_route();

    return 0;
}