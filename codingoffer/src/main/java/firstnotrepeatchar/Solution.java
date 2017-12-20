package firstnotrepeatchar;

import java.util.Arrays;

public class Solution {
    public int FirstNotRepeatingChar(String str) {
        char[] a = str.toCharArray();
        int[] posi = new int[125];
        int min=0;
        for(int i=0;i<a.length;i++)
        {
        	if (posi[a[i]] !=0) {
            	posi[a[i]] = -1;
			}else {
				posi[a[i]] = i+1;
			}
        }
        for (int i : posi) {
			if (i > 0) {
				if (min == 0) {
					min = i;
				}else {
					min = i<min?i:min;
				}
			}
		}
        return min-1;
    }
    
    public static void main(String[] args) {
		System.out.println(new Solution().FirstNotRepeatingChar("ABCBADD"));
	}
}