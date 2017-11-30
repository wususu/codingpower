#include "bettertree.h"
using namespace NT;

int main()
{
    Tree< TreeNode, ListNode<TreeNode> > tree;

    TreeNode *tnode1 = new TreeNode(1);

    TreeNode *tnode2 = new TreeNode(2);
    TreeNode *tnode3 = new TreeNode(3);

    TreeNode *tnode4 = new TreeNode(5);
    TreeNode *tnode5 = new TreeNode(6);
    TreeNode *tnode6 = new TreeNode(7);
    
    TreeNode *tnode7 = new TreeNode(8);
    TreeNode *tnode8 = new TreeNode(9);
    TreeNode *tnode9 = new TreeNode(10);
    
    TreeNode *tnode10 = new  TreeNode(11);
    TreeNode *tnode11 = new  TreeNode(12);
    TreeNode *tnode12 = new  TreeNode(13);
    TreeNode *tnode13 = new  TreeNode(14);

        TreeNode *tnode14 = new  TreeNode(15);

    
    tree.insert(tnode1, NULL);

    tree.insert(tnode2, tnode1);
    tree.insert(tnode3, tnode1);


    tree.insert(tnode3, tnode1);

    tree.insert(tnode4, tnode3);
    tree.insert(tnode5, tnode4);
    tree.insert(tnode6, tnode5);

    tree.insert(tnode7, tnode2);
            tree.insert(tnode13, tnode3);

    tree.insert(tnode8, tnode7);
    tree.insert(tnode9, tnode8);

    tree.insert(tnode10, tnode9);
    tree.insert(tnode11, tnode9);
    tree.insert(tnode12, tnode9);

     tree.print();

     tree.change(tnode14,tnode9, 2);
        std::cout<<tree.depth()<<std::endl;
             tree.print();

    return 0;
}