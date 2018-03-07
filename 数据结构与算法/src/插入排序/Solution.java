package 插入排序;

import java.util.Arrays;

public class Solution {
	
	public static void sort(int[] arr){
		if (arr.length <= 1) {
			return ;
		}
		int temp;
		for(int i=1; i< arr.length; i++){
			for(int j=0; j< i; j++){
				if (arr[i] < arr[j]) {
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	
	public static void main(String[] args) {
		int numbers1[] = new int[]{2, 7, -10, 3, 8, -2, 0, 43};
		int numbers2[] = new int[]{};
		sort(numbers1);
		sort(numbers2);
		System.out.println(Arrays.toString(numbers1));
		System.out.println(Arrays.toString(numbers2));
	}
}
