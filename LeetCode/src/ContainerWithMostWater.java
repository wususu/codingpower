// 11 https://leetcode.com/problems/container-with-most-water/description/

public class ContainerWithMostWater {

	private int min(int a, int b) {
		return a<b?a:b;
	}
	
	public int maxArea(int[] height) {
        int l,r, max=0, lh, rh,sum;
        	lh = height[0];
        	l = 0;
        	rh = height[height.length-1];
        	r = height.length - 1;

       while(r>l)
        {
    	   		sum = (r-l)*min(rh, lh);
    	   if (sum>max) {
			max = sum;
    	   		}
    	   if (rh < lh) {
    		   do {
    			   			r--;
    			   	} while (height[r] <= rh&&r>l);
        			rh = height[r];
			}
    	   else {
		        do{
		        		l++;
		        	}while(height[l] <= lh && l<r);
		        lh = height[l];
    	   		}
          }
    	return max;
    }
	public static void main(String[] args) {
		new ContainerWithMostWater().maxArea(new int[]{1,2,43,14,1,43,1,43,15,1});
	}
}

/**
从两边开始,矮的向中间跳
*/