package searchin2Daarray;

public class Solution {
    public boolean Find(int target, int [][] array) {
    	if (array .length == 0) {
			return false;
		}
    	
    	int xSize = array[0].length;
    	int ySize = array.length;
    	int y = 0, x = xSize-1;
    	
    	while(y < ySize && x >= 0)
    		{
    		if (array[y][x] == target) {
				return true;
			}
    		else if (target > array[y][x]) {
				y +=1;
			}
    		else {
				x-=1;
			}
    		}
    	return false;
    }
}