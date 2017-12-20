package morethanhalfnum;

public class Solution {
    public int MoreThanHalfNum_Solution(int [] array) {
    	if (array.length == 1) {
			return array[0];
		}
        int num=0, count=0;
    	for (int i : array) {
    		if (count < 2 && i != num) {
				count = 1;
				num = i;
				continue;
			}
			if (i == num) {
				count++;
			}
		}
    	
    	if (count>1) {
        	return num;
		}
    	return 0;
    }
    
    public static void main(String[] args) {
		System.out.println(new Solution().MoreThanHalfNum_Solution(new int[]{1,3,2,3,3,3}));
	}
}