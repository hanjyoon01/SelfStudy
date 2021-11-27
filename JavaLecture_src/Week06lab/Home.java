package Week06lab;

import java.util.Scanner;

public class Home {
	private HomeAppliance[] apps;
	private int capacity;
	private int count = 0;
	
	public Home(int capacity) {
		super();
		this.capacity = capacity;
		apps = new HomeAppliance[this.capacity];
	}
	
	public void buyHA(HomeAppliance app) {
		if(this.count < this.capacity) {
			apps[count++] = app;
		}
		else 
			System.out.println("더 이상 공간이 남아있지 않음");
	}
	
	public void open() {
		while(true) {
			System.out.println("제어할 가전제품을 선택하세요: ");
			for (int i = 0; i < count; i++) {
				System.out.println((i + 1) + ")" + apps[i].getHaName());
			}
			System.out.print("제품을 선택해주세요: ");
			Scanner scan = new Scanner(System.in);
			int index = scan.nextInt();
			if (index >= 1 && index <= count) {
				apps[index - 1].menu();
				apps[index - 1].showStatus();
			}else {
				System.out.println("가전제품 제어 종료");
				break;
			}
		}
	}
	
	public HomeAppliance connect() {
		System.out.println("원격 제어할 가전제품을 선택하세요: ");
		scanIoTDevice();
		System.out.print("제품을 선택해주세요: ");
		Scanner scan = new Scanner(System.in);
		int index = scan.nextInt();
		return apps[index-1];
	}
		 
	
public void scanIoTDevice() {
		System.out.println("원격 제어 가능 제품");
		for(int i=0;i<count;i++) {
			if(apps[i] instanceof IoTInterface)
				System.out.println((i + 1) + ")" + apps[i].getHaName());
		}
	}
}
