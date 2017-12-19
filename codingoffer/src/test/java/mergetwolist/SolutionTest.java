package mergetwolist;

import static org.junit.Assert.*;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

import org.junit.Assert;
import org.junit.Test;

public class SolutionTest {

	private Solution so = new Solution();
	
	private ListNode head1 = new ListNode(1);
	
	private ListNode head2 = new ListNode(1);

	private ListNode head3 = null;
	
	private ListNode head4= new ListNode(2);
	
	
	{
		head1.next = new ListNode(4);
		head1.next.next = new ListNode(9);
		head1.next.next.next = new ListNode(11);
		
		head2.next = new ListNode(2);
		head2.next.next = new ListNode(5);
		head2.next.next.next = new ListNode(30);
	}
	@Test
	public void test() {
		List<Integer> list = new ArrayList<>();
		List<Integer> list2 = new ArrayList<Integer>(){
			{
				add(1);add(1);add(2);add(4);add(5);add(9);add(11);add(30);
			}
		};

		ListNode pListNode = so.Merge(head1, head2);
		while(pListNode!=null)
		{
			list.add(pListNode.val);
			pListNode = pListNode.next;
		}
		Assert.assertEquals(list2, list);
		
		ListNode q = so.Merge(head3, head4);
		Assert.assertEquals(head4, q);
		
		ListNode p = so.Merge(head3, head3);
		Assert.assertEquals(null, p);

	}

}
