package mininwhirlingarray;

import org.junit.Assert;

public class Solution {
    
	public int minNumberInRotateArray(int [] array) {
		if (array.length == 1) {
			return array[0];
		}
		int left = 0, right = array.length-1,mid,min=array[0];
		if (array[left] < array[right]) {
			for (int i : array) {
				if (i<min) {
					min = i;
				}
			}
			return min;
		}
		while(left < right)
		{
			mid = left + (right-left)/2;

			if (left+1 == right) {
				return array[left] < array[right] ? array[left] : array[right]; 
			}
			if (array[left] > array[mid]){
				right = mid;
			}
			if (array[mid] > array[right]) {
				left = mid;
			}
		}
		throw new RuntimeException();
    }
	
	public static void main(String[] args) {
		Solution solution = new Solution();
		System.out.println(solution.minNumberInRotateArray(new int[]{1,2,3,4}));

	}
}