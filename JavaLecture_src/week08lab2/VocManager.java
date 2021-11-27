package week08lab2;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import java.util.Map.Entry;

import week08lab1.Word;

public class VocManager {
	private String userName;
	private HashMap<String, Word> voc = new HashMap<>();
	
	static Scanner scan = new Scanner(System.in);
	
	public VocManager(String userName) {
		this.userName = userName;
	}
	
	void makeVoc(String filename) {
		try(Scanner scan = new Scanner(new File(filename))){
			while(scan.hasNextLine()) {
				String str = scan.nextLine();
				String[] temp = str.split("\t");
				voc.put(temp[0].trim(), new Word(temp[0].trim(),temp[1].trim()));
			}
			System.out.println(userName+"의 단어장이 생성되었습니다.");
			menu();
			
		}catch(FileNotFoundException e) {
			System.err.println("파일 이름 확인해 주세요.");
		};

	}
	
	void menu() {
		int choice = 0;
		while(choice!=3) {
			
			System.out.println("\n--------한재윤의 단어장--------");
			System.out.println("1)단어검색    2)단어검색2   3)종료");
			System.out.print("메뉴를 선택하세요: ");
			try {
				choice = scan.nextInt();			
				System.out.println();
				scan.nextLine();
				switch (choice) {
				case 1:
					searchVoc();
					break;
				case 2:
					searchVoc2();
					break;
				case 3:
					System.out.println(userName+"의 단어장 프로그램을 종료합니다.");
					break;
				default:
					System.out.println("1과 3 사이의 숫자를 입력해 주세요.");
				}
			}catch(InputMismatchException e) {
				System.out.println();
				System.err.println("숫자를 입력해 주세요.");
				scan.nextLine();
			}

		}
	}

	public void searchVoc() {
		// TODO Auto-generated method stub
		System.out.println("--------- 단어 검색 ---------");
		System.out.print("검색할 단어를 입력하세요: ");
		String sWord = scan.nextLine();
		sWord = sWord.trim();
		
		Set<Map.Entry<String, Word>> set = voc.entrySet();
		Iterator<Entry<String, Word>> it = set.iterator();
		while(it.hasNext()) {
			Entry<String, Word> entry = it.next();
			String key = entry.getKey();
			Word word = entry.getValue();
			if(key != null) {
				if(key.equals(sWord)) {
					System.out.println("단어의 뜻: "+word.kor);
					break;
				}
			}else {
				System.out.println("단어장에 등록되어 있지 않습니다.");
				break;
			}
		}
		System.out.println("-------------------------\n");
	}
	public void searchVoc2() {
		// TODO Auto-generated method stub
		System.out.println("--------- 단어 검색 ---------");
		System.out.print("검색할 단어를 입력하세요: ");
		String sWord = scan.nextLine();
		sWord = sWord.trim();
		
		Set<Map.Entry<String, Word>> set = voc.entrySet();
		Iterator<Entry<String, Word>> it = set.iterator();
		while(it.hasNext()) {
			Entry<String, Word> entry = it.next();
			String key = entry.getKey();
			Word word = entry.getValue();
			if(key != null) {
				if(key.contains(sWord)) {
					System.out.println("단어: "+key+", 단어의 뜻: "+word.kor);
				}
			}else {
//				System.out.println("단어장에 등록되어 있지 않습니다.");
				break;
			}
		}
		System.out.println("-------------------------\n");
	}
	
//	public void multipleChoiceQuiz() {
//		int rightCount = 0;
//		Random rand = new Random();
//		long time1 = System.currentTimeMillis();
//		// TODO Auto-generated method stub
//		int[] count = new int[number];
//		for(int i=0; i<10 ; i++) {
//			int[] answer = new int[number];
//			int n = rand.nextInt(number);
//			if(count[n] == 0 ) 
//				count[n]++;
//			else {
//				i--;
//				continue;
//			}
//			System.out.println("------객관식 "+(i+1)+"번째 문제------");
//			System.out.println(voc[n].eng+"의 뜻은 무엇일까요?");
//			int[] answerList = new int[4];
//			answerList[0] = n;
//			for(int j=1; j<4; j++) {
//				int r = rand.nextInt(number);
//				if(r != n) {
//					if(answer[r] == 0) {
//						answerList[j] = r;
//						answer[r]++;
//					}
//					else {
//						j--;
//						continue;
//					}
//				}
//				else
//					j--;
//			}
//			change(answerList);
//			
//			for(int k=0; k<4; k++) {
//				System.out.println((k+1)+") "+ voc[answerList[k]].kor);
//			}
//			System.out.print("답을 입력하세요: ");
//			int choice = scan.nextInt();
//			if(answerList[choice-1] == n) {
//				System.out.println("정답입니다.");
//				rightCount++;
//			}
//			else {
//				int result = 0;
//				for(int k=0; k<4; k++) {
//					if(answerList[k] == n)
//						result = k;
//				}
//				System.out.println("틀렸습니다. 정답은 "+(result+1)+"번입니다.");
//			}
//
//		}
//		long time2 = System.currentTimeMillis();
//		long totalTime = time2 - time1;
//		
//		System.out.println();
//		System.out.println(userName+"님, 10문제 중 "+rightCount+"개 맞추셨고, 총 "+ totalTime/1000 +"초 소요되었습니다.");
//	}
//	
//	public static void change(int[] a) {
//		Random rand = new Random();
//		
//		for(int i=0;i<10;i++) {
//			int r = rand.nextInt(4);
//			int s = rand.nextInt(4);
//			int temp;
//			temp = a[r];
//			a[r] = a[s];
//			a[s] = temp;
//		}
//	}
}
