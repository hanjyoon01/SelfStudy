package week02example03;

public class TestMain3 {

	public static void main(String[] args) {
		
		int a = 10;
		int b = -8;
		
		String temp = "00000000000000000000000000000000";
		String aStr = temp + Integer.toBinaryString(a);
		String aBiStr = aStr.substring(aStr.length()-32);
		
		System.out.println("a:"+aBiStr);
		System.out.println("b:"+Integer.toBinaryString(b));
		
		a = a^b;
		b = a^b;
		a = a^b;

		temp = "00000000000000000000000000000000";
		aStr = temp + Integer.toBinaryString(b);	
		System.out.println("=================================");
		System.out.println("a:"+Integer.toBinaryString(a));
		System.out.println("b:"+aBiStr);
	}
}
