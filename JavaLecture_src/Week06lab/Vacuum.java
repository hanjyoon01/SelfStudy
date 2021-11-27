package Week06lab;

import java.util.Scanner;

public class Vacuum extends HomeAppliance implements IoTInterface{
	private int level = 1;

	public Vacuum(String haName, int level) {
		super(haName);
		this.level = level;
	}

	@Override
	public void showStatus() {
		if(this.isHaPower())
			System.out.println(this.getHaName()+", 전원상태: "+this.isHaPower()+", 청소기 세기: "+this.level+"레벨");
		else
			System.out.println(this.getHaName()+", 천원 꺼져 있음");
	}
		
	@Override
	public void menu() {
		Scanner scan = new Scanner(System.in);
		System.out.println("청소기를 제어합니다.");
		System.out.print("1)전원  2)청소 레벨\n원하는메뉴를 선택하세요: ");
		int choice = scan.nextInt();
		switch(choice) {
		case 1:
			this.setHaPower(!this.isHaPower());
			break;
		case 2:
			if(this.isHaPower()) {
				System.out.print("청소 레벨 입력(1~3): ");
				int level = scan.nextInt();
				if(level>=1 && level <=3) {
					this.setLevel(level);
				}else
					setLevel(1);
				System.out.println("청소 강도 "+this.level+"로 동작중입니다.");
			}else
				System.out.println("전원이 꺼져있습니다.");
			break;
		default:
			System.out.println("입력 메뉴를 확인하세요.");
		}
		System.out.println("청소기 제어 종료");
	}

	
	public int getLevel() {
		return level;
	}

	public void setLevel(int level) {
		this.level = level;
	}

	@Override
	public void turnOn() {
		// TODO Auto-generated method stub
		this.setHaPower(true);
	}

	@Override
	public void turnOff() {
		// TODO Auto-generated method stub
		this.setHaPower(false);
	}

	@Override
	public void control() {
		// TODO Auto-generated method stub
		menu();
	}
}
