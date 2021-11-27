package week05.hjy.konkuk;

import java.util.Scanner;

public class TestMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("202011390 한재윤");
		System.out.println("****팀 생성****");
		System.out.print("팀원 수: ");
		Scanner scan = new Scanner(System.in);
		int number = scan.nextInt();
		
		SalesReport team1 = new SalesReport(number);
		team1.computeStats();
		System.out.println();
		System.out.println("****최고 사원 정보****");
		System.out.println(team1.getBestClerk());
		System.out.println();
		System.out.print("****팀 정보****");
		System.out.println(team1);
	}
}
