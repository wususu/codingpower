package minnumberinstack;

import java.util.Stack;

public class Solution {

	Stack< Integer> stack = new Stack<>();
	
	Stack< Integer> minStack = new Stack<>();
    
	Integer miInteger = Integer.MAX_VALUE;
	
    public void push(int node) {
    	if (node < miInteger) {
			miInteger = node;
		}
    	stack.push(node);
    	minStack.push(miInteger);
    }
    
    public void pop() {
    minStack.pop();    
    	stack.pop();
    }
    
    public int top() {
        return stack.peek();
    }
    
    public int min() {
        return minStack.peek();
    }
}