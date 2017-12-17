package searchin2Darray;

import org.junit.Assert;
import org.junit.Test;

import searchin2Daarray.Solution;

public class SolutionTest {

	private Solution so = new Solution();
	
	@Test
	public void testSolution()
	{
		int array1[][] = {
				{2, 4, 7, 10, 23},
				{3, 7, 10, 12, 24},
				{10, 11, 12, 30, 31},
				{11, 21, 31, 32, 33}
		},
				array2[][] = {{}},
				array3[][] = {
						{1, 4, 6, 7,10}
				},
				array4[][] = {
						{2},
						{4},
						{8},
						{9}
				};
		int target1_1 = 2, target1_2 = 21, target1_3 = 11, target1_4 = 0, target1_5 = 50; 
		int target2_1 = 3;
		int target3_1 = 0, target3_2 = 11, target3_3 = 6, target3_4 = 5;
		int target4_1 = 0, target4_2 = 10, target4_3 = 4, target4_4 = 5;
		
		Assert.assertTrue(so.Find(target1_1, array1));
		Assert.assertTrue(so.Find(target1_2, array1));
		Assert.assertTrue(so.Find(target1_3, array1));
		Assert.assertFalse(so.Find(target1_4, array1));
		Assert.assertFalse(so.Find(target1_5, array1));

		Assert.assertFalse(so.Find(target2_1, array2));

		Assert.assertFalse(so.Find(target3_1, array3));
		Assert.assertFalse(so.Find(target3_2, array3));
		Assert.assertTrue(so.Find(target3_3, array3));
		Assert.assertFalse(so.Find(target3_4, array3));

		Assert.assertFalse(so.Find(target4_1, array4));
		Assert.assertFalse(so.Find(target4_2, array4));
		Assert.assertTrue(so.Find(target4_3, array4));
		Assert.assertFalse(so.Find(target4_4, array4));
	}
}
