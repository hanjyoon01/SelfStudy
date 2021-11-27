package week02.hjy.konkuk;

public class RGBChange {

	public static void main(String[] args) {
		
		int rgb = 0xffffff00; 
		int Egreen = 0xffff00ff; // 그린 색상만 제거
		String Crgb; // 변경 색상
		String strRgb = Integer.toBinaryString(rgb);
		
		System.out.println("202011390 한재윤");
		
		System.out.println("현재색상:"+ strRgb);
		Crgb = Integer.toBinaryString(rgb & Egreen); // and 연산 수행
		System.out.println("변경색상:"+ Crgb);

	}

}
