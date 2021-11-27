package week02example02;

import java.util.Scanner;

public class TestMain2 {

	public static void main(String[] args) {
		System.out.println("이름, 도시, 나이, 체중, 독신여부를 분리하여 입력");
		Scanner scanner = new Scanner(System.in);
		String name = scanner.next();
		System.out.println("이름="+name);
		String city = scanner.next();
		System.out.println("도시="+city);
		scanner.nextLine();
		String addr = scanner.nextLine();
		System.out.println("주소="+addr);
		int age = scanner.nextInt();
		System.out.println("나이="+age);
		double weight = scanner.nextDouble();
		System.out.println("체중="+weight+"kg");
		boolean single = scanner.nextBoolean();
		System.out.println("독신여부="+single);
		
		
		scanner.close();
	
	}

}
