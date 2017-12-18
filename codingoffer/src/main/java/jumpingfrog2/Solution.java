package jumpingfrog2;

public class Solution {
    public int JumpFloorII(int target) {
        if (target == 0) {
        	return 0;
		}
        if (target == 1) {
			return 1;
		}
    	int result = 2;
    	for(int i=1;i<target-1;i++)
        {
        	result *=2;
        }
    	return result;
    }
    
}