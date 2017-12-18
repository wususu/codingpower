package builder;

public enum Hair {

	LONG("long"), SHORT("short"),MIDDON("middon");
	
	private String type;
	
	private Hair(String type) {
		// TODO Auto-generated constructor stub
		this.type = type;
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return type;
	}
}
