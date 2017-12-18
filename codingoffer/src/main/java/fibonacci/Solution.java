package fibonacci;

public class Solution {
    public int Fibonacci(int n) {
    	if (n<0) {
			throw new RuntimeException();
		}
    	if (n < 2) {
			return n;
		}
    	int one = 0;
    	int two = 1;
    	int theN = 0;
    	for(int i=2;i<=n;i++)
	    	{
	    		theN = one + two;
	    		one = two;
	    		two = theN;
	    	}
    	return theN;
    }
}