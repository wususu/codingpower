package 堆排序;

import java.util.Arrays;

public class Solution {
	
	public static void adjust(int[] arr, int s, int n){
		int temp = arr[s];
		int i=s*2+1;
		while(i<n){
			if (i+1<n && arr[i] < arr[i+1]) 
				i++;
			if (arr[i] <= temp) 
				break; 
			
			arr[s] = arr[i];
			s=i;
			i = i*2+1;
			
		}
		arr[s] = temp;
	}
	
	public static void sort(int[] arr){

		for(int i=(arr.length-2)/2; i>=0; i--){
			adjust(arr, i, arr.length);
		}
		int temp;
		for(int i=arr.length-1; i>0; i--){
			temp = arr[0];
			arr[0] = arr[i];
			arr[i] = temp;
			adjust(arr, 0, i);
		}
	}
	
	public static void main(String[] args) {
		int[] numbers1 = new int[]{-3,2,7,8,3,19,-20,11,26,100,28,-38,0,0,-100,1};
		sort(numbers1);
		System.out.println(Arrays.toString(numbers1));
	}
}
