package Project03;

public class TestMain {

	public static void main(String[] args) {
		TaxManager seoul = new TaxManager("서울", 30);
		seoul.addTaxPayer(new TaxPayer("홍길동","2001",5000));
		seoul.addTaxPayer(new SalaryTaxPayer("이길동","2002",8500,"우리"));
		seoul.addTaxPayer(new SalaryTaxPayer("김길동","2003",6500,"한국"));
		seoul.addTaxPayer(new SalaryTaxPayer("남길동","2004",4500,"사랑"));
		seoul.addTaxPayer(new SalaryTaxPayer("박길동","2005",2500,"사랑"));
		seoul.addTaxPayer(new SalaryTaxPayer("고길동","2006",1500,"사랑"));
		seoul.addTaxPayer(new BusinessTaxPayer("임길동","2007",5000, 6000));
		seoul.addTaxPayer(new BusinessTaxPayer("조길동","2008",7000, 2000));
		seoul.addTaxPayer(new BusinessTaxPayer("한길동","2009",5000, 2000));

		System.out.println("202011390 한재윤");
		seoul.showBusinessTaxPayer();
		seoul.showSalaryTaxPayer();
		seoul.showTax();
	}
}
