// https://leetcode.com/problems/add-two-numbers/description/
/**
 * Definition for singly-linked list.
 */
 class ListNode {
    int val;
     ListNode next;
     ListNode(int x) { val = x; }
 }


public class AddTwoNumbers {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    	int flag = 0;
    		ListNode  pre_node = new ListNode(0), node;
    		ListNode head = pre_node;
    	while(l1 !=null || l2 != null){
    		if (l1 != null && l2!=null) {
    				node = new ListNode( l1.val +  l2.val + flag);
    				flag = node.val / 10;
    				node.val = node.val %10;
    				l1 = l1.next;
    				l2 = l2.next;
    				
    				pre_node.next = node;
			}else  {
				if (l1 == null) {
					node = new ListNode(l2.val + flag);
    					flag = node.val / 10;
    					node.val = node.val %10;
					l2 = l2.next;
					l1 =null;
					
    				pre_node.next = node;
				}else {
					node = new ListNode(l1.val + flag);
					flag =node.val / 10;
    					node.val = node.val %10;
					l1 = l1.next;
					l2 = null;
					
    				pre_node.next = node;
				}
			}
    		pre_node = pre_node.next;
    		}

    	if (flag != 0) {
    			pre_node.next = new ListNode(flag);
		}
    	return head.next;
    }
    
    public static  void printt(ListNode bb) {
    	ListNode head = bb;
    	while(head != null){
    		System.out.println(head.val);
    		head = head.next;
    	}
	}
    
    public static void main(String[] args) {
		ListNode aa = new ListNode(3);
		aa.next = new ListNode(8);
		aa.next.next = new ListNode(9);
		ListNode bb = new ListNode(7);
		ListNode result = new AddTwoNumbers().addTwoNumbers(bb, aa);
		printt(result);
	}
}
