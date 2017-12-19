package evenbeforeodd;

import java.util.Arrays;

public class Solution {
    public void reOrderArray(int [] array) {
    	int[] array2 = new int[array.length];
    	int left=0, right=array.length-1, p1=0,p2=array.length-1;
    	while(p2>=0 || p1<array.length)
	    	{
	    		if (p1<array.length && (array[p1] & 1)==1) {
					array2[left++] = array[p1++];
				}
	    		else {
					p1++;
				}
	    		if (p2>=0 && (array[p2] & 1) == 0) {
					array2[right--] = array[p2--];
				}
	    		else {
					p2--;
				}
	    	}
    		//通过改变对象的域来改变值，数组也是对象
    	for(int i=0;i<array.length;i++)
	    	{
	    		array[i] = array2[i];
	    	}
    }
    
    public static void main(String[] args) {
		Solution so = new Solution();
		int[] a= new int[]{1,2,3,4,5,6,7,8,9};
		so.reOrderArray(a);
		System.out.println(Arrays.toString(a));
	}
}