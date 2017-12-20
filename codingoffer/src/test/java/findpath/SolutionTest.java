package findpath;

import static org.junit.Assert.*;

import java.util.ArrayList;

import org.junit.Assert;
import org.junit.Test;

public class SolutionTest {

	private Solution so = new Solution();
	
	private TreeNode root = new TreeNode(1);
	
	private TreeNode root2 = null;

	
	{
		root.left = new TreeNode(3);
		root.right = new TreeNode(5);
		
		root.left.left = new TreeNode(5);
		root.left.right = new TreeNode( 11);
		
		root.right.left = new TreeNode(3);
		root.right.right = new TreeNode(10);
		
		
	}
	
	@Test
	public void test() {
		Assert.assertEquals(new ArrayList<ArrayList<Integer>>(){{
			add(new ArrayList<Integer>(){{
				add(1);add(3);add(5);
			}});
			add(new ArrayList<Integer>(){
				{
					add(1); add(5); add(3);
				}
			});
		}}, so.FindPath(root, 9));
		
		Assert.assertEquals(new ArrayList<ArrayList<Integer>>(),so.FindPath(root2, 2));

	}

}
