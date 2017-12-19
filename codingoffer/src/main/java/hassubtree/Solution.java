package hassubtree;

import javax.tools.Tool;

import com.sun.corba.se.spi.orbutil.fsm.Guard.Result;

class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;
    }
}

public class Solution {
    public boolean HasSubtree(TreeNode root1,TreeNode root2) {
        boolean result = false;
        if (root1 != null&&root2!=null) {
	    		result = find(root1, root2);
	    	if (result == false) {
				result = HasSubtree(root1.left, root2);
			}
	    	if (result == false) {
				result = HasSubtree(root1.right, root2);
			}
	}
    	return result;
    }
    
    private boolean find(TreeNode root1, TreeNode root2){
    	if (root2 == null) {
			return true;
		}
    	if (root1 == null) {
			return false;
		}
    	if (root1.val != root2.val) {
			return false;
		}
    	
    	return find(root1.left, root2.left) 
    			&&
    			find(root1.right, root2.right);
    }
}