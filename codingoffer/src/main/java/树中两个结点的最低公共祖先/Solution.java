package 树中两个结点的最低公共祖先;

import java.util.List;

import javax.management.ListenerNotFoundException;
import javax.xml.soap.Node;

class Solution{

    public static ListNode find(TreeNode a, TreeNode b){
        if(a.value == b.value){
            return new ListNode(b);
        }

        List<TreeNode> childs = a.childs;
        if(childs == null || childs.size() == 0){
            return null;
        }
        for (TreeNode child : childs) {
            ListNode next = find(child, b);
            if(next != null){
                ListNode pre = new ListNode(a);
                pre.next = next;
                return pre;
            }
        }
        return null;
    }


    public static TreeNode findLowestParent(TreeNode root, TreeNode a, TreeNode b){
    	ListNode root1 = find(root, a);
        ListNode root2 = find(root, b);
        TreeNode result = null;
        printList(root1);
        printList(root2);
        while(root1 != null && root2 != null){
        	if (root1.value == root2.value) {
				result = new TreeNode(root1.value);
				root1 = root1.next;
				root2 = root2.next;
			}else {
				return result;
			}
        }
        return result;
    }

    public static void printList(ListNode root){
        while(root != null){
            System.out.print(root.value + " ");
            root = root.next;
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        TreeNode a = new TreeNode(2);
        TreeNode b = new TreeNode(3);
        TreeNode c = new TreeNode(4);
        TreeNode d = new TreeNode(5);
        TreeNode e = new TreeNode(6);
        TreeNode f = new TreeNode(7);
        TreeNode g = new TreeNode(8);
        TreeNode h = new TreeNode(9);
        TreeNode i = new TreeNode(10);
        TreeNode j = new TreeNode(11);
        TreeNode k = new TreeNode(12);
        TreeNode l = new TreeNode(13);
        TreeNode m = new TreeNode(14);
        TreeNode n = new TreeNode(15);

        i.addChild(m);
        m.addChild(n);
        i.addChild(j);
        i.addChild(k);
        k.addChild(l);

        e.addChild(f);
        e.addChild(g);
        f.addChild(h);

        a.addChild(d);
        d.addChild(e);

        b.addChild(c);
        b.addChild(i);

        root.addChild(a);
        root.addChild(b);
        
        TreeNode parent = findLowestParent(root, n, k);
        System.out.println(parent.value);
    }

}