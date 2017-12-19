package ispoporder;

import static org.junit.Assert.*;

import org.junit.Assert;
import org.junit.Test;

public class SolutionTest {

	private Solution so = new Solution();
	
	@Test
	public void test() {
		Assert.assertTrue(so.IsPopOrder(new int[]{1,2,3,4,5,6,7,8}, new int[]{4,5,3,2,1,6,7,8}));
	}

}
