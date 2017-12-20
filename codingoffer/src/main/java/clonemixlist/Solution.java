package clonemixlist;

class RandomListNode {
    int label;
    RandomListNode next = null;
    RandomListNode random = null;

    RandomListNode(int label) {
        this.label = label;
    }
}

public class Solution {
	
	public RandomListNode pHead = new RandomListNode(1);
	{
		pHead.next = new RandomListNode(2);
		pHead.next.next = new RandomListNode(3);
		pHead.next.next.next = new RandomListNode(4);
		pHead.next.next.next.next = new RandomListNode(5);
		
		pHead.random = pHead.next.next.next.next;
		pHead.next.random = pHead.next.next.next;
		pHead.next.next.random = pHead;
		pHead.next.next.next.random = pHead.next;
		pHead.next.next.next.next.random = pHead.next.next.next.next;

	}
	
    public RandomListNode Clone(RandomListNode pHead){
    	if (pHead == null) {
			return null;
		}
    	int count=0;
    		RandomListNode root=pHead, p=null, k, r1=null,r2=null;;
    	while(pHead != null){
    			count++;
    			p = new RandomListNode(pHead.label);
    			k = pHead.next; //暂存
    			pHead.next = p;
    			p.next = k;
    			pHead = k;
    		}
		p = root;
    	for(int i=1; i<=count*2; i++){
    		if ((i&1) != 1) {
				p=p.next;
				continue;
			}
    		if (p.random!=null) {
    				p.next.random = p.random.next;
			}
    			p = p.next;
    		}
    		p = root;
    		count=0;
    		r1 = p;
    		r2 = p.next;
    		p=p.next.next;
    		pHead = r1;
    		root = r2;
    	while(p!=null)
    		{
    			count++;
    		if ((count&1) == 1) {
    				r1.next = p;
    				r1 = r1.next;
			}else {
				r2.next = p;
				r2 = r2.next;
			}
    		p=p.next;
    		}
    		r1.next = r2.next = null;
    	return root;
    }

}