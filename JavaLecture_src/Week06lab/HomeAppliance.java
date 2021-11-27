package Week06lab;

public abstract class HomeAppliance {
	
	private String haName;
	private boolean haPower = false;
	
	public abstract void showStatus();
	
	public abstract void menu();
	
	public HomeAppliance(String haName) {
		super();
		this.haName = haName;
	}

	public String getHaName() {
		return haName;
	}

	public void setHaName(String haName) {
		this.haName = haName;
	}

	public boolean isHaPower() {
		return haPower;
	}

	public void setHaPower(boolean haPower) {
		this.haPower = haPower;
	}
}
