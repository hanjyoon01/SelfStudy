package week09.lab.swing2;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class MyFrame extends JFrame {

	JPanel panel1, panel2;
	JLabel imgChar = new JLabel();
	ImageIcon img = new ImageIcon("img/char1.png");
	int xpos=100, ypos=100;
	
	public MyFrame() {
		this("202011390 한재윤");
	}
	
	public MyFrame(String title) {
		super(title);
		this.setSize(500,500);
		this.setLocation(500,500);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		init();
		this.setVisible(true);
	}

	
	public void init() {
		
		initPanel1();
		
		initPanel2();
		
	}
	
	public void initPanel1() {

		panel1 = new JPanel(new GridLayout(4,1,10,10));

		JButton btn1 = new JButton("▲");
		btn1.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(ypos > 10) {
					ypos -= 10;
					imgChar.setBounds(xpos,ypos,img.getIconWidth(),img.getIconHeight());	
				}
			}
		});
		panel1.add(btn1);
		
		JButton btn2 = new JButton("▼");
		btn2.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(ypos < panel2.getHeight() - img.getIconHeight()) {
					ypos += 10;
					imgChar.setBounds(xpos,ypos,img.getIconWidth(),img.getIconHeight());	
				}
				imgChar.setBounds(xpos,ypos,img.getIconWidth(),img.getIconHeight());
			}
		});
		panel1.add(btn2);
		
	
		JButton btn3 = new JButton("◀");
		btn3.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(xpos >= 10) {
					xpos -= 10;
					imgChar.setBounds(xpos,ypos,img.getIconWidth(),img.getIconHeight());	
				}
			}
		});
		panel1.add(btn3);
		
		JButton btn4 = new JButton("▶");
		btn4.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(xpos < panel2.getWidth()-img.getIconWidth()) {
					xpos += 10;
					imgChar.setBounds(xpos,ypos,img.getIconWidth(),img.getIconHeight());	
				}
			}
		});
		panel1.add(btn4);

		
		this.add(panel1,BorderLayout.WEST);
	}
	
	public void initPanel2() {
		// TODO Auto-generated method stub
		panel2 = new JPanel();
		panel2.setLayout(null);
		imgChar.setIcon(img);
		panel2.add(imgChar);
		imgChar.setBounds(xpos,ypos,img.getIconWidth(),img.getIconHeight());
		this.add(panel2,BorderLayout.CENTER);
	}
}
