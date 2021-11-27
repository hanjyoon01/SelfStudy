package Week05lab;

public class BankAccount {
	public static int count = 0;
	public int accountNumber;
	public 	String customerName;
	public double accountBalance;
	
	{
		++count;
		this.accountNumber = count;
	}
	
	/*public BankAccount() {
		//super();
	}*/

	public BankAccount(String customerName, double accountBalance) {
		//super();
		this.customerName = customerName;
		this.accountBalance = accountBalance;
	}

	public BankAccount(String customerName) {
		//super();
		this(customerName,0);
	}

	public void deposit (double amount) {
		this.accountBalance += amount;
	}
	
	public void withdraw (double amount) {
		if(this.accountBalance>=amount)
			this.accountBalance -= amount;
		else
			System.out.println("출금 잔액 부족");
	}	
	
	public void transfer(BankAccount account, double amount) {
		if(this.accountBalance >= amount) {
			this.withdraw(amount);
			account.deposit(amount);
		}
		else
			System.out.println("출금 잔액 부족");
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		String str = "고객이름: "+ this.customerName;
		str += "\n계좌번호: "+ this.accountNumber;
		str += "\n잔      액: "+ this.accountBalance;
		return str;
	}
}
