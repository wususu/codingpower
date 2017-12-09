// 链表工具类
#include <iostream>
#include <string>
#include "linkedlist.h"

using namespace ll;

int main()
{

    List<std::string> list;
    list.insert("janke");
    list.insert("hehe");
    list.insert("华山");

    list.insert("kk", 1);

    std::cout<<"is: "<<list.contains("华山")<<std::endl;

    std::cout<<list.change("R3",4)<<std::endl;

    std::cout<<list.remove(1)<<std::endl;
    
    std::cout<<list.get(4)<<std::endl;


    list.print();


    return 0;
}
