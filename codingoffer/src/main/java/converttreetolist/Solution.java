package converttreetolist;

import sun.reflect.generics.tree.Tree;

class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;
    }
}

public class Solution {
    public TreeNode Convert(TreeNode pRootOfTree) {
    		TreeNode node = pRootOfTree;
    	while(node != null && node.left != null)
    			node = node.left;
    		Convert(pRootOfTree, node);

    	return node;
    }
    
    private TreeNode Convert(TreeNode node, TreeNode lastNode){
    	if (node == null) {
			return lastNode;
		}
    	if (node.left != null) {
			lastNode = Convert(node.left, lastNode);
		}
    	if (node != lastNode) {
    			lastNode.right = node;
    			node.left = lastNode;
    			lastNode = node;
		}
    	if (node.right != null) {
			lastNode = Convert(node.right, lastNode);
		}
    	return lastNode;
    }
}