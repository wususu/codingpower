package singleton;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

import org.junit.Assert;
import org.junit.Test;

import singleton.DoubleCheckSingleton;

public class DoubleCheckSingletonTest {

	
	@Test
	public void testInMultilyThread() throws Exception
	{
		ExecutorService executeService = Executors.newFixedThreadPool(8);
		final List<Future<DoubleCheckSingleton>> taskList = new ArrayList<>();
		for(int i=0;i<10000000;i++)
		{
			Future<DoubleCheckSingleton> task = executeService.submit(
					new Callable<DoubleCheckSingleton>() 
					{
						@Override
						public DoubleCheckSingleton call() throws Exception 
						{
							return DoubleCheckSingleton.getInstance();
						};
					});
			taskList.add(task);
		}
		
		final DoubleCheckSingleton expectInstance = DoubleCheckSingleton.getInstance();
		for (Future<DoubleCheckSingleton> future : taskList) {
			final DoubleCheckSingleton obj = future.get();
			Assert.assertNotNull(obj);
		
			Assert.assertEquals(expectInstance, obj);
		}
		
	}
	
	
	
}
