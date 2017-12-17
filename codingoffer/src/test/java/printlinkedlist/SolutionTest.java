package printlinkedlist;

import java.util.ArrayList;

import org.junit.Assert;
import org.junit.Test;

import com.sun.org.apache.bcel.internal.generic.NEW;

public class SolutionTest {

	private Solution so = new Solution();
	
	@Test
	public void test()
	{
		ListNode a = new ListNode(1);
		a.next = new ListNode(2);
		a.next.next = new ListNode(3);
		a.next.next.next = new ListNode(4);
		int[] expect = new int[]{4, 3, 2, 1};
		 ArrayList<Integer> list = so.printListFromTailToHead(a);
		for(int i=0; i<expect.length; i++)
		{
			Assert.assertEquals(expect[i], (int)list.get(i));
		}
	}
}
