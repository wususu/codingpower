package getnumberofk;

public class Solution {
	
    public int GetNumberOfK(int [] array , int k) {
    	if (array.length>0) {
    	       return GetNumberOfK(array, 0, array.length-1, k);
		}
    	return 0;
    }
    
    private int GetNumberOfK(int[] array, int start, int end, int k){
    	if (start>end) {
			return 0;
		}
    	if (start == end) {
			if (array[start] == k) {
				return 1;
			}else {
				return 0;
			}
		}
    	int mid = start + (end-start)/2;
    	if (array[mid] < k) {
        	return GetNumberOfK(array, mid+1, end, k);
		}else if (array[mid] > k) {
			return GetNumberOfK(array, start, mid-1, k);
		}else {
			return GetNumberOfK(array, start, mid-1, k)
					+ 
					GetNumberOfK(array, mid+1, end, k)
					+
					1;
		}
    }
    
    public static void main(String[] args) {
		System.out.println(new Solution().GetNumberOfK(new int[]{1,3,3,3,3,4,5}, 2));
	}
}