package Project03;

public class SalaryTaxPayer extends TaxPayer {
	private String companyName;

	public SalaryTaxPayer(String name, String number, int earnings, String companyName) {
		super(name, number, earnings);
		this.companyName = companyName;
	}
	
	public double getTax() {
		if(this.getEarnings()>=8000)
			return super.getEarnings()*0.2;
		else if(this.getEarnings()>=6000)
			return super.getEarnings()*0.15;
		else if(this.getEarnings()>=4000)
			return super.getEarnings()*0.10;
		else if(this.getEarnings()>=2000)
			return super.getEarnings()*0.05;
		else
			return super.getEarnings()*0.01;
	}
	
	public String getCompanyName() {
		return companyName;
	}
	
	public void setCompanyName(String companyName) {
		this.companyName = companyName;
	}
	
	@Override
	public String toString() {
		String str = "납세자: "+this.getName();
		str += "\n식별번호: "+this.getNumber();
		str += "\n소득금액: "+this.getEarnings();
		str += "\n세금액: "+this.getTax();
		return str;
	}
	
}
