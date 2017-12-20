package permutation;

import static org.junit.Assert.*;

import java.util.ArrayList;

import org.junit.Assert;
import org.junit.Test;

import com.sun.javafx.geom.AreaOp.AddOp;

public class SolutionTest {

	private Solution so = new Solution();
	
	@Test
	public void test() {
		assertEquals(new ArrayList<String>(){{
			add("ABC"); add("ACB");add("BAC");add("BCA");add("CAB");add("CBA");
		}}, so.Permutation("ABC"));
		Assert.assertEquals(new ArrayList<>(), so.Permutation(""));
		Assert.assertEquals(new ArrayList<String>(){{add("aa");}}, so.Permutation("aa"));

	}

}
