package Project03;

public class TaxPayer {
	private String name;
	private String number;
	private int earnings;
	
	public TaxPayer(String name, String number, int earnings) {
		this.name = name;
		this.number = number;
		this.earnings = earnings;
	}
	
	public double getTax() {
		return earnings*0.1;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getNumber() {
		return number;
	}

	public void setNumber(String number) {
		this.number = number;
	}

	public int getEarnings() {
		return earnings;
	}

	public void setEarnings(int earnings) {
		this.earnings = earnings;
	}

	@Override
	public String toString() {
		String str = "납세자: "+this.name;
		str += "\n식별번호: "+this.number;
		str += "\n소득금액: "+this.earnings;
		str += "\n식별번호: "+this.getTax();
		return str;
	}
	
	
	
}
