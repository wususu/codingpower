// https://leetcode.com/problems/string-to-integer-atoi/description/

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class StringToInteger {

    public int myAtoi(String str) {
    	boolean flag = false;
    	int j = 0;
    	long value = 0;
		Pattern pattern = Pattern.compile("^\\s*?(([\\+-]{0,1})[0-9]+).*");
		Matcher matcher =  pattern.matcher(str);
		if (matcher.find()) {
			String num = matcher.group(1);
			System.out.println(num);
			String[] characters = num.split("");
			if (characters[0].equals("-")){
				flag = true;
				j = 1;
			}
			if (characters[0].equals("+")) {
				flag = false;
				j=1;
			}
			// 大于MAX_LONG
			if (characters.length - j > String.valueOf(Integer.MAX_VALUE).length()) {
				return flag == true? Integer.MIN_VALUE: Integer.MAX_VALUE;
			}
			// 小于MAX_INT
			for(int i=j; i<characters.length; i++){
				value = value*10 + Integer.valueOf(characters[i]);
			}
			// 大于MAX_INT 小于MAX_LONG
			if (value>Integer.MAX_VALUE || -value < Integer.MIN_VALUE) {
				return flag == true? Integer.MIN_VALUE: Integer.MAX_VALUE;
			}
			int result  = (int) (value);
			return flag == true? -result : result;
		}
        return 0;
    }
    
    public static void main(String[] args) {
		System.out.println(new StringToInteger().myAtoi("9223372036854775809"));
	}
}
