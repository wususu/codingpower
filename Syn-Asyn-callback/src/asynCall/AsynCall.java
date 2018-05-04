package asynCall;

import callback.Callback;

public class AsynCall {
	public void process(Callback callback){
		(new Thread(){
			@Override
			public void run() {
				// TODO Auto-generated method stub
				callback.call();
			}
		}).start();
	}
}
