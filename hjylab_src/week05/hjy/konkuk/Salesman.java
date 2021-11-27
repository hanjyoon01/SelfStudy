package week05.hjy.konkuk;

import java.util.Scanner;

public class Salesman {
	public String name;
	public double sales;
	
	Scanner scan = new Scanner(System.in);
	public Salesman(String name, double sales) {
		this.name = name;
		this.sales = sales;
	}
	

	public void setName(String name) {
		this.name = name;
	}

	public void readInput() {
		System.out.print("이름: ");
		name = scan.nextLine();
		System.out.print("실적: ");
		sales = scan.nextDouble();
	}


	@Override
	public String toString() {
		String str = "이름: "+ this.name;
		str += " / 실적: "+ this.sales;
		return str;
	}
}
