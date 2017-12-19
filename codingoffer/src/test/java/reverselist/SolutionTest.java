package reverselist;
import java.util.ArrayList;
import java.util.List;

import org.junit.Assert;
import org.junit.Test;

import com.sun.xml.internal.messaging.saaj.packaging.mime.Header;

public class SolutionTest {

	public Solution so = new Solution();
	
	public ListNode head = new ListNode(1);
	
	public ListNode head2 = new ListNode(9);
	
	public ListNode head3 = null;

	public List<Integer> list = new ArrayList<>();
	
	{
		head.next = new ListNode(2);
		head.next.next = new ListNode(3);
		head.next.next.next = new ListNode(4);
		
		ListNode pListNode  = head;
		while(pListNode != null)
		{
			list.add(pListNode.val);
			pListNode = pListNode.next;
		}
	}
	
	@Test
	public void test() {
		ListNode tail = so.ReverseList(head);
		List<Integer> tails  = new ArrayList<>();
		while(tail != null)
		{
			System.out.println(tail.val);
			tails.add(0, tail.val);
			tail = tail.next;
		}
		Assert.assertEquals(this.list, tails);
		
		
		Assert.assertEquals(head2, so.ReverseList(head2));
		Assert.assertEquals(head3, so.ReverseList(head3));

	}

}
