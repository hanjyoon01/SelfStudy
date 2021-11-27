package week05.hjy.konkuk;

public class SalesReport {

	public Salesman [] team;
	public double highestSales;
	public double averageSales;
	public final int number;
	
	public SalesReport(int num) {
		number = num;
		team = new Salesman[number];
		for(int i=0;i<number;i++) {
			team[i] = new Salesman(null, 0);
			System.out.println((i+1)+"번째 팀원 정보 입력");
			team[i].readInput();
		}
	}
	
	public void computeStats() {
		this.highestSales = highestSales;
		this.averageSales = averageSales;
		double MAX = team[0].sales;
		double SUM = team[0].sales;
		for(int i=1;i<number;i++) {
			if(team[0].sales<team[i].sales){
				MAX = team[i].sales;
			}
			SUM += team[i].sales;
		}
		highestSales = MAX;
		averageSales = SUM / number;
	}
	public Salesman getBestClerk() {
		Salesman BC = team[0];
		for(int i=1;i<number;i++) {
			if(BC.sales < team[i].sales){
				 BC = team[i];
			}
		}
		return BC;
	}

	@Override
	public String toString() {
		String str = "총 팀원 수: " + number;
		str += "\n최고 판매액: " + highestSales;
		str += "\n평균 판매액: " + averageSales;
		str += "\n-----------------\n";
		System.out.println();
		for(int i=0;i<number;i++) {
			str += team[i].toString();
			str += "\n";
		}
		return str;
	}
}
