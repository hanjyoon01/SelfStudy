package week13lab3;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class TestMain3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File file = new File("data/copyWords4.txt");
		try {
			Scanner scan = new Scanner(file, "euc-kr"); //"utf-8"
			FileOutputStream fout = new FileOutputStream("data/copyWords5.txt");
			PrintWriter out = new PrintWriter(fout);
			
			while(scan.hasNext()) {
				String str = scan.nextLine();
				//System.out.println(str);
				out.println(str);
			}
			scan.close();
			out.flush();
			out.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
