package 树中两个结点的最低公共祖先;

import java.util.ArrayList;
import java.util.List;

class TreeNode{

    public int value;

    public TreeNode(int value){
        this.value = value;
    }

    public List<TreeNode> childs = new ArrayList<>();

    public void addChild(TreeNode child){
        this.childs.add(child);
    }
}