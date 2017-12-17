package singleton;

import org.junit.runner.notification.RunListener.ThreadSafe;

@ThreadSafe
public final class DoubleCheckSingleton {

	private static volatile DoubleCheckSingleton instance;
	
	public static DoubleCheckSingleton getInstance()
	{
		if (instance == null) {
			synchronized (DoubleCheckSingleton.class) {
				if (instance == null) {
					instance = new DoubleCheckSingleton();
				}
			}
		}
		return instance;
	}
	
}
