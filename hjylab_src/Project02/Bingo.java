package Project02;

import java.util.Random;
import java.util.Scanner;


public class Bingo {
	
	static Random rand = new Random();
	static Scanner scan = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		int[][] Bingo = makebingo();
		
		System.out.println("202011390 한재윤");
		
		while(true) {
			
			//빙고판 표시
			System.out.println("====================");
			for(int i=0;i<Bingo.length;i++) {
				for(int j: Bingo[i]) {
					if(j == 79 || j == 88)
						System.out.printf("%3c ",j);
					else
						System.out.printf("%3d ",j);
				}
				System.out.println();
			}
			System.out.println("====================");
		
			//컴퓨터 숫자 선택 후 빙고 만족 여부
			int[] u_row_count = {0,0,0,0,0};
			int[] c_row_count = {0,0,0,0,0};
			int[] u_column_count = {0,0,0,0,0};
			int[] c_column_count = {0,0,0,0,0};
			int[] u_diagonal_count = {0,0};
			int[] c_diagonal_count = {0,0};
			//행
			for(int m=0;m<Bingo.length;m++) {
				for(int n=0;n<Bingo[0].length;n++){
					if(Bingo[m][n]==79)
						u_row_count[m]++;
					if(Bingo[m][n]==88)
						c_row_count[m]++;
				}
			}
			//렬
			for(int m=0;m<Bingo.length;m++) {
				for(int n=0;n<Bingo[0].length;n++){
					if(Bingo[n][m]==79)
						u_column_count[m]++;
					if(Bingo[n][m]==88)
						c_column_count[m]++;
				}
			}
			//대각선
			for(int n=0;n<Bingo.length;n++) {
				//정대각선
				if(Bingo[n][n]==79)
					u_diagonal_count[0]++;
				if(Bingo[n][n]==88)
					c_diagonal_count[0]++;
				//반대각선
				if(Bingo[n][4-n]==79)
					u_diagonal_count[1]++;
				if(Bingo[n][4-n]==79)
					c_diagonal_count[1]++;
			}
			
			for(int n=0;n<Bingo.length;n++) {
				if(u_row_count[n]==5 || u_column_count[n]==5) {
					System.out.println("user 빙고!");
					System.exit(0);
				}
				if(c_row_count[n]==5 || c_column_count[n]==5) {
					System.out.println("com 빙고!");
					System.exit(0);
				}
			}
			if(u_diagonal_count[0]==5 || u_diagonal_count[1]==5) {
				System.out.println("user 빙고!");
				System.exit(0);
			}
			if(c_diagonal_count[0]==5 || c_diagonal_count[1]==5) {
				System.out.println("com 빙고!");
				System.exit(0);
			}
			
			//숫자 선택(사용자)
			while(true) {
				System.out.print("숫자를 선택하세요(user): ");
				int u = scan.nextInt();
				int count = 0;
				if(u < 1 || u > 25) {
					System.out.println("이미 선택되었거나 없는 숫자입니다. 다시 선택해주세요");
					continue;
				}
				for(int i=0;i<Bingo.length;i++) {
					for(int j: Bingo[i]) {
						if (u == j)
							count++;
					}
				}
				if(count == 0)
					System.out.println("이미 선택되었거나 없는 숫자입니다. 다시 선택해주세요");
				
				else {
					for(int i=0;i<Bingo.length;i++) {
						for(int j=0;j<Bingo.length;j++) {
							if(Bingo[i][j] == u)
								Bingo[i][j] = 79; 
						}
					}
					break;
				}
			}
		
			//선택 후 빙고판 표시
			System.out.println("====================");
			for(int i=0;i<Bingo.length;i++) {
				for(int j: Bingo[i]) {
					if(j == 79 || j == 88)
						System.out.printf("%3c ",j);
					else
						System.out.printf("%3d ",j);
				}
				System.out.println();
			}
			System.out.println("====================");
			
			//사용자 숫자 선택 후 빙고 만족 여부 검사
			for(int m=0;m<Bingo.length;m++){
				u_row_count[m] = 0;
				c_row_count[m] = 0;
				u_column_count[m] = 0;
				c_column_count[m] = 0;
			}
			u_diagonal_count[0]=0;
			u_diagonal_count[1]=0;
			c_diagonal_count[0]=0;
			c_diagonal_count[1]=0;
			
			//행
			for(int m=0;m<Bingo.length;m++) {
				for(int n=0;n<Bingo[0].length;n++){
					if(Bingo[m][n]==79)
						u_row_count[m]++;
					if(Bingo[m][n]==88)
						c_row_count[m]++;
				}
			}
			//렬
			for(int m=0;m<Bingo.length;m++) {
				for(int n=0;n<Bingo[0].length;n++){
					if(Bingo[n][m]==79)
						u_column_count[m]++;
					if(Bingo[n][m]==88)
						c_column_count[m]++;
				}
			}
			//대각선
			for(int n=0;n<Bingo.length;n++) {
				//정대각선
				if(Bingo[n][n]==79)
					u_diagonal_count[0]++;
				if(Bingo[n][n]==88)
					c_diagonal_count[0]++;
				//반대각선
				if(Bingo[n][4-n]==79)
					u_diagonal_count[1]++;
				if(Bingo[n][4-n]==79)
					c_diagonal_count[1]++;
			}
			for(int n=0;n<Bingo.length;n++) {
				if(u_row_count[n]==5 || u_column_count[n]==5) {
					System.out.println("user 빙고!");
					System.exit(0);
				}
				if(c_row_count[n]==5 || c_column_count[n]==5) {
					System.out.println("com 빙고!");
					System.exit(0);
				}
			}
			if(u_diagonal_count[0]==5 || u_diagonal_count[1]==5) {
				System.out.println("user 빙고!");
				System.exit(0);
			}
			if(c_diagonal_count[0]==5 || c_diagonal_count[1]==5) {
				System.out.println("com 빙고!");
				System.exit(0);
			}
			
			int final_count=0;
			//사용자 숫자 선택 후 모든 숫자가 오픈됐는지 확인
			for(int i=0;i<Bingo.length;i++) {
				for(int j=0;j<Bingo[0].length;j++){
					if(Bingo[i][j]==79 || Bingo[i][j]==88)
						final_count++;
				}
			}
			if(final_count==25) {
				System.out.println("모든 숫자를 오픈했습니다. 프로그램을 종료합니다.");
				System.exit(0);
			}
			
			//숫자 선택(컴퓨터)
			while(true) {
				int c1 = rand.nextInt(5);
				int c2 = rand.nextInt(5);
				if(Bingo[c1][c2] == 79 || Bingo[c1][c2] == 88)
					continue;
				System.out.println("com은 "+Bingo[c1][c2]+"을(를) 선택했습니다.");
				Bingo[c1][c2] = 88;
				break;
			}
		}
	}
	
	public static int[][] makebingo() {
		int k = 1;
		int[][] bingo = new int[5][5];
		for(int i=0;i<bingo.length;i++){
			for(int j=0;j<bingo[0].length;j++) {
				bingo[i][j] = k;
				k++;
			}
		}
		change(bingo);
		
		return bingo;
	}

	public static void change(int[][] bingo) {
		for(int i=0;i<30;i++) {
			int r = rand.nextInt(5);
			int s = rand.nextInt(5);
			int t = rand.nextInt(5);
			int u = rand.nextInt(5);
			int temp;
			temp = bingo[r][s];
			bingo[r][s] = bingo[t][u];
			bingo[t][u] = temp;
		}
	}
}
