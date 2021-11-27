package Week06lab;

import java.util.Scanner;

public class TV extends HomeAppliance {
	private int channel = 10;

	public TV(String haName, int channel) {
		super(haName);
		this.channel = channel;
	}

	public int getChannel() {
		return channel;
	}

	public void setChannel(int channel) {
		this.channel = channel;
	}
	
	@Override
	public void showStatus() {
		if(this.isHaPower())
			System.out.println(this.getHaName()+", 전원상태: "+this.isHaPower()+", 채널: "+this.channel+"번 시청 중");
		else
			System.out.println(this.getHaName()+", 천원 꺼져 있음");
	}
	
	@Override
	public void menu() {
		Scanner scan = new Scanner(System.in);
		System.out.println("TV를 제어합니다.");
		System.out.print("1)전원  2)채널\n원하는메뉴를 선택하세요: ");
		int choice = scan.nextInt();
		switch(choice) {
		case 1:
			this.setHaPower(!this.isHaPower());
			break;
		case 2:
			if(this.isHaPower()) {
				System.out.print("채널 입력: ");
				setChannel(scan.nextInt());
			}else
				System.out.println("전원이 꺼져있습니다.");
			break;
		default:
			System.out.println("입력 메뉴를 확인하세요.");
		}
		System.out.println("TV 제어 종료");
	}
}
