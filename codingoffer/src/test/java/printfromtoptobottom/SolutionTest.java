package printfromtoptobottom;

import static org.junit.Assert.*;

import java.util.ArrayList;

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
		root.left.right.right = new TreeNode(6);


	}
	
	
	@Test
	public void test() {
		Assert.assertEquals(new ArrayList<Integer>(){{add(1);add(2);add(3);add(4);add(5);add(6);}},
				so.PrintFromTopToBottom(root));
	}

}
