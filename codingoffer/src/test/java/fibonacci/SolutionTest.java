package fibonacci;

import static org.junit.Assert.*;

import org.junit.Assert;
import org.junit.Test;

public class SolutionTest {

	@Test
	public void test() {
		Solution solution = new Solution();
		Assert.assertEquals(3, solution.Fibonacci(4));
	}

}
