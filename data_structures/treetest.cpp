#include "binarytree.h"


int main()
{

    NT::TreeNode *tnode1 = new NT::TreeNode(1);


    NT::TreeNode *tnode2 = new NT::TreeNode(2);
    NT::TreeNode *tnode3 = new NT::TreeNode(3);



    NT::TreeNode *tnode4 = new NT::TreeNode(5);
    NT::TreeNode *tnode5 = new NT::TreeNode(6);
    NT::TreeNode *tnode6 = new NT::TreeNode(7);
    
    NT::TreeNode *tnode7 = new NT::TreeNode(8);
    NT::TreeNode *tnode8 = new NT::TreeNode(9);
    NT::TreeNode *tnode9 = new NT::TreeNode(10);
    
    NT::TreeNode *tnode10 = new  NT::TreeNode(11);
    NT::TreeNode *tnode11 = new  NT::TreeNode(12);
    NT::TreeNode *tnode12 = new  NT::TreeNode(13);
    NT::TreeNode *tnode13 = new  NT::TreeNode(14);

    NT::TreeNode *tnode14 = new  NT::TreeNode(15);

    
    NT::Tree *tree = new NT::Tree();

    tree->insert(tnode1, NULL);

    tree->insert(tnode2, tnode1);
    tree->insert(tnode3, tnode1);


    tree->insert(tnode3, tnode1);

    tree->insert(tnode4, tnode3);
    tree->insert(tnode5, tnode4);
    tree->insert(tnode6, tnode5);

    tree->insert(tnode7, tnode2);
    tree->insert(tnode13, tnode3);

    tree->insert(tnode8, tnode7);
    tree->insert(tnode9, tnode8);

    tree->insert(tnode10, tnode9);
    tree->insert(tnode11, tnode9);
    tree->insert(tnode12, tnode9);

    tree->print();

    tree->change(tnode14,tnode9, 2);
    std::cout<<tree->depth()<<std::endl;
    tree->print();

    BT::BinaryTree *binaryTree = new BT::BinaryTree();

    BT::BinaryTree *binaryTree2 = binaryTree->toBinaryTree(tree);

    std::cout<<"前序遍历二叉树"<<std::endl;
    binaryTree->firstRootReserve(binaryTree2->root);
    
    std::cout<<"哈弗曼树构建及其遍历"<<std::endl;
    binaryTree->printHaffumanTree(binaryTree2->toHaffumanTree());
    

    return 0;
}