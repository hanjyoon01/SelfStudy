package week13lab2;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class TestMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			
//			FileWriter fout = new FileWriter("data/copyWords.txt");
//			FileReader fin = new FileReader("data/words.txt");
			
			FileInputStream fis = new FileInputStream("data/words.txt");
			FileOutputStream fout = new FileOutputStream("data/copyWords4.txt");
		
			InputStreamReader reader = new InputStreamReader(fis);
			OutputStreamWriter writer = new OutputStreamWriter(fout,"euc-kr");
			
			
			char[] buffer = new char[1024];
			
			while(true) {
				int len = reader.read(buffer);
				if(len>0) {
					writer.write(buffer,0,len);
				}else
					break;
			}
			
			writer.flush();
			writer.close();
			reader.close();
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}

}
