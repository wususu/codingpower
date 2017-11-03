
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class LongestSubstringWithoutRep {

    public int lengthOfLongestSubstring(String s) {
       char[] characters = s.toCharArray();
       int length = 0, ret=0;
       	Map<Character, Integer> checkMap = new HashMap<Character, Integer>();
       	Set<Character> checkSet = checkMap.keySet();
       for (int i=0;i<characters.length;i++) {
		if (checkSet.contains(characters[i])) {
			ret = length>ret? length: ret;
			length = 0;
			i = checkMap.get(characters[i]);
			checkMap.clear();
			continue;
		}else {
			checkMap.put(characters[i], i);
			length++;
		}
	}
       if (length>ret) {
		ret = length;
	}
       return ret;
    }
	
    public static void main(String[] args) {
		new LongestSubstringWithoutRep().lengthOfLongestSubstring("asdqeqadsabv");
	}
}
