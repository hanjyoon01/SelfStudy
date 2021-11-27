package Project03;

public class BusinessTaxPayer extends TaxPayer {
	private int expenses;

	public BusinessTaxPayer(String name, String number, int earnings, int expenses) {
		super(name, number, earnings);
		this.expenses = expenses;
	}
	
	public int getExpenses() {
		return expenses;
	}

	public void setExpenses(int expenses) {
		this.expenses = expenses;
	}

	public double getTax() {
		int tax = this.getEarnings() - this.expenses;
		if(tax<=0)
			return 0;
		else if(tax>=4000)
			return tax*0.2;
		else
			return tax*0.1;
	}

	@Override
	public String toString() {
		String str = "납세자: "+this.getName();
		str += "\n식별번호: "+this.getNumber();
		str += "\n소득금액: "+this.getEarnings();
		str += "\n총 지출액: "+this.expenses;
		str += "\n세금액: "+this.getTax();
		return str;
	}
}
