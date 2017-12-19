package hassubtree;

import static org.junit.Assert.*;

import org.junit.Assert;
import org.junit.Test;

import sun.reflect.generics.tree.Tree;

public class SolutionTest {

	public Solution so = new Solution();
	
	TreeNode root1 = new TreeNode(1);
	
	TreeNode subRoot1 = new TreeNode(2);
	
	TreeNode root2 =  new TreeNode(10);
	
	TreeNode subRoot2 = new TreeNode(4);
	
	TreeNode node = null;
	
	{
		root1.left = new TreeNode(2);
		root1.right = new TreeNode(3);
		root1.left.left = new TreeNode(4);
		root1.left.right = new TreeNode(5);
		
		subRoot1.left = new TreeNode(4);
		subRoot1.right = new TreeNode(5);
	}
	
	@Test
	public void test() {

		Assert.assertTrue(so.HasSubtree(root1, subRoot1));
		Assert.assertTrue(so.HasSubtree(root1, subRoot2));
		Assert.assertTrue(so.HasSubtree(root2, root2));
		
		Assert.assertFalse(so.HasSubtree(null, null));
		Assert.assertFalse(so.HasSubtree(root1, root2));

	}

}
