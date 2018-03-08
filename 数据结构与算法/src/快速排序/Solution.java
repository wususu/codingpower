package 快速排序;
// 快速排序: 快速排序通过一个切分元素将数组分为两个子数组，
// 左子数组小于等于切分元素，右子数组大于等于切分元素，将这两个子数组排序也就将整个数组排序了
import java.util.Arrays;

public class Solution {

	public static int partition(int[] arr, int low, int high){
		int k = arr[low];
		while(low < high){
			while(arr[high] >= k && low<high)
				high--;
			arr[low] = arr[high];
			while(arr[low] <= k && low<high)
				low++;
			arr[high] = arr[low];
		}
		arr[high] = k;
		return high;
	}
	
	public static void qsort(int[] arr, int low, int high){
		if (low >= high) {
			return ;
		}
		int mid = partition(arr, low, high);
		qsort(arr, low, mid-1);
		qsort(arr, mid+1, high);
	}
	
	public static void sort(int[] arr){
		if (arr.length <= 1) {
			return ;
		}
		qsort(arr, 0, arr.length-1);
	}
	
	public static void main(String[] args) {
		int[] numbers1 = new int[]{2, -2, -10, 2,5, 3,5,7,9,10,12,100,-23};
		int[] numbers2 = new int[]{};
		sort(numbers1);
		sort(numbers1);
		System.out.println(Arrays.toString(numbers1));
		System.out.println(Arrays.toString(numbers2));

	}
}
