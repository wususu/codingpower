// 找到数组中的最小元素，然后将它与数组的第一个元素交换位置。
// 然后再从剩下的元素中找到最小的元素，将它与数组的第二个元素交换位置。
// 不断进行这样的操作，直到将整个数组排序。
package 选择排序;

import java.util.Arrays;

public class Solution {
	
	public static void sort(int[] arry){
		if (arry.length <= 1) {
			return ;
		}
		int temp;
		int min , flag;
		for(int x=0; x<arry.length; x++){
			min = arry[x]; flag=x;
			for(int i=x; i<arry.length; i++){
				if (arry[i] < min) {
					min = arry[i];
					flag = i;
				}
			}
			temp = arry[x];
			arry[x] = arry[flag];
			arry[flag] = temp;
		}
	}
	
	public static void main(String[] args) {
		int[] numbers1 = new int[]{4, 5, -2, 3,-10, 2, 5, 18};
		int[] numbers2 = new int[]{};
		sort(numbers1);
		sort(numbers2);
		System.out.println(Arrays.toString(numbers1));
		System.out.println(Arrays.toString(numbers2));

	}
}
