package week13lab3;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.filechooser.FileNameExtensionFilter;

public class MyFrame extends JFrame implements ActionListener{

	Container frame = this.getContentPane();
	JPanel panel = new JPanel();
	MyLabel label = new MyLabel();
	JButton btn1,btn2;
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
		btn1 = new JButton("불러오기");
		btn1.addActionListener(this);
		btn2 = new JButton("저장하기");
		btn2.addActionListener(this);
		panel.add(btn1);
		panel.add(btn2);
		frame.add(panel, BorderLayout.NORTH);
		frame.add(label, BorderLayout.CENTER);
		
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource()==btn1) {
			JFileChooser dlg = new JFileChooser();
			FileNameExtensionFilter filter = new FileNameExtensionFilter("jpg Images", "jpg", "jpeg");
			dlg.setFileFilter(filter);
			filter = new FileNameExtensionFilter("gif Images", "gif");
			dlg.setFileFilter(filter);
			
			int ret = dlg.showOpenDialog(null);
			if(ret == JFileChooser.APPROVE_OPTION) {
				File imgFile = dlg.getSelectedFile();
				label.setIcon(new ImageIcon(imgFile.getPath()));
				this.pack();
			}
		}else if(e.getSource()==btn2) {
			
			BufferedImage img = new BufferedImage(label.getWidth(),label.getHeight(),BufferedImage.TYPE_INT_RGB);
			Graphics g = img.getGraphics();
			label.printAll(g);
			g.dispose();
			
			JFileChooser dlg = new JFileChooser();
			FileNameExtensionFilter filter = new FileNameExtensionFilter("image file", "jpg", "png");
			dlg.setFileFilter(filter);
			int ret = dlg.showSaveDialog(null);
			if(ret == JFileChooser.APPROVE_OPTION) {
				String str = dlg.getSelectedFile().toString();
				String format = str.substring(str.length()-3, str.length());
				try {
					ImageIO.write(img, format, dlg.getSelectedFile());
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				this.pack();
			}
		}
	}
	
	class MyLabel extends JLabel{
		
		Point pt = new Point(-100,100);
		
		MyLabel(){
			this.addMouseListener(new MouseAdapter() {

				@Override
				public void mouseClicked(MouseEvent e) {
					// TODO Auto-generated method stub
					super.mouseClicked(e);
					pt = e.getPoint();
					repaint();
				}
			});
		}

		@Override
		protected void paintComponent(Graphics g) {
			// TODO Auto-generated method stub
			super.paintComponent(g);
			g.setColor(Color.ORANGE);
			g.fillOval(pt.x-25, pt.y-25, 50, 50);	
		}
	}
}
