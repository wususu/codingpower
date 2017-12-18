package builder;

public class App {

	
	public static void main(String[] args) {
		Actor man = new Actor.Builder("man", true)
				.setHair(Hair.LONG)
				.setMounts(Mounts.PIG)
				.setWeapon(Weapon.HAMMER)
				.build();
	}
}
