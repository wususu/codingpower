package builder;

public final class Actor {

	private final String name;
	
	private final boolean sex;
	
	private String describtion;
	
	private Hair hair;
	
	private Mounts mounts;
	
	private Weapon weapon;

	public Actor(Builder builder) {
		super();
		this.name = builder.name;
		this.sex = builder.sex;
		this.describtion = builder.describtion;
		this.hair = builder.hair;
		this.mounts = builder.mounts;
		this.weapon = builder.weapon;
	}
	
	public String getDescribtion() {
		return describtion;
	}

	public void setDescribtion(String describtion) {
		this.describtion = describtion;
	}

	public Hair getHair() {
		return hair;
	}

	public void setHair(Hair hair) {
		this.hair = hair;
	}

	public Mounts getMounts() {
		return mounts;
	}

	public void setMounts(Mounts mounts) {
		this.mounts = mounts;
	}

	public Weapon getWeapon() {
		return weapon;
	}

	public void setWeapon(Weapon weapon) {
		this.weapon = weapon;
	}

	public String getName() {
		return name;
	}

	public boolean isSex() {
		return sex;
	}


	public static class Builder
	{
		private final String name;
		
		private final boolean sex;
		
		private String describtion;
		
		private Hair hair;
		
		private Mounts mounts;
		
		private Weapon weapon;
		
		public Builder(final String name, final boolean sex) {
			// TODO Auto-generated constructor stub
			this.name = name;
			this.sex = sex;
		}
		
		public Builder sexDesc(String desc){
			this.describtion = desc;
			return this;
		}
		
		public Builder setHair(Hair hair)
		{
			this.hair = hair;
			return this;
		}
		
		public Builder setWeapon(Weapon weapon){
			this.weapon = weapon;
			return this;
		}
		
		public Builder setMounts(Mounts mounts)
		{
			this.mounts = mounts;
			return this;
		}
		
		public Actor build(){
			return new Actor(this);
		}
	}

	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((describtion == null) ? 0 : describtion.hashCode());
		result = prime * result + ((hair == null) ? 0 : hair.hashCode());
		result = prime * result + ((mounts == null) ? 0 : mounts.hashCode());
		result = prime * result + ((name == null) ? 0 : name.hashCode());
		result = prime * result + (sex ? 1231 : 1237);
		result = prime * result + ((weapon == null) ? 0 : weapon.hashCode());
		return result;
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		Actor other = (Actor) obj;
		if (describtion == null) {
			if (other.describtion != null)
				return false;
		} else if (!describtion.equals(other.describtion))
			return false;
		if (hair != other.hair)
			return false;
		if (mounts != other.mounts)
			return false;
		if (name == null) {
			if (other.name != null)
				return false;
		} else if (!name.equals(other.name))
			return false;
		if (sex != other.sex)
			return false;
		if (weapon != other.weapon)
			return false;
		return true;
	}
}
