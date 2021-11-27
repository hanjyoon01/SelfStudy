package week02.hjy.konkuk;

import java.util.Random;
import java.util.Scanner;
import java.lang.Math;

public class RSPGame {

	public static void main(String[] args) {
		
		Random r = new Random();
		int com = Math.abs(r.nextInt()%3);
		String uRSP=null, cRSP = null; // 한글 표현
		Scanner s = new Scanner(System.in);
		System.out.println("202011390 한재윤");
		System.out.println("가위(0), 바위(1), 보(2)중에 하나를 입력해주세요");
		System.out.print("입력:");
		
		int user = s.nextInt();
		
		switch(user) {
		case 0:
			uRSP = "가위";
			break;
		case 1:
			uRSP = "바위";
			break;
		case 2:
			uRSP = "보";
			break;
		}
		
		switch(com) {
		case 0:
			cRSP = "가위";
			break;
		case 1:
			cRSP = "바위";
			break;
		case 2:
			cRSP = "보";
			break;
		}
		
		System.out.println("user: "+uRSP);
		System.out.println("com: "+cRSP);
		if(user==com)
			System.out.println("무승부");
		else if((user==0 && com==1)||(user==1 && com==2)||(user==2 && com==0))
			System.out.println("com 승리");
		else
			System.out.println("user 승리");
		
		s.close();
	}

}
