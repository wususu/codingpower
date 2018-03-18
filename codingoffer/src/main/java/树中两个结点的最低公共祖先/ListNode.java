package 树中两个结点的最低公共祖先;

class ListNode{

    public int value;

    public ListNode next;

    public ListNode(TreeNode treeNode){
        this.value = treeNode.value;
    }
    public ListNode(int value){
        this.value = value;
    }
}