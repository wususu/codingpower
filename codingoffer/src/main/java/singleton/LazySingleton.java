package singleton;

import org.junit.runner.notification.RunListener.ThreadSafe;

@ThreadSafe
public final class LazySingleton 
{
		
	public static LazySingleton getInstance()
	{
		return Inner.instance;
	}
	
	private LazySingleton()
	{
	}
	
	private static class Inner
	{
		public static LazySingleton instance = new LazySingleton();
	}
}
