package replacespace;

public class Solution 
{
    public String replaceSpace(StringBuffer str) 
    {
    		StringBuffer sf = new StringBuffer();
    	char[] array = str.toString().toCharArray();
    	for (char c : array) 
    	{
			if (c == ' ') 
			{
				sf.append("%20");
			}
			else 
			{
				sf.append(c);
			}
		}
    	return sf.toString();
    }
}