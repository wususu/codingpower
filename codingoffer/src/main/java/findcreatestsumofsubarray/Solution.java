package findcreatestsumofsubarray;

import com.sun.org.apache.bcel.internal.generic.NEW;

public class Solution {
    public int FindGreatestSumOfSubArray(int[] array) {
    	if (array.length == 0) {
			return 0;
		}
        int sum=Integer.MIN_VALUE;
        int temp = Integer.MIN_VALUE;
        for (int i : array) {
        	if (temp<=0) {
				temp = i;
			}
        	else {
				temp += i;
			}
        	if (temp>sum) {
				sum=temp;
			}
		}
        return sum;
    }
    
    public static void main(String[] args) {
		System.out.println(new Solution().FindGreatestSumOfSubArray(new int[]{}));
	}
}