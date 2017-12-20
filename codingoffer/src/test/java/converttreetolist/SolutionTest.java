package converttreetolist;

import static org.junit.Assert.*;

import org.junit.Test;

public class SolutionTest {

	private Solution so = new Solution();
	
	private TreeNode root = new TreeNode(10);
	
	private TreeNode root2 = null;
	
	{
		root.left = new TreeNode(6);
		root.right = new TreeNode(14);
		
		root.left.left = new TreeNode(4);
		root.left.right = new TreeNode(8);
		
		root.right.left = new TreeNode(12);
		root.right.right = new TreeNode(16);
	}
	
	@Test
	public void test() {
		TreeNode node1 = so.Convert(root);
		so.Convert(root2);
		
		while(node1.right!=null)
		{
			System.out.println(node1.val);
			node1=node1.right;
		}
		System.out.println(node1.val);
		
		while(node1 !=null)
		{
			System.out.println(node1.val);
			node1=node1.left;
		}

	}

}
