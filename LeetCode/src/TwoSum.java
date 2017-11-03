// https://leetcode.com/problems/two-sum/description/
	
import java.util.Arrays;

public class TwoSum {

	    public int[] twoSum(int[] nums, int target) {
	    int[] copyNums = Arrays.copyOf(nums, nums.length);
	        Arrays.sort(nums);
	        int i = 0, j = nums.length - 1, sum=0, head=-1, tail=-1;
	        while(i<j){
	        		sum = nums[i] + nums[j];
	        	if (sum == target) {
	        		break;
	        		}
	        	if (sum < target) {
					i++;
					continue;
				}else {
					j--;
					continue;
				}
	        }
	        for(int k=0; k<copyNums.length;k++){
	        	if (copyNums[k] == nums[i] || copyNums[k] == nums[j]){
	        		if (head != -1) {
						tail = k;
						break;
					}
					head = k;
	        		}
	        }
	        return new int[]{head, tail};
	    }
	    
	    public static void main(String[] args) {
			int[] bb = new TwoSum().twoSum(new int[]{3,2,4}, 6);
			System.out.println(Arrays.toString(bb));
		}
}
