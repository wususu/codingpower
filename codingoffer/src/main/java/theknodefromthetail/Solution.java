package theknodefromthetail;

class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}

public class Solution {
    public ListNode FindKthToTail(ListNode head,int k) {
    	if (head==null) {
			return head;
		}
    		ListNode p = head, h = head;
    	int i;
    	for(i=0;i<k && p!=null;i++)
	    	{
	    		p = p.next;
	    	}
    	if (i != k) {
			return null;
		}
    	while(p!=null){
    			p = p.next;
    			h = h.next;
    		}
    	return h;
    }
}