package builder;

public enum Weapon {

	SWORD("sword"), KNIFE("knife"), HAMMER("hammer");
	
	private String type;
	
	private Weapon(String type) {
		// TODO Auto-generated constructor stub
		this.type = type;
	}
	
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return type;
	}
}
