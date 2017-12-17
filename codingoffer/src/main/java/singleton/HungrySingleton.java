package singleton;

import org.junit.runner.notification.RunListener.ThreadSafe;

@ThreadSafe
public final class HungrySingleton {
	
	private static HungrySingleton instance = new HungrySingleton();
	
	public static HungrySingleton getInstance()
	{
		return instance;
	}
	
	private HungrySingleton()
	{
	}
}
