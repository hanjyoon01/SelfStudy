package week11.lab.swing1;

import java.awt.BorderLayout;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class MyFrameProject extends JFrame {

	JButton btn1 = new JButton("단어장 생성");
	JButton btn2 = new JButton("단어 검색1");
	JButton btn3 = new JButton("단어 검색2");
	JButton btn4 = new JButton("객관식 퀴즈");
	JButton btn5 = new JButton("빈출 단어");
	JButton btn6 = new JButton("오답 노트");
	
	JPanel panel1, panel2;
	
	public MyFrameProject() {
		this("202011390 한재윤");
	}

	public MyFrameProject(String title) {
		// TODO Auto-generated constructor stub
		super(title);
		this.setSize(500,500);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	public void init() {
		
		this.setLayout(new BorderLayout());
		panel1 = new JPanel(new GridLayout(2,3));
		panel1.add(btn1, BorderLayout.CENTER);
		panel1.add(btn2, BorderLayout.CENTER);
		panel1.add(btn3, BorderLayout.CENTER);
		panel1.add(btn4, BorderLayout.CENTER);
		panel1.add(btn5, BorderLayout.CENTER);
		panel1.add(btn6, BorderLayout.CENTER);
		
		
	}
}
