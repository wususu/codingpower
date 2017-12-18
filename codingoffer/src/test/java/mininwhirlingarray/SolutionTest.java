package mininwhirlingarray;

import static org.junit.Assert.*;

import org.junit.Assert;
import org.junit.Test;

public class SolutionTest {

	@Test
	public void test() {
		Solution solution = new Solution();
		Assert.assertEquals(1, solution.minNumberInRotateArray(new int[]{4,5,6,7,7,7,1,1,2,3}));
		Assert.assertEquals(3, solution.minNumberInRotateArray(new int[]{4,5,6,7,7,3}));
		Assert.assertEquals(4, solution.minNumberInRotateArray(new int[]{4}));

	}

	@Test(expected=RuntimeException.class)
	public void test2(){
		Solution solution = new Solution();
		Assert.assertEquals(3, solution.minNumberInRotateArray(new int[]{}));
	}
}
