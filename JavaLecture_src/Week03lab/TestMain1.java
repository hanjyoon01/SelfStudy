package Week03lab;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Random;
import java.util.Scanner;

public class TestMain1 {

	static Scanner scanner = new Scanner(System.in);
	
	public static void lab01() {
		// 선택정렬
		//int[] list = {10, 50, 30, 60, 70, 20};
		//int[] list = new int[] {10, 50, 30, 60, 70, 20};
		/*int[] list = new int[6];
		list[0]= 10;
		list[1] = 50;*/
		int[] list = {10, 50, 30, 60, 70, 20};	
		
		System.out.print("정렬 전:");
		for(int i : list) {
			System.out.print(i + ", ");
		}
		System.out.println();
		
		for(int i=0; i<list.length-1;i++) {
			int idxMin = i;
			for(int j=i+1; j<list.length;j++) {
				if(list[j] < list[idxMin])
					idxMin = j;
			}
			if(idxMin != i) {
				//int temp = list[idxMin];
				//list[idxMin] = list[i];
				//list[i] = temp;
				list[i] = list[i]^list[idxMin];
				list[idxMin] = list[i]^list[idxMin];
				list[i] = list[i]^list[idxMin];
			}
		}
		System.out.print("정렬 후:");
		for(int i : list) {
			System.out.print(i + ", ");
		}
	}
	
	public static void lab02() {
		
		String[] list = {"홍길동", "김길동", "이길동", "남길동"};	
		
		System.out.print("정렬 전:");
		for(String i : list) {
			System.out.print(i + ", ");
		}
		System.out.println();
		
		for(int i=0; i<list.length-1;i++) {
			int idxMin = i;
			for(int j=i+1; j<list.length;j++) {
				if(list[j].compareTo(list[idxMin]) < 0 )
					idxMin = j;
			}
			if(idxMin != i) {
				String temp = list[idxMin];
				list[idxMin] = list[i];
				list[i] = temp;
				//list[i] = list[i]^list[idxMin];
				//list[idxMin] = list[i]^list[idxMin];
				//list[i] = list[i]^list[idxMin];
			}
		}
		System.out.print("정렬 후:");
		for(String i : list) {
			System.out.print(i + ", ");
		}
	}
	
	public static void lab03() {
		int[] arr1 = {1,2,3,4};
		int[] arr2 = {1,2,3,4};
		
		boolean result = arrEquals(arr1,arr2);
		System.out.println(arr1+"\n"+arr2);
		System.out.println(result?"같음":"같지않음");
	}
	
	private static boolean arrEquals(int[] arr1, int[] arr2) {
		if(arr1.length != arr2.length)
			return false;
		for(int i=0;i<arr1.length;i++) {
			if(arr1[i] != arr2[i])
				return false;
		}
		return true;
	}
	
	public static void lab04() {
	
		int[] Lotto = makelotto();
		for(int i: Lotto) {
			System.out.print(i+" ");
		}
		
	}

	public static int[] makelotto() {
		Random rand = new Random();
		int[] Lotto = new int[6];
		for(int i=0;i<Lotto.length;i++){
			Lotto[i] = rand.nextInt(46) + 1;
			for (int j=0;j<i;j++){
				if (Lotto[j] == Lotto[i]) {
					i--;
					break;
				}
			}
		}
		return Lotto;
	}
	
	public static void lab05() {
		int[] answer = {1,2,3,3,2,1};
		int[] std1 = {1,2,4,3,1,2};
		int[] std2 = {2,1,4,1,1,3};
		int[] std = new int[12];
		System.arraycopy(std1,0,std,0,std1.length);
		System.arraycopy(std2,0,std,6,std2.length);
		for(int i:std)
			System.out.print(i+" ");
		System.out.println();
		
		for(int i:std)
			System.out.print(i+" ");
		System.out.println();
		
		int[] quiz_result = get_quiz_result(answer,std.clone());
		
		for(int i:quiz_result)
			System.out.print(i+" ");
		System.out.println();
		
		for(int i:std)
			System.out.print(i+" ");
		System.out.println();
	}

	public static int[] get_quiz_result(int[] answer, int[] std) {
		for(int i=0;i<answer.length;i++) {
			if (std[i] == answer[i])
				std[i]=1;
			else
				std[i]=0;
		}
		return std;
	}
	
	public static void lab06() {
		String[] name = new String[] {"홍길동","이길동","김길동","고길동"};
		int[][] score = new int[][] {
			{10,20,30,0,0},
			{15,30,20,0,0},
			{20,20,10,0,0},
			{5,30,15,0,0}
		};
		for(int[] arr: score) {
			for(int i=0; i<arr.length-2;i++) {
				arr[arr.length-1] += arr[i];
			}
		}
		for(int i=0;i<score.length;i++) {
			System.out.print(name[i]+" >> ");
			int k=0;
			for(int j: score[i]) {
				if(k==3)
					System.out.print("| ");
				System.out.print(j+" ");
				k++;
			}
			System.out.println();
		}
	}

	public static void lab07() {
	
		int[][] arr = makearray2D();
		printarray2D(arr);
		
	}
	public static void printarray2D(int[][] arr) {
		for(int i=0;i<arr.length;i++) {
			System.out.print((i+1)+"층: ");
		//	for(int j:arr[i])
		//		System.out.print(j+" ");
			for(int j=0;j<arr[i].length;j++)
				System.out.print(arr[i][j] + " ");
			System.out.println();
		}
		
	}

	public static int[][] makearray2D() {
		System.out.print("층의 개수: ");
		final int ROW = scanner.nextInt();
		int[][] arr = new int [ROW][];
		Random rand = new Random();
		for(int i=0;i<ROW;i++) {
			System.out.print((i+1)+"층: ");
			final int COL = scanner.nextInt();
			arr[i] = new int [COL];
			for(int j=0;j<COL;j++) {
				arr[i][j] = rand.nextInt(100); 
			}
		}
		return arr;
	}
	
	public static void lab08(String filename) {
		int[][] map = readMap(filename);
		if (map!=null)
			showMap(map);
	}
	
	private static void showMap(int[][] map) {
		// TODO Auto-generated method stub
		for (int[] row: map) {
			for(int col:row) {
				switch(col) {
				case 0:
					System.out.print("★");
					break;
				case 1:
					System.out.print("☆");
					break;
				case 2:
					System.out.print("⊙");
					break;
				}
			}
		System.out.println();
		}
	}

	public static int[][] readMap(String filename) {
		int[][] map = null;
		File file = new File(filename);
		try {
			Scanner filescan = new Scanner(file);
			final int ROW = filescan.nextInt();
			final int COL = filescan.nextInt();
			map = new int[ROW][COL];
			for(int i=0;i<map.length;i++) {
				for(int j=0;j<map[i].length;j++) {
					map[i][j] = filescan.nextInt();
				}
			}
		} catch (FileNotFoundException e) {
			System.out.println("파일이 존재하지 않습니다.");
			//e.printStackTrace();
		}
		
		return map;
	}

	public static void main(String[] args) {

		lab07();
		//lab08(args[0]);
		scanner.close();
	}

}
