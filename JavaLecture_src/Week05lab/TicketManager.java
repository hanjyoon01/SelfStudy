package Week05lab;

public class TicketManager {
	Ticket[] tickets;
	int number;
  	int count=0;
	String name;
	
	
	public TicketManager(String name, int number) {
		super();
		this.number = number;
		this.name = name;
		tickets = new Ticket[this.number];
	}
	
	public void showGeneralTicket(boolean payByCredit) {
		for(Ticket ticket:tickets) {
			if(ticket!=null & ticket instanceof GeneralTicket) {
				GeneralTicket t = (GeneralTicket)ticket;
				if(t.isPayByCredit()==payByCredit) {
					System.out.println(t.toString());
				}
			}
		}
	}
	
	public void showAdvancedTicket(int day) {
		for(Ticket ticket:tickets) {
			if(ticket!=null & ticket instanceof AdvancedTicket) {
				AdvancedTicket t = (AdvancedTicket)ticket;
				if(t.getAdvancedDays()>day) {
					System.out.println(t.toString());
				}
			}
		}
		System.out.println("--------------------------");
	}
	
	public void register(Ticket ticket) { //다형성
		if(this.count < this.number)
			this.tickets[this.count++] = ticket;
		else
			System.out.println("티켓 판매 완료");
	}
	
	public double getTotal() {
		double total = 0.0;
		for(Ticket ticket:tickets) {
			if(ticket != null) {
				total+=ticket.getPrice();
			}else
				break;
		}
		return total;
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		String str = "공연명: "+this.name+"\n";
		str+="좌석수: "+this.number+"\n";
		str+="총 판매티켓 수: "+this.count+"\n";
		str+="--------------------\n";
		for(Ticket ticket:tickets) {
			if(ticket!=null)
				str+= ticket.toString() + "\n---------------\n";
			else
				break;
		}
		str+="총 티켓 판매 금액: "+this.getTotal()+"\n";
		
		return str;
	}
	
	


}
