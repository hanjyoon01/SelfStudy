package Project01;

import java.util.Scanner;

public class Control {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		System.out.println("202011390 한재윤");
		
		while (true) {
			System.out.println("1) 복리예금 계산기	2) 구구단 출력하기	3) 종료");
			System.out.print("메뉴를 선택하세요: ");
			int select = scan.nextInt();
			if(select == 1) {
				int year = 1;
				System.out.println("========= 복리예금 계산기 =========");
				System.out.print("원금을 입력하세요: ");
				int origin = scan.nextInt();
				System.out.print("연이율을 입력하세요: ");
				double year_rate = scan.nextDouble();
				System.out.println("------------------------------");
				System.out.println("년도수                      원리금");
				System.out.println("------------------------------");
				double y_origin = (double)origin;
				while (true) {
					y_origin *= (1+year_rate/100);
					if (y_origin>2*origin) {
						System.out.printf("%d             %.2f\n",year, y_origin);
						System.out.println("------------------------------");
						System.out.println(year+"년이 걸립니다.");
						System.out.println(" ");
						break;
					}
					System.out.printf("%d             %.2f\n",year, y_origin);
					year++;
				}
			}
			else if(select == 2) {
				System.out.println("========= 구구단 출력하기 =========");

				Label: while(true) {
					System.out.print("출력 단수: ");
					int column = scan.nextInt();
					if(column < 2 || column > 8) {
						System.out.println("다시 입력하세요.");
						System.out.println();
						continue;
					}
					for(int i=2; i<10; i+=column) {
						for (int j=1; j<10;j++) {
							for (int k=i; k<i+column;k++) {
							System.out.print(k+"*"+j+"="+k*j);
							System.out.print("\t");
							if (k>8)
								break;
							}
							System.out.println();
						}
						System.out.println();	
					}
					break Label;
				}
			}
			else if(select == 3) {
				scan.close();
				System.out.println("프로그램을 종료합니다.");
				System.exit(0);
			}
				
			else {
				System.out.println("메뉴를 다시 골라주세요.");
				System.out.println();
			}
		}
	}
}
