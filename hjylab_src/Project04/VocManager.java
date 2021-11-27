package Project04;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.Scanner;

public class VocManager {
	private String userName;
	private Word[] voc = new Word[100];
	private int number = 0;
	
	static Scanner scan = new Scanner(System.in);
	
	public VocManager(String userName) {
		this.userName = userName;
	}
	
	void addword(Word word) {
		if(number < voc.length)
			voc[number++] = word;
		else {
			System.out.println("단어장에 더이상의 단어를 등록할 수 없습니다.");
		}
	}
	
	void makeVoc(String filename) {
		try(Scanner scan = new Scanner(new File(filename))){
			while(scan.hasNextLine()) {
				String str = scan.nextLine();
				String[] temp = str.split("\t");
				this.addword(new Word(temp[0].trim(), temp[1].trim()));
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
			System.out.println("1)단어검색    2)객관식 퀴즈    3)종료");
			System.out.print("메뉴를 선택하세요: ");
			try {
				choice = scan.nextInt();			
				System.out.println();
				scan.nextLine();
				switch (choice) {
				case 1:
					searchVoc2();
					break;
				case 2:
					multipleChoiceQuiz();
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
		for(Word word:voc) {
			if(word!=null) {
				if(word.getEng().equals(sWord)) {
					System.out.println("단어의 뜻: "+word.getKor());
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
		for(Word word:voc) {
			if(word!=null) {
				if(word.getEng().contains(sWord)) {
					System.out.println("단어: "+word.getEng()+", 단어의 뜻: "+word.getKor());
				}
			}else {
				//System.out.println("단어장에 등록되어 있지 않습니다.");
				break;
			}
		}
		System.out.println("-------------------------\n");
	}
	
	public void multipleChoiceQuiz() {
		
		int rightCount = 0; //정답의 갯수
		Random rand = new Random();
		long time1 = System.currentTimeMillis(); //시작시간
		int[] count = new int[number]; //이미 문제에 출제된 단어인지 확인하는 용도
		
		for(int i=0; i<10 ; i++) {
			int[] answer = new int[number]; // 선지에 이미 출제된 단어의 뜻이 확인하는 용도 (한 문제 출제 후 다시 0으로 초기화)
			int n = rand.nextInt(number);
			if(count[n] == 0 ) 
				count[n]++;
			
			//
			else {
				i--;
				continue;
			}
			System.out.println("------객관식 "+(i+1)+"번째 문제------");
			System.out.println(voc[n].getEng()+"의 뜻은 무엇일까요?");
			int[] answerList = new int[4];
			
			//첫 번째 인덱스에 답인 선지를 배치
			answerList[0] = n;
			
			//3개의 틀린 선지를 무작위로 선택해 배치
			for(int j=1; j<4; j++) {
				int r = rand.nextInt(number);
				if(r != n) {
					//선지의 뜻이 같으면 인덱스 감소
					if(voc[n].getKor().equals(voc[r].getKor())) {
						j--;
						continue;
					}
					if(answer[r] == 0) {
						answerList[j] = r;
						answer[r]++;
					}
					//이미 선택된 선지면 인덱스 감소
					else {
						j--;
						continue;
					}
				}
				//답인 선지와 같은 선지면 인덱스 감소
				else
					j--;
			}
			//4개의 선지를 무작위로 배치
			change(answerList);
			
			//4개의 선지를 출력
			for(int k=0; k<4; k++) {
				System.out.println((k+1)+") "+ voc[answerList[k]].getKor());
			}
			try {
				//답 선택
				System.out.print("답을 입력하세요: ");
				int choice = scan.nextInt();
				
				//선지에 없는 번호 선택 시 오답처리
				if(choice<1 || choice>4) {
					System.err.println("선지에 없는 번호를 골랐습니다. 오답 처리합니다.\n");
				}
				
				else {
					if(answerList[choice-1] == n) {
						System.out.println("정답입니다.");
						rightCount++;
					}
					else {
						//오답일 때, 정답 번호 출력
						int result = 0;
						for(int k=0; k<4; k++) {
							if(answerList[k] == n)
								result = k;
						}
						System.out.println("틀렸습니다. 정답은 "+(result+1)+"번입니다.");
					}
				}
			//숫자외의 문자 입력 시 오답처리
			}catch(InputMismatchException e) { 
				System.err.println("숫자를 입력하지 않았습니다. 오답 처리합니다.\n");
				scan.nextLine();
			}

		}
		long time2 = System.currentTimeMillis();
		long totalTime = time2 - time1;
		
		//총 맞춘 갯수, 시험 시간 출력
		System.out.println();
		System.out.println(userName+"님, 10문제 중 "+rightCount+"개 맞추셨고, 총 "+ totalTime/1000 +"초 소요되었습니다.");
	}
	
	//4개의 선지를 무작위로 10번 섞는 메소드
	public static void change(int[] a) {
		Random rand = new Random();
		
		for(int i=0;i<10;i++) {
			int r = rand.nextInt(4);
			int s = rand.nextInt(4);
			int temp;
			temp = a[r];
			a[r] = a[s];
			a[s] = temp;
		}
	}

}