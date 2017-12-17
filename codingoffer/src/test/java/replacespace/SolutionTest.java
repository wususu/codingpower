package replacespace;

import org.junit.Assert;
import org.junit.Test;

public class SolutionTest {

	private Solution so = new Solution();
	
	@Test
	public void test()
	{
		Assert.assertEquals("Happy%20%20hh%20a", so.replaceSpace(new StringBuffer("Happy  hh a")));
	}
}
