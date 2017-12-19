package rebuildbinarytree;


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.junit.Assert;
import org.junit.Test;

public class SolutionTest {

	private Solution so = new Solution();
	
	private List<Integer> list_1 = new ArrayList<>();
	
	private List<Integer> list_2 = new ArrayList<>();

	
	@Test
	public void test() {
		int[] pre = new int[]{1, 2,4,7,3,5,6,8}, in = new  int[]{4,7,2,1,5,3,8,6};
		TreeNode node = so.reConstructBinaryTree(pre, in);
		toPre(node);
		toIn(node);
		for (int i=0; i<pre.length; i++)
		{
			Assert.assertEquals((int)list_1.get(i), pre[i]);
			Assert.assertEquals((int)list_2.get(i), in[i]);
		}
		
	}
	
	private void toPre(TreeNode node)
	{
		if (node != null) {
			list_1.add(node.val);
			toPre(node.left);
			toPre(node.right);
		}
	}
	
	private void toIn(TreeNode node)
	{
		if (node != null) {
			toIn(node.left);
			list_2.add(node.val);
			toIn(node.right);
		}
	}

}
