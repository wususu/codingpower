package printmatrix;
import java.util.ArrayList;
import java.util.List;

public class Solution {
    public ArrayList<Integer> printMatrix(int [][] matrix) {
    	ArrayList<Integer> list = new ArrayList<>();
    	get(list, matrix, 0, 0, matrix.length, matrix[0].length);
    	return list;
    }
    
    private void get(ArrayList<Integer> list, int[][] matrix, int point_x, int point_y, int hight, int weight){
    	if (hight  == 0 ||  weight == 0) {
			return ;
		}
    	if (hight == 1) {
			for(int i=0;i<weight; i++)
			{
				list.add(matrix[point_x][point_y+i]);
			}
			return ;
		}
    	
    	if (weight == 1) {
			for(int i=0;i<hight; i++)
			{
				list.add(matrix[point_x+i][point_y]);
			}
			return ;
		}
    	
    	for(int i=0;i<weight; i++)
    	{
    		list.add(matrix[point_x][point_y+i]);
    	}
    	for(int i=1; i<hight; i++)
    	{
    		list.add(matrix[point_x+i][point_y+weight-1]);
    	}
    	for(int i=1;i<weight;i++)
    	{
    		list.add(matrix[point_x+hight-1][point_y+weight-1-i]);
    	}
    	if (hight > 2) {
			for(int i=1; i<hight-1; i++)
			{
				list.add(matrix[point_x+hight-1-i][point_y]);
			}
		}
     get(list, matrix, point_x+1, point_y+1, hight-2, weight-2);	
    }
    
    
    public static void main(String[] args) {
		int [][] a = {
				{1,2,3,4},
				{5,6,7,8},
				{9,10,11,12}
		};
		List<Integer> list = (new Solution()).printMatrix(a);
		System.out.println(list);
	}
}