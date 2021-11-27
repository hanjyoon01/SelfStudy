package Week05lab;

public class AdvancedTicket extends Ticket {
	
	private int advancedDays;

	public AdvancedTicket(int number, double price, int advancedDays) {
		super(number, price);
		this.advancedDays = advancedDays;
	}

	public int getAdvancedDays() {
		return advancedDays;
	}

	public void setAdvancedDays(int advancedDays) {
		this.advancedDays = advancedDays;
	}

	@Override
	public double getPrice() {
		if(this.advancedDays>=30)
			return super.getPrice()*0.7;
		else if(this.advancedDays>=20)
			return super.getPrice()*0.8;
		else if(this.advancedDays>=10)
			return super.getPrice()*0.9;
		else
			return super.getPrice();
	}


	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return super.toString()+"\n예약일: "+this.getAdvancedDays()+"일 전\n결제금액: "+this.getPrice()+"\n";
	}
}
