package Project03;

public class TaxManager {
	private String city;
	private int number;
	private int count=0;
	TaxPayer[] payers;
	
	public TaxManager(String city, int number) {
		this.city = city;
		this.number = number;
		payers = new TaxPayer[this.number];
	}
	
	public void addTaxPayer(TaxPayer taxpayer) {
		if(this.count < this.number)
			this.payers[this.count++] = taxpayer;
		else
			System.out.println("모든 납세자 입력 완료");
	}
	public void showTax() {
		double totalTax = 0.0;
		for(TaxPayer payer:payers) {
			if(payer != null) {
				totalTax+= payer.getTax();
			}else
				break;
		}
		System.out.println(city+" 지역의 총 세금 징수액은 "+totalTax+"입니다.");
	}
	public void showSalaryTaxPayer() {
		double totalSalaryTax = 0.0;
		System.out.println("***근로소득자의 징수 내역***");
		for(TaxPayer payer:payers) {
			if(payers != null & payer instanceof SalaryTaxPayer) {
				SalaryTaxPayer p = (SalaryTaxPayer)payer;
				totalSalaryTax += p.getTax();
				System.out.println(p.toString());
				System.out.println("----------------------");
			}
		}
		System.out.println("총 근로소득세 징수금액: "+totalSalaryTax+"\n");
	}
	
	public void showBusinessTaxPayer() {
		double totalBusinessTax = 0.0;
		System.out.println("***사업소득자의 징수 내역***");
		for(TaxPayer payer:payers) {
			if(payers != null & payer instanceof BusinessTaxPayer) {
				BusinessTaxPayer p = (BusinessTaxPayer)payer;
				totalBusinessTax += p.getTax();
				System.out.println(p.toString());
				System.out.println("----------------------");
			}
		}
		System.out.println("총 사업소득세 징수금액: "+totalBusinessTax+"\n");
	}
}
