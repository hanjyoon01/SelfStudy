package week13lab3;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.List;

public class TestMain2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

//		List<String> list = new ArrayList<>();
//		list.add("greenjoa1");
//		list.add("greenjoa2");
//		list.add("greenjoa3");
//		list.add("greenjoa4");
//		
//		try {
//			FileOutputStream fout = new FileOutputStream("greenjoa.dat");
//			ObjectOutputStream out = new ObjectOutputStream(fout);
//			out.writeObject(list);
//			out.flush();
//			out.close();
//		} catch(IOException e) {
//			e.printStackTrace();
//		}
		
//      ================
		
//		List<MyData> list = new ArrayList<>();
//		list.add(new MyData("greenjoa1",1));
//		list.add(new MyData("greenjoa2",2));
//		list.add(new MyData("greenjoa3",3));
//		list.add(new MyData("greenjoa4",10));
//		
//		try {
//			FileOutputStream fout = new FileOutputStream("greenjoa1.dat");
//			ObjectOutputStream out = new ObjectOutputStream(fout);
//			out.writeObject(list);
//			out.flush();
//			out.close();
//		} catch(IOException e) {
//			e.printStackTrace();
//		}
		
		
		try {
			FileInputStream fos = new FileInputStream("greenjoa1.dat");
			ObjectInputStream ios = new ObjectInputStream(fos);
			@SuppressWarnings("unchecked")
			List<MyData> list1 = (List<MyData>)ios.readObject();
			for(MyData str:list1) {
				System.out.println(str.name+" : "+str.num);
			}
		
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
	}

}
