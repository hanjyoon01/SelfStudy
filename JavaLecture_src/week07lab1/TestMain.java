package week07lab1;

import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;

class MenuRangeCheckException extends RuntimeException{

	public MenuRangeCheckException() {
		super();
		// TODO Auto-generated constructor stub
	}

	public MenuRangeCheckException(String message) {
		super(message);
		// TODO Auto-generated constructor stub
	}
	
}
public class TestMain {
	
	public static void method(String[] args) throws ClassNotFoundException{
		//String str = args[0];
		Class clazz = Class.forName("java.lang.String2");
		
	}

	public static void main(String[] args) {	
		
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		while(true) {
			try {
				System.out.print("1)아메리카노  2)카페라떼  3)결제  4)종료\n 메뉴를 선택하세요 : ");
				int choice = scan.nextInt();
				if(!(choice>=1 && choice<=4)) {
					throw new MenuRangeCheckException("메뉴 범위 체크 바람");
				}
			}catch(MenuRangeCheckException e) {
				System.err.println(e.getMessage());
			}catch(InputMismatchException e) {
				System.err.println("숫자를 입력해주세요.");
				scan.nextLine();
			}
		}
		
		
		
		
	
		
//		try {
//			method(args);
//		}catch (ClassNotFoundException e) {
//			e.printStackTrace();
//		}catch(ArrayIndexOutOfBoundsException e) {
//			System.err.print(e.getMessage());
//			e.printStackTrace();
//		}
	
//		int num = 100;
//		Random rand = new Random();
//		while(true) {
//			try {
//				String str = args[0];
//				int result = num / rand.nextInt(100);
//				if(result>2)
//					return;
//				System.out.println(result);
//			}catch(ArithmeticException e) {
//				System.out.println("0으로 나눌 수 없음!");
//			}catch(ArrayIndexOutOfBoundsException e) {
//				System.err.println(e.getMessage());
//				System.out.println("배열 인덱스 참조 오류");
//				e.printStackTrace();
//			}catch(Exception e){
//				System.out.println("예외 발생");
//			}
//			finally {
//				System.out.println("다음 연산을 수행합니다.");
//			}
//		}
		
	}
}

