package permutation;

import java.util.ArrayList;
import java.util.Collections;

/**
 * 注意:
 * 1.重复元素不计算: 
 * 	if (i != deep &&str[i] == str[deep] ) {
				continue;
			}
*2.字典序:
*Collections.sort()
*
 * @author janke
 *
 */
public class Solution {
    public ArrayList<String> Permutation(String str) {
       if (str == null) {
		return null;
       	}

       	ArrayList<String> list = new ArrayList<>();
        if (str.length() == 0) {
    		return list;
    	}
       	Permutation(str.toCharArray(), list, 0);
       Collections.sort(list);
       return list;
    }
    
    private void Permutation(char[] str, ArrayList<String> list, int deep){
    	if (deep == str.length) {
			list.add(new String(str));
			return ;
		}
    	for(int i=deep; i<str.length; i++)
    		{
    		if (i != deep &&str[i] == str[deep] ) {
				continue;
			}
    		char temp = str[deep];
    			str[deep] = str[i];
    			str[i] = temp;
    			Permutation(str, list, deep+1);
	    		temp = str[deep];
	    		str[deep] = str[i];
	    		str[i] = temp;
    		}
    }

}