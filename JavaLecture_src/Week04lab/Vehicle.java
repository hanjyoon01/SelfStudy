package Week04lab;

public class Vehicle {
	public String color;
	public int speed;
	public int mileage;
	public char gearStatus;
	public TV tv;
	
	public Vehicle() {
		this("검정색",0,0,'P');
	//	this.color = "검정색";
	//	this.speed = 0;
	//	this.mileage = 0;
	//	this.speed = 0;
	//	this.gearStatus = 'P';
	}
	public Vehicle(String color, int mileage) {
		this(color,0,mileage,'P');
		System.out.println(this);
	//	this.color = color;
	//	this.speed = 0;
	//	this.mileage = mileage;
	//	this.gearStatus = 'P';
	}
	
	public Vehicle(String color, int speed, int mileage, char gearStatus) {
		this.color = color;
		this.speed = speed;
		this.mileage = mileage;
		this.gearStatus = gearStatus;
	}

	public Vehicle(String color, int speed, int mileage, char gearStatus, TV tv) {
		this.color = color;
		this.speed = speed;
		this.mileage = mileage;
		this.gearStatus = gearStatus;
		this.tv = tv;
	}

	public Vehicle(Vehicle car1) {
		// TODO Auto-generated constructor stub
		this(car1.color,car1.speed,car1.mileage,car1.gearStatus,new TV(car1.tv));
	}
	public void accelerate(int speed) {
		if((this.gearStatus!='P')&&(this.gearStatus!='N')) {
			this.speed += speed;
			this.mileage += speed;
		}
		else
			System.out.println("현재 기어상태는 "+this.gearStatus+"상태입니다.");
	}
	public void breaker(int speed) {
		if((this.gearStatus!='P')&&(this.gearStatus!='N')) {
			this.speed -= speed;
			this.mileage += this.speed;
		}
		else
			System.out.println("현재 기어상태는 "+this.gearStatus+"상태입니다.");
	}
	public void showStatus() {
		switch(this.gearStatus) {
		case 'P':
			System.out.println("주차중"); break;
		case 'N':
			System.out.println("중립모드"); break;
		case 'D':
			System.out.println("주행중"); break;
		case '1':
			System.out.println("저속운행중"); break;
		case '2':
			System.out.println("저속운행중"); break;
		}
		System.out.println("====================");
		System.out.println("차의 색상 : "+this.color);
		System.out.println("차의 속도 : "+this.speed);
		System.out.println("차의 기어상태 : "+this.gearStatus);
		if(tv!=null)
			tv.show();
		System.out.println("====================");
	}
	public void changeGear(char gearStatus) {
		this.gearStatus = gearStatus;
		switch(this.gearStatus) {
		case 'P' : 
		case 'N' :
			this.speed = 0; break;
		case '1' :
		case '2' :
			this.speed = 30; break;
			
		}
	}
}
