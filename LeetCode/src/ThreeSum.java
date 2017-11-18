// 15 Three Sums https://leetcode.com/problems/3sum/description/


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ThreeSum {

    public List<List<Integer>> threeSum(int[] nums) {
    	List<List<Integer>> result = new ArrayList<>();
        int l, r, target;	
    		Arrays.sort(nums);

        for (int i=0; i<nums.length - 2; i ++) {
			if (nums[i] > 0) 
				break;
			if (i>0 && nums[i] == nums[i-1] ) 
				continue;
			target = 0 - nums[i];
			l = i + 1;
			r = nums.length - 1;
			while(l < r)
			{
				if (target == (nums[l] + nums[r])) {
					result.add(new ArrayList<>(Arrays.asList(-target, nums[l], nums[r])));
				
					while(l<r && nums[l] == nums[l+1])
						l++;
					while(l<r && nums[r] == nums[r-1] )
						r--;
					l++;
					r--;
				}else if (target > (nums[l] + nums[r])) {
					l++;
				}else {
					r--;
				}
			}
		}
        return result;
    }
    
    public static void main(String[] args) {
		new ThreeSum().threeSum(new int[]{1,-1,-1,0});
	}
}

/**
 * 先排序,然后0-num_1 = target;
 * 接下来就是找num_2 + num_3 = target(TwoSum的解法)
 */
