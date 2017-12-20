package depthofbinarytree;

import static org.junit.Assert.*;

import org.junit.Assert;
import org.junit.Test;

public class SolutionTest {

	private Solution so = new Solution();
	
	private TreeNode root = new TreeNode(1);
	
	{
		root.left = new TreeNode(2);
		root.right = new TreeNode(3);
		
		root.left.left = new TreeNode(4);
		root.left.right = new TreeNode(5);
		
		root.right.right = new TreeNode(6);
		
		root.left.right.left = new TreeNode(7);
	}
	
	@Test
	public void test() {
		Assert.assertEquals(4, so.TreeDepth(root));
		Assert.assertEquals(0, so.TreeDepth(null));

	}

}
