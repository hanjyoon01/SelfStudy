package week09.lab.swing1;

import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class MyFrame extends JFrame {

	int width;
	int height;
	JPanel panel1, panel2;
	String[] str = {"빨강","초록","파랑","노랑","핑크","회색"};
	Color[] color = { Color.RED, Color.GREEN, Color.BLUE, Color.YELLOW, Color.PINK, Color.GRAY};
	JPanel[] card;
	CardLayout cl = new CardLayout();
	public MyFrame() {
		this("202011390 한재윤");
//		this.setTitle("202011390 한재윤");
//		this.setSize(500,500);
//		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
//		this.setVisible(true);
	}
	
	public MyFrame(String title) {
		super(title);
		Toolkit kit = Toolkit.getDefaultToolkit();
		Dimension screenSize = kit.getScreenSize();
		this.width = screenSize.width;
		this.height = screenSize.height;
		this.setSize(width/2, height/2);
		this.setLocation(width/4,height/4);
//		Image icon = kit.getImage("img/char1.png");
//		this.setIconImage(icon);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	public void init() {
		Container container = this.getContentPane();
//		container.setLayout(new BorderLayout(15,15));
		BorderLayout lm = (BorderLayout) container.getLayout();
		lm.setHgap(15);
		panel2 = new JPanel(cl);
		card = new JPanel[color.length];
		for(int i=0; i<color.length;i++) {
			card[i] = new JPanel();
			card[i].setBackground(color[i]);
			panel2.add(card[i], String.valueOf(i));
		}
		panel1 = new JPanel(new GridLayout(1,2,10,10));

		
		JButton btn1 = new JButton("<<");
		btn1.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				cl.previous(panel2);
			}
		});
		panel1.add(btn1);
		JButton btn2 = new JButton("HOME");
		btn2.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				cl.first(panel2);
			}
		});
		panel1.add(btn2);
		JButton btn3 = new JButton(">>");
		btn3.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				cl.next(panel2);
			}
		});
		panel1.add(btn3);
		
//		for(int i=0;i<str.length; i++) {
//			final int idx = i;
//			JButton btn = new JButton(str[i]);
//			btn.setBackground(color[i]);
//			btn.addActionListener(new ActionListener() {
//				@Override
//				public void actionPerformed(ActionEvent e) {
//					// TODO Auto-generated method stub
//					panel2.setBackground(color[idx]);
//				}
//			});
//			panel1.add(btn);
//		}
//		panel2.setBackground(Color.RED);
		
		cl.first(panel2);
		
		container.add(panel1,BorderLayout.NORTH);
		container.add(panel2,BorderLayout.CENTER);
	}
}
