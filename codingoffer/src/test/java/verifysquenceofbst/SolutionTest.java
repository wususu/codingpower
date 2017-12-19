package verifysquenceofbst;

import static org.junit.Assert.*;

import org.junit.Assert;
import org.junit.Test;

public class SolutionTest {

	private Solution so = new Solution();
	
	@Test
	public void test() {
		Assert.assertTrue(so.VerifySquenceOfBST(new int[]{5, 7, 6, 9, 11, 10, 8}));
		Assert.assertFalse(so.VerifySquenceOfBST(new int[]{}));
		Assert.assertTrue(so.VerifySquenceOfBST(new int[]{5}));

	}

}
