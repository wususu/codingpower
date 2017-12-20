package depthofbinarytree;

class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;
    }
}

public class Solution {
    public int TreeDepth(TreeNode root) {
    	if (root == null) {
			return 0;
		}
    	int left=1,right=1;
    	if (root.left!=null) {
			left = 1+TreeDepth(root.left);
		}
    	if (root.right!=null) {
			right = 1+TreeDepth(root.right);
		}
        return left>right?left:right;
    }
}