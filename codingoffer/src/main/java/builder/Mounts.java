package builder;

public enum Mounts {

	PIG("pig"), HOURSE("hourse"), CAR("car"), BIKE("bike");
	
	private String type;
	
	private Mounts(String type) {
		// TODO Auto-generated constructor stub
		this.type = type;
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return type;
	}
}
