package week07lab2;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class TestMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("202011390 한재윤");
		fileMerge("words1.txt","words2.txt","words.txt");
	}



	private static void fileMerge(String filename1, String filename2, String filename3) {
		// TODO Auto-generated method stub
//		Scanner input1 = null;
//		Scanner input2 = null;
//		PrintWriter output = null;
		try(Scanner input1 = new Scanner(new File(filename1));
			Scanner input2 = new Scanner(new File(filename2));
			PrintWriter output = new PrintWriter(new File(filename3))) {
			
 
//			input1 = new Scanner(new File(filename1));
//			input2 = new Scanner(new File(filename2));
//			output = new PrintWriter(new File(filename3));
			
			fileWriter(input1,input2,output);
			
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			System.err.println(e.getMessage());
			//e.printStackTrace();
		}
//		}finally {
//			if(input1!=null)input1.close();
//			if(input2!=null)input2.close();
//			if(output!=null)output.close();
//		}
	}

	private static void fileWriter(Scanner input1, Scanner input2, PrintWriter output) {
		// TODO Auto-generated method stub
		
		String i1 = input1.nextLine();
		String i2 = input2.nextLine();
		
		while(true) {
			
			
			if(input1.hasNextLine() && input2.hasNextLine()) {
				if(i1.compareTo(i2)<0) {
					output.println(i1);
					i1 = input1.nextLine();
				}
				else {
					output.println(i2);
					i2 = input2.nextLine();
				}
			}
			
			else if(!input1.hasNextLine() || !input2.hasNextLine()) {
				
				if(input1.hasNextLine() && !input2.hasNextLine()) {	
					if(i1.compareTo(i2)<0) {
						output.println(i1);
						i1 = input1.nextLine();
					}
					else {
						output.println(i2);
						while(input1.hasNextLine()) {
							output.println(i1);
							i1 = input1.nextLine();
						}
						output.println(i1);
						break;
					}
				}
				else if(!input1.hasNextLine() && input2.hasNextLine()) {
					if(i1.compareTo(i2)<0) {
						output.println(i1);
						while(input2.hasNextLine()) {
							output.println(i2);
							i2 = input2.nextLine();
						}
						output.println(i2);
						break;
					}
					else {
						output.println(i2);
						i2 = input2.nextLine();
					}
				}
				else {
					if(i1.compareTo(i2)<0) {
						output.println(i1);
						output.println(i2);
						break;
					}
					else {
						output.println(i2);
						output.println(i1);
						break;
					}
				}
			}			
		}
	}
}
