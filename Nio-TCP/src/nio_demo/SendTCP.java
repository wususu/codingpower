package nio_demo;

import java.io.IOException;
import java.util.Arrays;

public class SendTCP {

	
	public static void main(String[] args) {
		if (args.length != 4) {
			return ;
		}
		String sourceIP = args[0];
		String destIP = args[2];
		Integer destPort = Integer.valueOf(args[3]);
		Integer sourcePort = Integer.valueOf(args[1]);
		System.out.println(Arrays.toString(args));
		
		System.out.println(sourceIP + " " + destIP + " " + destPort + " " + sourcePort);
		(new Thread(){
			public void run() {
				try {
					Server.start(destIP, destPort);
				} catch (IOException e) {
					// TODO Auto-generated catch block
				}
			};
		}).start();
		try {
			Client.start(sourceIP, sourcePort, destIP, destPort);
		} catch (IOException e) {
			// TODO Auto-generated catch block
		}
	}
}
