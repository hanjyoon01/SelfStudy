package week13lab3;

import java.io.Serializable;

public class MyData implements Serializable {

	private static final long serialVersionUID = 1L;
	String name;
	int num;
	int score;
	public MyData(String name, int num) {
		super();
		this.name = name;
		this.num = num;
	}
}
