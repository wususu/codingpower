package 归并排序;

import java.util.Arrays;

public class Solution {

	public static void merge(int arr[], int low, int mid, int high){
		int arrBak[] = new int[arr.length]; 
		for(int i=low; i<=high; i++){
			arrBak[i] = arr[i];
		}
		
		int l=low, r=mid+1, i;
		for(i=l; i<=high && l<=mid && r<=high; i++){
			if (arrBak[l] < arrBak[r]) {
				arr[i] = arrBak[l];
				l++;
			}else {
				arr[i] = arrBak[r];
				r++;
			}
		}
		while(l<=mid){
			arr[i++] = arrBak[l];
			l++;
		}
		while(r<=high){
			arr[i++] = arrBak[r];
			r++;
		}
	}
	
	public static void sort(int arr[], int low, int high){
		if (low==high) {
			return ;
		}
		int mid = (high - low)/2+ low;
		sort(arr, low, mid);
		sort(arr, mid+1, high);
		merge(arr, low, mid, high);
	}
	
	public static void sort(int arr[]){
		sort(arr, 0, arr.length-1);
	}
	
	public static void main(String[] args) {
		int[] numbers1 = new int[]{3, -5, 1, 0, 10, -6, 100, 2, -10, -4, 2, 8, 0, 17, 5};
		sort(numbers1);
		System.out.println(Arrays.toString(numbers1));
		int[] numbers2 = new int[]{3, -5, 1, 0, 10, -6, 100, 2, -10, -4, 8, 0, 17, 5};
		sort(numbers2);
		System.out.println(Arrays.toString(numbers2));
		int[] numbers4 = new int[]{3, -2};
		sort(numbers4);
		System.out.println(Arrays.toString(numbers4));
		int[] numbers3 = new int[]{3};
		sort(numbers3);
		System.out.println(Arrays.toString(numbers3));
	}
}
