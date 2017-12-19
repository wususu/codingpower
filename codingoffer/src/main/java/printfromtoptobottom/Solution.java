package printfromtoptobottom;

import java.util.ArrayList;
import java.util.LinkedList;

class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;
    }
}

public class Solution {
		
    public ArrayList<Integer> PrintFromTopToBottom(TreeNode root) {
		LinkedList<TreeNode> queue = new LinkedList<>();
		ArrayList<Integer> list = new ArrayList<>();
		if (root == null) {
			return list;
		}
		queue.addLast(root);
		
		while(queue.size()>0)
		{
			TreeNode node = queue.removeFirst();
			list.add(node.val);
			
			if (node.left != null) {
				queue.addLast(node.left);
			}
			if (node.right != null) {
				queue.addLast(node.right);
			}
		}
		return list;
    }
  
}