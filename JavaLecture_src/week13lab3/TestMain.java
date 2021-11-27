package week13lab3;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class TestMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try {
			
			FileInputStream fis = new FileInputStream("bgm/bgm1.mp3");
			FileOutputStream fout = new FileOutputStream("data/copybgm.mp3");;
			
			BufferedInputStream bis = new BufferedInputStream(fis);
			BufferedOutputStream bout = new BufferedOutputStream(fout);
			
			while(true) {
				int data = bis.read();
				if(data!=-1) {
					bout.write(data);
				}else
					break;
			}
			
			bout.flush();
			bout.close();
			bis.close();
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}

}
