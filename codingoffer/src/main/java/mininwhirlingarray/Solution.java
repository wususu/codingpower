package mininwhirlingarray;

public class Solution {
    
	public int minNumberInRotateArray(int [] array) {
		if (array.length == 1) {
			return array[0];
		}
		int left = 0, right = array.length-1,mid;
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
}