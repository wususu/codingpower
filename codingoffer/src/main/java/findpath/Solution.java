package findpath;
import java.util.ArrayList;

class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;
    }
}

public class Solution {
    
	public ArrayList<ArrayList<Integer>> FindPath(TreeNode root,int target) {
    		ArrayList<ArrayList<Integer>> pathList = new ArrayList<>();
    		ArrayList<Integer> list = new ArrayList<>();
    		FindPath(root, target, list, 0, pathList);
    	return pathList;
    }
    
    private void FindPath(TreeNode node, int targer, 
    		ArrayList<Integer> list, int sum,ArrayList<ArrayList<Integer>> pathLis){
    	if (node == null) {
			return ;
		}
    		list.add(node.val);
    		sum += node.val;

    	if (sum == targer && node.left==null && node.right==null) {
    			pathLis.add((ArrayList<Integer>)list.clone());
		}
    	if (node.left != null) {
    			FindPath(node.left, targer, list, sum, pathLis);
		}
    	if (node.right != null) {
    		FindPath(node.right, targer, list, sum, pathLis);
		}
    		list.remove(list.size()-1);
    }
}