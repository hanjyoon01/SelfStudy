package Week04lab;

import java.util.Scanner;

public class TestMain {

	static Scanner scan = new Scanner(System.in);
	public static void replaceChar(char[] input, char char1, char char2) {
		for(int i=0; i<input.length;i++) {
			if(input[i]==char1)
				input[i] = char2;
		}
	}
	public static char[] replaceChar(String input, char char1, char char2) {
		
		char[] charArr = input.toCharArray();
		replaceChar(charArr, char1, char2);
		return charArr;
	}
	
	public static void main(String[] args) {
		
//		lab02();
//		System.out.println("202011390 한재윤"); 
//		TV tv = new TV(false,15);
//		tv.poweronoff();
//		tv.volumeup();
//		tv.volumeup();
//		tv.changeChannel(5);
//		tv.changeVolume(15);
//		tv.changeVolume(25);
//		tv.poweronoff();
		
		Vehicle car1 = new Vehicle("빨강색", 100);
		car1.tv = new TV(true, 20);
		System.out.println("Car1");
		//System.out.println(car1);
		car1.showStatus();
		car1.changeGear('D');
		car1.accelerate(10);
		car1.accelerate(10);
		car1.showStatus();
		car1.breaker(5);
		car1.showStatus();
		car1.changeGear('N');
		car1.showStatus();
		
		System.out.println("Car2");
		Vehicle car2 = new Vehicle(car1);
		car2.showStatus();
		car1.tv.channelup();
		car2.showStatus();
	}
	
	public static void lab02() {
		
		System.out.print("문자열을 입력하세요: ");
		String userinput = scan.nextLine();
		System.out.print("찾을 문자를 입력하세요: ");
		String userchar1 = scan.nextLine();
		char char1 = userchar1.charAt(0);
		System.out.print("바꿀 문자를 입력하세요: ");
		String userchar2 = scan.nextLine();
		char char2 = userchar2.charAt(0);
		char[] resultArray = replaceChar(userinput, char1, char2);
		System.out.println(resultArray);
	}
}


