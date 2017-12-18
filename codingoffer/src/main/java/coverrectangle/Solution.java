package coverrectangle;

public class Solution {
    public int RectCover(int target) {
    	if(target < 0)
    		{
    		throw new RuntimeException();
    		}
    	if (target <= 2) {
			return target;
		}
    	int one = 1;
    	int two = 2;
    	int theN = 0;
    	for(int i=3; i<=target; i++){
    		theN = one + two;
    		one = two;
    		two = theN;
    		}
    	return theN;
    }
}