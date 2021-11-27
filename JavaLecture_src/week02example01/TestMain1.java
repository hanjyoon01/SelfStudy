package week02example01;

import java.io.IOException;

public class TestMain1 {

	public static void main(String[] args) throws IOException {
		
//		int code = System.in.read();
//		char ch = (char)System.in.read();
//		System.out.printf("%2$d, %1$c\n", ch, code);
		
		int code;
		while((code=System.in.read())!= -1) {
			System.out.println("code=" + code);
		}
		code=System.in.read();
		System.out.println("code=" + code);
		code=System.in.read();
		System.out.println("code=" + code);
		code=System.in.read();
		System.out.println("code=" + code);
	}

}
