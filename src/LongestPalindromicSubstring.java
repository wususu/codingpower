// https://leetcode.com/problems/longest-palindromic-substring/description/

public class LongestPalindromicSubstring {
	
	public String longestPalindrome(String s) {
		char[] s1 = s.toCharArray();
		char[] s2 = new char[s1.length *2 + 1];
		int j = 0;
		for(int i=0; i<s2.length; i++){
			if ((i&1)==0) {
				s2[i] = '#';
			}else {
				s2[i] = s1[j++];
			}
		}
		int max = 0, flag = 0;
		for(int i=1; i<s2.length; i++){
			int c = 0;
			for(int k = 1; (i+k < s2.length && i-k >=0); k++){
				if (s2[i+k] == s2[i-k]) {
					c ++;
				}else {
					break;
				}
			}
			if (c > max) {
				max = c;
				flag = i;
			}
		}

		String subString = "";
		for(int i=flag-max; i<flag+max; i++){
			if (s2[i]!='#') {
				subString += s2[i];
			}
		}
		return subString;
	}
	
	public static void main(String[] args) {
		new LongestPalindromicSubstring().longestPalindrome("ashhhshd");
	}
	
	
}
