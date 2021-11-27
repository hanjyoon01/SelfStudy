package week10.lab.swing1;

import java.awt.Color;
import java.awt.Point;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;


@SuppressWarnings("serial")
public class MyFrame extends JFrame {

	
	String[] imgpath = {"img/Down.png","img/Left.png","img/Right.png","img/Up.png"};
	ImageIcon[] icons = new ImageIcon[imgpath.length];
	JLabel player;
	int imgWidth, imgHeight;
	Point pos = new Point(100,100);
	
	public MyFrame() {
		this("202011390 한재윤");
	}
	
	public MyFrame(String title) {
		super(title);
		this.setSize(500,500);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	public void init() {
	
		for(int i=0;i<icons.length;i++) {
			icons[i] = new ImageIcon(imgpath[i]);
		}
		player = new JLabel(icons[0]);
		imgWidth = icons[0].getIconWidth();
		imgHeight = icons[0].getIconHeight();
		this.setLayout(null);
		player.setSize(imgWidth, imgHeight);
		player.setLocation(pos);
		this.add(player);
		this.getContentPane().setBackground(Color.WHITE);
		initKeyListener();
		initMouseListener();
		
//		this.addWindowListener(new MyWindowAdapter2());
//		this.addWindowListener(new WindowAdapter() {
//			@Override
//			public void windowClosing(WindowEvent e) {
//				// TODO Auto-generated method stub
//				super.windowClosing(e);
//				System.exit(0);
//			}
//		});
		
	}
	
	public void initMouseListener() {
		this.addMouseListener(new MyMouseListener());
		this.addMouseListener(new MouseAdapter() {
			
			@Override
			public void mouseEntered(MouseEvent e) {
				// TODO Auto-generated method stub
				super.mouseEntered(e);
				setSize(500,500);
				getContentPane().setBackground(Color.ORANGE);
			}

			@Override
			public void mouseExited(MouseEvent e) {
				// TODO Auto-generated method stub
				super.mouseExited(e);
				setSize(300,300);
				getContentPane().setBackground(Color.PINK);
			}
		});
	}
	
	class MyMouseListener extends MouseAdapter{

		@Override
		public void mouseEntered(MouseEvent e) {
			// TODO Auto-generated method stub
			super.mouseEntered(e);
			setSize(500,500);
			getContentPane().setBackground(Color.ORANGE);
		}

		@Override
		public void mouseExited(MouseEvent e) {
			// TODO Auto-generated method stub
			super.mouseExited(e);
			setSize(300,300);
			getContentPane().setBackground(Color.PINK);
		}
	}

	public void initKeyListener() {
		this.addKeyListener(new KeyAdapter() {

//			@Override
//			public void keyTyped(KeyEvent e) {
//				// TODO Auto-generated method stub
//				super.keyTyped(e);
//				switch(e.getKeyChar()) {
//				case 'd':
//					pos.y += 10;
//					player.setIcon(icons[0]);
//					break;
//				case 'a':
//					pos.x -= 10;
//					player.setIcon(icons[1]);
//					break;
//				case 'f':
//					pos.x += 10;
//					player.setIcon(icons[2]);
//					break;
//				case 's':
//					pos.y -= 10;
//					player.setIcon(icons[3]);
//					break;
//				}
//				player.setLocation(pos);
//			}

			@Override
			public void keyPressed(KeyEvent e) {
				// TODO Auto-generated method stub
				super.keyPressed(e);
				switch(e.getKeyCode()) {
				case KeyEvent.VK_DOWN:
					pos.y += 10;
					player.setIcon(icons[0]);
					break;
				case KeyEvent.VK_LEFT:
					pos.x -= 10;
					player.setIcon(icons[1]);
					break;
				case KeyEvent.VK_RIGHT:
					pos.x += 10;
					player.setIcon(icons[2]);
					break;
				case KeyEvent.VK_UP:
					pos.y -= 10;
					player.setIcon(icons[3]);
					break;
				}

				switch(e.getKeyChar()) {
				case 'd':
					pos.y += 10;
					player.setIcon(icons[0]);
					break;
				case 'a':
					pos.x -= 10;
					player.setIcon(icons[1]);
					break;
				case 'f':
					pos.x += 10;
					player.setIcon(icons[2]);
					break;
				case 's':
					pos.y -= 10;
					player.setIcon(icons[3]);
					break;
				}
				player.setLocation(pos);
			}
			
		});
	}
	
//	class MyWindowAdapter2 extends java.awt.event.WindowAdapter {
//		@Override
//		public void windowOpened(WindowEvent e) {
//			// TODO Auto-generated method stub
//			super.windowOpened(e);
//			String name = JOptionPane.showInputDialog("닉네임을 입력하세요");
//			setTitle(name);
//		}
		
}
