package reverselist;


class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}

public class Solution {
    public ListNode ReverseList(ListNode head) {
    	ListNode  k, top = null;
    	while(head != null){
    			k = head;
    			head = head.next; //先取得下一个不然会被k.next = top破坏链表
    			k.next = top;
    			top = k;
    		}
    	return top;
    }
}