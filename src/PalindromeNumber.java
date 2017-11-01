// https://leetcode.com/problems/palindrome-number/description/

public class PalindromeNumber {
	
    public boolean isPalindrome(int x) {
    	char[] c = String.valueOf(x).toCharArray();
    	char[] s = new char[c.length*2+1];
    	int j = 0;
    	for(int i=0; i<s.length; i++){
    		if ((i&1) == 0) {
				s[i] = '#';
			}else {
				s[i] = c[j++];
			}
    		}
    	int p = s.length/2;
    	for(int i=1; (i+p<s.length && p-i>=0); i++){
    		if (s[p-i] != s[p+i]) {
				return false;
			}
    		}
    	return true;
    }
    
    public static void main(String[] args) {
		new PalindromeNumber().isPalindrome(121);
	}
}
