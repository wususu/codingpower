package mirrortree;

import java.util.ArrayList;
import java.util.List;

import org.junit.Assert;
import org.junit.Test;

public class SolutionTest {

	private Solution so = new Solution();
	
	private TreeNode tree1 = new TreeNode(1);
	
	private TreeNode tree2 = new TreeNode(1);
	
	{
		tree1.left = tree2.right = new TreeNode(2);
		tree1.right = tree2.left = new TreeNode(3);
		tree1.left.left = tree2.right.right = new TreeNode(4);
		tree1.left.right = tree2.right.left = new TreeNode(5);
	}
	
	
	@Test
	public void test() {
		so.Mirror(tree1);
		List<Integer> list1 = new ArrayList<>();
		List<Integer> list2 = new ArrayList<>();
		get(list1, tree1);
		get(list2, tree2);
		Assert.assertEquals(list1, list2);
	}
	
	private List<Integer> get(List<Integer> list, TreeNode node){
		if (node != null) {
			list.add(node.val);
			get(list, node.left);
			get(list, node.right);
		}
		return list;
	}

}
