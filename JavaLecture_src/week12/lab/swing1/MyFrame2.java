package week12.lab.swing1;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class MyFrame2 extends JFrame {
	
	Container frame = this.getContentPane();
	MyPanel panel = new MyPanel();
	JPanel panel2 = new JPanel();
	JLabel label = new JLabel();
	
	public MyFrame2() {
		this("202011390 한재윤");
	}

	public MyFrame2(String title) {
		// TODO Auto-generated constructor stub
		super(title);
		this.setSize(500,500);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	public void init() {
		
		MyImageBtn btn1 = new MyImageBtn("img/char1.png");
		panel2.add(btn1);
		btn1.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				label.setIcon(new ImageIcon("img/char1.png"));
			}
			
		});
		frame.add(panel2, BorderLayout.NORTH);
		panel.add(label);
		frame.add(panel, BorderLayout.CENTER);
	}
	
	class MyImageBtn extends JButton{
		ImageIcon icon;
		Image img;
		MyImageBtn(String imgname){
			icon = new ImageIcon(imgname);
			img = icon.getImage();
			this.setPreferredSize(new Dimension(50,100));
		}
		@Override
		protected void paintComponent(Graphics g) {
			// TODO Auto-generated method stub
			super.paintComponent(g);
			g.drawImage(img, 0, 0, this.getWidth(), this.getHeight(), 0, 0, img.getWidth(null), img.getHeight(null), null);
		}
	}
}
