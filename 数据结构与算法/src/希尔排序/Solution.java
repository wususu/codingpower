// 希尔排序使用插入排序对间隔 h 的序列进行排序，如果 h 很大，那么元素就能很快的移到很远的地方。
// 通过不断减小 h，最后令 h=1，就可以使得整个数组是有序的。
package 希尔排序;

import java.util.Arrays;

public class Solution {

	public static void sort(int arr[]){
		if (arr.length <= 1) {
			return ;
		}
		int temp;
		int h = arr.length/3;
		while(h>0){
			for(int i=h; i<arr.length; i++){
				for(int j=i; j<arr.length; j+=h){
					if (arr[j] < arr[i]) {
						temp = arr[i];
						arr[i] = arr[j];
						arr[j] = temp;
					}
				}
			}
			h /= 3;
		}
	}
	
	public static void main(String[] args) {
		int[] numbers1 = new int[]{2, -10, -4, 2, 8, 0, 17, 5,2, -10, -4, 2, 8, 0, 17, 5};
		int[] numbers2 = new int[]{2};
		sort(numbers1);
		sort(numbers2);
		System.out.println(Arrays.toString(numbers1));
		System.out.println(Arrays.toString(numbers2));
	}
}
