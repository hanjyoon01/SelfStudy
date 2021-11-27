package week02.hjy.konkuk;

import java.util.Scanner;

public class PassCheck {

	public static void main(String[] args) {
		
		System.out.println("202011390 한재윤");
		String Password = "greenjoa";
		int count = 0;
		Scanner s = new Scanner(System.in);
		
		while(true) {
			System.out.print("비밀번호를 입력하세요: ");
			String pass = s.next();
			if(pass.equals(Password)) {
				s.close();
				System.out.println("환영합니다.");
				System.exit(0);
			}
			else {
				count++;
				if (count==3) {
					s.close();
					System.out.println("접속을 거부합니다.");
					System.exit(0);
				}
			}
		}
	}
}
