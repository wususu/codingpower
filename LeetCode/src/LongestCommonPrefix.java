import java.util.Arrays;

// 14 https://leetcode.com/problems/longest-common-prefix/description/

public class LongestCommonPrefix {
	
    public String longestCommonPrefix(String[] strs) {
    	if (strs.length < 1) {
			return "";
		}
    	if (strs.length == 1) {
			return strs[0];
		}
        int size = strs[0].length();
        	String min = strs[0];
        
    	for (String string : strs) {
    		if (string.length() < size) {
				min = string;
				size = string.length();
			}
		}
    	for (String string : strs) {
			if (string.length() >= size ) {
				char[] a = min.toCharArray();
				char[] b = string.toCharArray();
				for(int i=0; i<a.length; i++){
					if (a[i] != b[i]) {
						min = min.substring(0, i);
						break;
					}
				}
			}
		}
    	return min;
    }
    public static void main(String[] args) {
    	new LongestCommonPrefix().longestCommonPrefix( new String[]{"a", "b"});
	}
}

/**
 * 注意没有公共前缀和字符串数组为空的情况
 */
