package Week05lab;

import java.util.Scanner;

public class BankManager {
	public String branchname;
//	public static final int NUM = 20;
//	public BankAccount[] bankAccount = new BankAccount[NUM];
	public final int NUM;
	public BankAccount[] bankAccount;
	public static Scanner scan = new Scanner(System.in);

	public BankManager(String branchname, int num) {
		NUM = num;
		bankAccount = new BankAccount[NUM];
		this.branchname = branchname;
	}
	
	public void createAccount() {
		System.out.println("*** 계좌 개설 ***");
		if(BankAccount.count < NUM) {
			System.out.print("이름: " );
			String name = scan.next();
			System.out.print("입금할 금액: " );
			int money = scan.nextInt();
			bankAccount[BankAccount.count]=new BankAccount(name, money);
			System.out.println("계좌 계설 완료");
		}else {
			System.out.println("더 이상 계좌 개설 불가");
		}
		
	}

	public void deposit() {
		System.out.println("*** 입금 ***");
		System.out.print("계좌번호: ");
		int acc = scan.nextInt();
		BankAccount target = findAccount(acc);
		if(target!=null) {
			System.out.print("입금할 금액: ");
			int money = scan.nextInt();
			target.deposit(money);
		}else {
			System.out.println("계좌 번호 확인 요함");
		}
	}
	
	public void withdraw() {
		System.out.println("*** 출금 ***");
		System.out.print("계좌번호: ");
		int acc = scan.nextInt();
		BankAccount target = findAccount(acc);
		if(target!=null) {
			System.out.print("출금할 금액: ");
			int money = scan.nextInt();
			target.withdraw(money);
		}else {
			System.out.println("계좌 번호 확인 요함");
		}
	}
	
	public void transfer() {
		System.out.println("*** 계좌 이체 ***");
		System.out.print("송금할 계좌번호: ");
		int acc1 = scan.nextInt();
		System.out.print("송금받을 계좌번호: ");
		int acc2 = scan.nextInt();
		BankAccount target1 = findAccount(acc1);
		BankAccount target2 = findAccount(acc2);
		if(target1 != null && target2 != null) {
			System.out.print("이체할 금액: ");
			int money = scan.nextInt();
			if(target1.accountBalance >= money) {
				target1.withdraw(money);
				target2.deposit(money);
			}
			else {
				System.out.println("출금 잔액 부족");
			}
		}else 
			System.out.println("계좌 번호 확인 요함");
	}
	
	public BankAccount findAccount (int target) {
		if ((BankAccount.count >= target) && (target > 0)) {
			return bankAccount[target-1];
		}
		else
			return null;
	}

	@Override
	public String toString() {
		String str = this.branchname+"\n";
		str+="==============\n";
	//	for(BankAccount acc:bankAccount) {
		for(int i=0;i<BankAccount.count;i++) {
			str += bankAccount[i].toString();
			str += "\n---------------\n";
		}
		return str;
	}
}
