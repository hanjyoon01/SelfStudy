package Week05lab;

public class GeneralTicket extends Ticket {
	
	private boolean payByCredit;
	
	public GeneralTicket(int number, boolean payByCredit) {
		this(number,0.0, payByCredit);
		//this.payByCredit = payByCredit;
	}
	
	public GeneralTicket(int number, double price, boolean payByCredit) {
		super(number, price);
		this.payByCredit = payByCredit;
	}

	public boolean isPayByCredit() {
		return payByCredit;
	}

	public void setPayByCredit(boolean payByCredit) {
		this.payByCredit = payByCredit;
	}

	@Override
	public double getPrice() {
		// TODO Auto-generated method stub
		if(this.payByCredit)
			return this.price*1.1;
		else
			return this.price;
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return super.toString()+"\n카드 결제: "+this.isPayByCredit()+"\n결제금액: "+this.getPrice()+"\n";
	}


	
	
}
