package jumpingfrog2;

import static org.junit.Assert.*;

import org.junit.Assert;
import org.junit.Test;

public class SolutionTest {

	@Test
	public void test() {
		Solution so = new Solution();
		Assert.assertEquals(1, so.JumpFloorII(1));
		Assert.assertEquals(2, so.JumpFloorII(2));
		Assert.assertEquals(8, so.JumpFloorII(4));

	}

}
