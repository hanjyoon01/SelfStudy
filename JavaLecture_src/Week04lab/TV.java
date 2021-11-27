package Week04lab;

public class TV {
	public boolean power;
	public int channel=10;
	public int volume=10;
	
	public TV(boolean p) {
		power = p; 
	}
	public TV(boolean p, int c) {
		power = p; 
		channel = c;
	}

	public TV(TV tv) {
		// TODO Auto-generated constructor stub
		this.channel = tv.channel;
		this.power = tv.power;
	}
	public void show() {
		if(power) 
			System.out.println("현재 "+channel+"번 시청중");
		else
			System.out.println("전원이 꺼져있음");
	}
	public void poweronoff() {
		power = !power;
		show();
	}
	public void channelup() {
		if(power) {
			channel++;
			show();
		}
		else
			System.out.println("전원을 먼저 키세요.");
	}
	public void channeldown() {
		if(power) {
			channel--;
			show();
		}
		else
			System.out.println("전원을 먼저 키세요.");
	}
	public void volumeup() {
		if(power) {
			if (volume<20) {
				volume++;
				System.out.println("볼륨:"+volume);
			}
			else
				System.out.println("볼륨은 20을 넘어갈 수 없습니다.");
		}
		else
			System.out.println("전원을 먼저 키세요.");
	}
	public void volumedown() {
		if(power) {
			if (volume>0) {
				volume--;
				System.out.println("볼륨:"+volume);
			}
			else
				System.out.println("볼륨은 0보다 작을 수 없습니다.");
		}
		else
			System.out.println("전원을 먼저 키세요.");
	}
	
	public void changeChannel(int n) {
		channel = n;
		show();
	}
	
	public void changeVolume(int n) {
		if (n<0 || n>20) 
			System.out.println("볼륨은 0과 20 사이의 값만 가능합니다.");
		else {
			volume = n;
			System.out.println("볼륨:"+volume);
		}
	}
}