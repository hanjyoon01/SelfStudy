package week12.lab.swing1;

import java.awt.Container;

import javax.swing.JFrame;

public class MyFrame extends JFrame {
	
	Container frame = this.getContentPane();
	
	public MyFrame() {
		this("202011390 한재윤");
	}

	public MyFrame(String title) {
		// TODO Auto-generated constructor stub
		super(title);
		this.setSize(500,500);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	public void init() {
		
	}
}
