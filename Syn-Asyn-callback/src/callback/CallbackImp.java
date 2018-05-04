package callback;

public class CallbackImp implements Callback{
	
	public CallbackImp(String msg) {
		// TODO Auto-generated constructor stub
		this.msg = msg;
	}
	
	private String msg;
	
	@Override
	public void call() {
		// TODO Auto-generated method stub
		System.out.println("This is a 【"+ msg+"】 CallBack method");
	}

}
