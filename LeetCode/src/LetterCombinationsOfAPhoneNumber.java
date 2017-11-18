// P17 https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

import java.util.ArrayList;
import java.util.List;

public class LetterCombinationsOfAPhoneNumber {
	
	public void reservr(String[] dict, List<String> result,int index,String digits, StringBuffer current)
	{
		if (index == digits.length()) {
			result.add(current.toString());
			return ;
		}
		
		int num = digits.charAt(index) - '0';
		for(int i=0;i<dict[num].length();i++)
		{
			current.append(dict[num].substring(i, i+1));
			reservr(dict, result, index+1 , digits, current);
			current.delete(current.length()-1, current.length());
		}
		
	}
	
    public List<String> letterCombinations(String digits) {

    		String[] dict = new String[]{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    		List<String> result = new ArrayList<>();
    		  
            if (digits.length() == 0) {
        			return result;
        		}
    		StringBuffer current = new StringBuffer();
    		reservr(dict, result,0, digits, current);

    	return result;
    }
	public static void main(String[] args) {
		System.out.println(new LetterCombinationsOfAPhoneNumber().letterCombinations(""));
	}
}
