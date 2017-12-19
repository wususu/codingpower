package mergetwolist;


class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}

public class Solution {
    public ListNode Merge(ListNode list1,ListNode list2) {
        ListNode mergerList = new ListNode(0), head = mergerList;
        while(list1 != null && list2 != null){
        	if (list1.val < list2.val) {
				mergerList.next = list1;
				list1 = list1.next;
			}
        	else {
				mergerList.next = list2;
				list2 = list2.next;
			}
			mergerList = mergerList.next;
        }
        
        mergerList.next = list1==null?list2:list1;
        return head.next;
    }
}