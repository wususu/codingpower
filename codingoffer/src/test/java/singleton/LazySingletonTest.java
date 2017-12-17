package singleton;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

import org.junit.Assert;
import org.junit.Test;

public class LazySingletonTest {

	@Test
	public void testInMultilyThread() throws Exception
	{
		ExecutorService executeService = Executors.newFixedThreadPool(8);
		final List<Future<LazySingleton>> taskList = new ArrayList<>();
		for(int i=0;i<10000000;i++)
		{
			Future<LazySingleton> task = executeService.submit(
					new Callable<LazySingleton>() 
					{
						@Override
						public LazySingleton call() throws Exception 
						{
							return LazySingleton.getInstance();
						};
					});
			taskList.add(task);
		}
		
		final LazySingleton expectInstance = LazySingleton.getInstance();
		for (Future<LazySingleton> future : taskList) {
			final LazySingleton obj = future.get();
			Assert.assertNotNull(obj);
		
			Assert.assertEquals(expectInstance, obj);
		}
		
	}
	
}
