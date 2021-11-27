package week13lab1;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;

public class TestMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			FileOutputStream fout = new FileOutputStream("data/copyBack2.jpg");
			FileInputStream fin = new FileInputStream("img/back.jpg");
		
			byte[] buffer = new byte[1024];
			
			while(true) {
				int len = fin.read(buffer);
				if(len>0) {
					fout.write(buffer,0,len);
					//System.out.println(data);
				}else
					break;
			}
			fout.flush();
			fout.close();
			fin.close();
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
