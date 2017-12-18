package rebuildbinarytree;

import com.sun.org.apache.bcel.internal.generic.NEW;
import com.sun.org.apache.xpath.internal.operations.Bool;

class TreeNode {
      int val;
      TreeNode left;
      TreeNode right;
      TreeNode(int x) { val = x; }
	@Override
	public String toString() {
		return "TreeNode [val=" + val + ", left=" + left + ", right=" + right + "]";
	}

      
 };

public class Solution 
{
    public TreeNode reConstructBinaryTree(int [] pre,int [] in) 
    {
    		TreeNode root = new TreeNode(0);
    	return this.construct(root, pre, 0, pre.length-1, in, 0, in.length-1);
    }
    
    private TreeNode construct(TreeNode root, int pre[], int preStart, int preEnd, int in[], int inStart, int inEnd)
    {
    		root.val = pre[preStart];
    		Boolean posi = false;
    	int i;
    	for(i=inStart; i<=inEnd; i++)
    		{
    		if (pre[preStart] == in[i]) {
    			posi = true;
				break;
			}
    		}
    	if (posi == false) {
			throw new RuntimeException();
		}
    	if (i-inStart > 0) 
    		{
    		root.left = new TreeNode(0);
    		this.construct(root.left, pre, preStart+1, preStart+i-inStart, in, inStart, i-1);
    		}
    	if (inEnd-i>0) 
    		{
    		root.right = new TreeNode(0);
    		this.construct(root.right, pre, preStart+i-inStart+1, preEnd, in, i+1, inEnd);
    		}
    	return root;
    }
    
    private static void print(TreeNode root)
    {
    	if (root == null) {
			return ;
		}
		System.out.println(root.val);
    	print(root.left);
    	print(root.right);
    }
}