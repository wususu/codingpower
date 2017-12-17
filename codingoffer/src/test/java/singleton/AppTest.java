package singleton;

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

public class AppTest {
	public static void main(String[] args) {
		Result result = JUnitCore.runClasses(DoubleCheckSingletonTest.class);
		Result result2 = JUnitCore.runClasses(HungrySingletonTest.class);


	}
}
