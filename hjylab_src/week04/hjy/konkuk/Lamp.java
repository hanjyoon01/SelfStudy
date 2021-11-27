package week04.hjy.konkuk;

public class Lamp {
	public boolean isOn;
	public int illuminance;
	
	public Lamp() {
		this(false, 1);
	}

	public Lamp(boolean isOn, int illuminance) {
		this.isOn = isOn;
		this.illuminance = illuminance;
	}
	
	public void turnOnOff() {
		if(isOn == true) {
			isOn = false;
			System.out.println("전원이 꺼졌습니다.");
		}
			
		else {
			isOn = true;
			System.out.println("전원이 켜졌습니다.(조도:"+illuminance+")");
		}
	}
	
	public void changeLight() {
		if (isOn == false) {
			System.out.println("전원을 켜주세요.");
		}
		else {
			 if(illuminance == 3)
				  illuminance = 1;
			  else
				  illuminance++;
			 System.out.println("조도:"+illuminance);
		}
	}
}
