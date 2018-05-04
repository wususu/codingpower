import asynCall.AsynCall;
import callback.Callback;
import callback.CallbackImp;
import synCall.SynCall;

public class Main {

	public static void main(String[] args) {
		Callback synCallback = new CallbackImp("Syn");
		Callback AsynCallback = new CallbackImp("Asyn");

		AsynCall asynCall = new AsynCall();
		SynCall synCall = new SynCall();
		
		// Syn always call print first
		asynCall.process(AsynCallback);
		synCall.process(synCallback);
	}
}
