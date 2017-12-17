package printlinkedlist;
import java.util.ArrayList;

class ListNode 
{
	int val;
     ListNode next = null;
     ListNode(int val) 
     {
            this.val = val;
     }
 }
public class Solution {
    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) 
    {
    		ArrayList<Integer> list = new ArrayList<>();
    		print(list, listNode);
    	return list;
    }
    
    private void print(ArrayList<Integer> list, ListNode listNode)
    {
    	if (listNode == null) {
			return ;
		}
    		print(list, listNode.next);
    		list.add(listNode.val);
    }
}