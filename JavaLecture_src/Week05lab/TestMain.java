package Week05lab;

public class TestMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("202011390 한재윤");
		
		TicketManager ticket1 = new TicketManager("이승환 콘서트", 100);
	//	ticket1.register(new Ticket(1,2000.0));
		ticket1.register(new GeneralTicket(2,2000.0,true));
		ticket1.register(new GeneralTicket(3,2000.0,false));
		ticket1.register(new AdvancedTicket(4,2000.0,50));
		ticket1.register(new AdvancedTicket(5,3000.0,15));
		ticket1.register(new AdvancedTicket(6,5000.0,20));
		ticket1.register(new AdvancedTicket(7,1000.0,40));
		
		ticket1.showAdvancedTicket(18);
		ticket1.showAdvancedTicket(45);

		//Ticket1
		/*AdvancedTicket t1 = new AdvancedTicket(1,5000.0,45);
		AdvancedTicket t2 = new AdvancedTicket(2,5000.0,25);
		System.out.println(t1);
		System.out.println(t2);*/
		
		
		
		//Bank
		/*BankManager Bank1 = new BankManager("건국은행",10);
		BankManager Bank2 = new BankManager("세종은행",20);
		
		Bank1.createAccount();
		Bank1.createAccount();
		Bank1.deposit();
		Bank1.withdraw();
		Bank1.transfer();*/
		
		//System.out.println(Bank1);
		//System.out.println(acc1);
		//System.out.println(acc2);
		
		/*acc1.deposit(1000);
		acc1.withdraw(3000);
		acc1.transfer(acc2,1500);
		System.out.println(acc1);
		System.out.println(acc2);*/
	}
}
