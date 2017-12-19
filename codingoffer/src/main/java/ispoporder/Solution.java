package ispoporder;
import java.util.Stack;

public class Solution {
	
	private Stack<Integer> stack = new Stack<>();
	
    public boolean IsPopOrder(int [] pushA,int [] popA) {
    	if (pushA.length != popA.length) {
			return false;
		}
    	if (pushA.length == 0) {
			return false;
		}
    	int k=0, i=1,num=0;
    		stack.push(pushA[0]);
    	while(k<popA.length)
    		{
    		if (i > popA.length) { // 如果长度已经不匹配,提前退出,避免长时间循环
				return false;
			}
    		if (stack.size()>0 && stack.peek() == popA[k]) {
				stack.pop();
				num--;
				k++;
				continue;
			}else {
				if (i<pushA.length) {
					stack.push(pushA[i]);
					num++;
				}
				i++;
			}
    		}
    	if (k==popA.length) {
			return true;
		}
    	return false;
    }
}