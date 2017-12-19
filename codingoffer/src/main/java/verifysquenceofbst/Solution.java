package verifysquenceofbst;

import java.util.Arrays;

public class Solution {
    public boolean VerifySquenceOfBST(int [] sequence) {
    	if (sequence.length == 0) {
			return false;
		}
    	boolean left = true,right= true;
    	int root = sequence[sequence.length-1];
    	int i;
    	for(i=0; i< sequence.length; i++)
    		{
    		if (sequence[i] >= root) {
				break;
			}
    		}
    	for(int j=sequence.length-1; j>=i;j--)
    		{
    		if (sequence[j] < root) {
				return false;
			}
    		}
    	
    	if (i>0) {
    			left = VerifySquenceOfBST(Arrays.copyOfRange(sequence, 0, i));
		}
    	if (i<sequence.length-1) {
        		right = VerifySquenceOfBST(Arrays.copyOfRange(sequence, i, sequence.length-1));
		}
    	return left
    			&&
    			right;
    }
}