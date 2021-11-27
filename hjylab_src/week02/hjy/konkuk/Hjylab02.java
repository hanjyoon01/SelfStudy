package week02.hjy.konkuk;

import java.util.Scanner;

public class Hjylab02 {

	public static void main(String[] args) {
		
		System.out.println("202011390 한재윤");
		
		Scanner scanner = new Scanner(System.in);
		
		System.out.print("학번:");
		int student_number = scanner.nextInt();
		System.out.print("이름:");
		String student_name = scanner.next();
		System.out.print("나이:");
		int student_age = scanner.nextInt();
		System.out.print("주소:");
		scanner.nextLine();
		String student_address = scanner.nextLine();
		
		scanner.close();
		
		System.out.println();
		System.out.println("학번: "+student_number);
		System.out.println("이름: "+student_name);
		System.out.println("나이: "+student_age);
		System.out.println("주소: "+student_address);
	}

}
