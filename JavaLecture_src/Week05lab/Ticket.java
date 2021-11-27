package Week05lab;

public abstract class Ticket {
	protected int number;
	protected double price;
	
	public Ticket(int number, double price) {
		this.number = number;
		this.price = price;
	}

	public Ticket(int number) {
		this(number, 0.0);
		this.number = number;
	}
	

	public Ticket() {
		this(0,0.0);
	}
	
	
	public int getNumber() {
		return number;
	}


	public void setNumber(int number) {
		this.number = number;
	}

//	public abstract double getPrice();

	public double getPrice() {
		return price;
	}


	public void setPrice(double price) {
		this.price = price;
	}


	@Override
	public String toString() {
		return"티켓번호: "+this.number+"\n"+"티켓가격: " +this.price;
	}
}
