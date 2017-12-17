package singleton;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

import org.junit.Assert;
import org.junit.Test;

public class HungrySingletonTest {

	@Test
	public void testInMultilyThread() throws Exception
	{
		ExecutorService executeService = Executors.newFixedThreadPool(8);
		final List<Future<HungrySingleton>> taskList = new ArrayList<>();
		for(int i=0;i<10000000;i++)
		{
			Future<HungrySingleton> task = executeService.submit(
					new Callable<HungrySingleton>() 
					{
						@Override
						public HungrySingleton call() throws Exception 
						{
							return HungrySingleton.getInstance();
						};
					});
			taskList.add(task);
		}
		
		final HungrySingleton expectInstance = HungrySingleton.getInstance();
		for (Future<HungrySingleton> future : taskList) {
			final HungrySingleton obj = future.get();
			Assert.assertNotNull(obj);
		
			Assert.assertEquals(expectInstance, obj);
		}
		
	}
	
}
