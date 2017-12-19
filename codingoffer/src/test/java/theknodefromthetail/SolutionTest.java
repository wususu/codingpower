package theknodefromthetail;

import org.junit.Assert;
import org.junit.Test;

public class SolutionTest {

	ListNode head = new ListNode(1);
	Solution so = new Solution();

	{
		head.next = new ListNode(2);
		head.next.next = new ListNode(3);
		head.next.next.next = new ListNode(4);
		head.next.next.next.next = new ListNode(5);
		head.next.next.next.next.next = new ListNode(6);
	}
	
	@Test
	public void test() {
		Assert.assertEquals(null, so.FindKthToTail(head, 7));
	}
	
	@Test
	public void test1()
	{
		Assert.assertEquals(head.next.next, so.FindKthToTail(head, 4));
		Assert.assertEquals(head, so.FindKthToTail(head, 6));
		Assert.assertEquals(null, so.FindKthToTail(null, 6));

	}

}
