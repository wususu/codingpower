package use2stackasqueue;

import static org.junit.Assert.*;

import java.util.EmptyStackException;

import org.junit.Assert;
import org.junit.Test;

public class SolutionTest {

	@Test
	public void test() {
		Solution queue = new Solution();

		queue.push(1);
		queue.push(2);
		queue.push(3);
		
		Assert.assertEquals(1, queue.pop());
		Assert.assertEquals(2, queue.pop());
		queue.push(4);
		Assert.assertEquals(3, queue.pop());
		Assert.assertEquals(4, queue.pop());
	}
	
	@Test(expected = EmptyStackException.class)
	public void test2(){
		Solution queue = new Solution();
		queue.push(2);
		queue.pop();
		queue.pop();
	}

}
