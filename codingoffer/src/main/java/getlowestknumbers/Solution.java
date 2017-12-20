package getlowestknumbers;

import java.util.ArrayList;

public class Solution {
    
	public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
		ArrayList<Integer> list = new ArrayList<>();
		int index;
		if (input.length == 0) {
			return list;
		}
		if (input.length < k) {
			return list;
		}
        if(k==0)
        {
            return list;
        }
		int start = 0, end=input.length-1;
		index = prim(input, start, end);
		while(index != k-1){
			if (index < k-1) {
				start = index+1;
				index = prim(input, start, end);
			}else{
				end = index-1;
				index = prim(input, start, end);
			}
		}
			for(int i=0;i<=index; i++)
				list.add(input[i]);
		
		return list;
    }
    
    private int prim(int[] input, int start, int end){
    	int val = input[start];
    	while(start<end){
	    	while(start<end && input[end] > val)
	    			end--;
	    		input[start] = input[end];
	    	while(start<end && input[start] <= val)
	    			start++;
	    		input[end] = input[start];
    		}
    	System.out.println(start);
    		input[start] = val;
    	return start;
    }
    

    public static void main(String[] args) {
    	System.out.println(new Solution().GetLeastNumbers_Solution(new int[]{6,9,2,3,4,5,2,3,4}, 5));

	}
}