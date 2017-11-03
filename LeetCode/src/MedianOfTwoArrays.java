import java.util.Arrays;

public class MedianOfTwoArrays {

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
    	int leng1 = nums1.length, leng2 = nums2.length, i=0;
    	int [] data = new int[4];
    	double result = 0;
    	
    	if ((leng1 &1) == 1 && leng1!=0) {
			data[i++] = nums1[leng1/2];
		}else {
			data[i++] = nums1[leng1/2-1];
			data[i++] = nums1[leng1/2];
		}
    	
    	if ((leng2 & 1) == 1 && leng2 !=0) {
			data[i++] = nums2[leng1];
		}else {
			data[i++] = nums2[leng2/2-1];
			data[i++] = nums2[leng2/2];
		}
    	
    	for(int j=0;j<i;j++){
    		result += data[j];
    		}
    	result/=i;
    	System.out.println(result);
    	return result;
    }
    
    public static void main(String[] args) {
		new MedianOfTwoArrays().findMedianSortedArrays(new int[]{1,2,4,5,6}, new int[]{2,3,4,7,8,10});
	}
	
}
