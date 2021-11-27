package week12.lab.swing1;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.text.SimpleDateFormat;
import java.util.Calendar;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class MyFrame3 extends JFrame {
	
	Container frame = this.getContentPane();
	
	public MyFrame3() {
		this("202011390 한재윤");
	}

	public MyFrame3(String title) {
		// TODO Auto-generated constructor stub
		super(title);
		this.setSize(500,500);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	public void init() {
		MyLabel label = new MyLabel();
		frame.add(label, BorderLayout.NORTH);
	}
}

class MyLabel extends JLabel implements Runnable{

	SimpleDateFormat date = new SimpleDateFormat("YYYY년 MM월 dd일 HH시 mm분 ss초");
	
	MyLabel(){
		this.setOpaque(true);
		this.setFont(new Font("궁서체", Font.BOLD, 24));
		this.setHorizontalAlignment(CENTER);
		this.setBackground(Color.GREEN);
		Thread th = new Thread(this);
		th.start();
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub
		while(true) {
			this.setText(date.format(Calendar.getInstance().getTime()));
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
