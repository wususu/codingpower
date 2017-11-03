// https://leetcode.com/problems/reverse-integer/description/

public class ReverseInteger {
    
	private int reserve(long x){
		long value=0;
		value = value*10 + x%10;
		while(x/10>0){
			x=x/10;
			value = value*10 + x%10;
		}
		if (value > Integer.MAX_VALUE ) 
			return 0;
		return (int)value;
	}
	
	public int reverse(int x)  {
		if(-x >= Integer.MAX_VALUE || -x <= Integer.MIN_VALUE)
			return 0;
		return (x<0) ? -reserve(-x) :  reserve(x);
    }
	
	public static void main(String[] args) {
		try {
			System.out.println(new ReverseInteger().reverse(-2147483648));
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
