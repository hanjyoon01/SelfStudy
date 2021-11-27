package Week06lab;

public class TestMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("202011390 한재윤");
		Home home = new Home(10);
		home.buyHA(new TV("건국TV", 15));
		home.buyHA(new Refrigerator("건국냉장고", 15));
		home.buyHA(new Boiler("건국보일러", 20));
		home.buyHA(new Vacuum("건국청소기", 1));
		home.buyHA(new TV("대학TV", 10));
		
		IoTInterface iot = (IoTInterface) home.connect();
		if(iot!=null) {
			iot.turnOn();
			iot.control();
			iot.turnOff();
		}else {
			System.out.println("connect 실패");
		}
	}
}
