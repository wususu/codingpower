#include "binarytree.h"


int main()
{

    nt::Tree<std::string> *tree = new nt::Tree<std::string>();

    tree->insert("A", "");

    tree->insert("B","A");
    tree->insert("C","A");
    tree->insert("D","A");

    tree->insert("E", "C");
    tree->insert("F", "C");
    tree->insert("H", "C");


    std::cout<<tree->remove("C")<<std::endl;
    std::cout<<tree->change("X", "F")<<std::endl;

    std::cout<<"----"<<std::endl;


    std::cout<<"树的深度是: "<<tree->depth()<<std::endl;
    std::cout<<"----"<<std::endl;

    tree->print();

    std::cout<<"---------二叉树--------"<<std::endl;
    bt::BinaryTree<int> btree;
    std::cout<<"插入12: 成功?"<<btree.insert(12, 0, 0)<<std::endl;
    std::cout<<"插入11: 成功?"<<btree.insert(11,12,0)<<std::endl;
    std::cout<<"插入10: 成功?"<<btree.insert(10,12,1)<<std::endl;


    std::cout<<"插入8: 成功?"<<btree.insert(8,11,0)<<std::endl;
    std::cout<<"插入7: 成功?"<<btree.insert(7,11,1)<<std::endl;

    std::cout<<"插入9: 成功?"<<btree.insert(9,10,1)<<std::endl;
    std::cout<<"插入6: 成功?"<<btree.insert(6,10,0)<<std::endl;

    btree.print();
    bt::BinaryTree<int> *bbtree = btree.toHaffumanTree(); 

    std::cout<<"哈夫曼编码: "<<std::endl;
    btree.printHaffumanTree(bbtree);


    std::cout<<"普通树转二叉树: "<<std::endl;
    bt::BinaryTree<std::string> s_btree; 
    bt::BinaryTree<std::string> *s_btree2 = s_btree.toBinaryTree(tree);
    s_btree2->print();
}