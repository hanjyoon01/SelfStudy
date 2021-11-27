package week02example06;

import java.util.Scanner;

public class TestMain6 {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		System.out.print("문장입력: ");
		String input = scan.nextLine();
		int counter = 0;
		
		for(int i=0; i<input.length(); i++) {
			char ch = input.charAt(i);
			if(ch == ' ' || ch == '\t' || ch == '.')
				continue;
			counter++;
		}
		System.out.println("글자 수는 "+counter+"개 입니다.");

		scan.close();
	}

}
