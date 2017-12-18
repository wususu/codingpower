package countof1inbinary;

public class Solution {
    public int NumberOf1(int n) {
		int count=0;
        while(n!=0)
        {
            count++;
            n = (n-1)&n;
        }
        return count;
    }
    public static void main(String[] args) {
		Solution so = new Solution();
		System.out.println(so.NumberOf1(9));
	}
}
