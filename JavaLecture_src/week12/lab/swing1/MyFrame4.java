package week12.lab.swing1;

import java.awt.Color;
import java.awt.Container;
import java.awt.Point;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.io.FileInputStream;
import java.io.FileNotFoundException;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

import javazoom.jl.decoder.JavaLayerException;
import javazoom.jl.player.Player;

public class MyFrame4 extends JFrame {
	
	Container frame = this.getContentPane();
	GamePanel panel = new GamePanel();
	
	public MyFrame4() {
		this("202011390 한재윤");
	}

	public MyFrame4(String title) {
		// TODO Auto-generated constructor stub
		super(title);
		this.setSize(500,500);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	public void init() {
		frame.add(panel);
		panel.setFocusable(true);
		panel.requestFocus();

	}
	
	class MusicThread extends Thread{

		@Override
		public void run() {
			// TODO Auto-generated method stub
			try {
				while(true) {
					FileInputStream fis = new FileInputStream("bgm/bgm1.mp3");
					Player mp3player = new Player(fis);
					mp3player.play();
				}
			} catch (FileNotFoundException | JavaLayerException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
	}
	class GamePanel extends JPanel{
		String[] img = {"img/Down.png", "img/Left.png",
				"img/Right.png","img/Up.png","img/char1.png"};
		
		ImageIcon[] icons = new ImageIcon[img.length];
		JLabel avatar;
		JLabel monster;
		
		final int AVATAR_MOVE = 10;
		Point pos = new Point(50,50);
		
		public GamePanel() {
			for(int i=0;i<icons.length;i++) {
				icons[i] = new ImageIcon(img[i]);
			}
			avatar = new JLabel(icons[0]);
			monster = new JLabel(icons[img.length-1]);
			
			this.setLayout(null);
			this.setBackground(Color.WHITE);
			this.addKeyListener(new MyKeyListener());
			avatar.setLocation(pos);
			avatar.setSize(icons[0].getIconWidth(), icons[0].getIconHeight());
			this.add(avatar);
			
			monster.setLocation(250,50);
			monster.setSize(icons[img.length-1].getIconWidth(), icons[img.length-1].getIconHeight());
			this.add(monster);
			
			MonsterThread th = new MonsterThread(avatar, monster);
			th.start();
			
			MusicThread mth = new MusicThread();
			mth.start();
			
		}
		
		class MyKeyListener extends KeyAdapter{

			@Override
			public void keyPressed(KeyEvent e) {
				// TODO Auto-generated method stub
				super.keyPressed(e);
				
				switch(e.getKeyCode()) {
				case KeyEvent.VK_DOWN:
					pos.y = pos.y + AVATAR_MOVE;
					avatar.setIcon(icons[0]);break;
				case KeyEvent.VK_LEFT:
					pos.x = pos.x - AVATAR_MOVE;
					avatar.setIcon(icons[1]);break;
				case KeyEvent.VK_RIGHT:
					pos.x = pos.x + AVATAR_MOVE;
					avatar.setIcon(icons[2]);break;
				case KeyEvent.VK_UP:
					pos.y = pos.y - AVATAR_MOVE;
					avatar.setIcon(icons[3]);break;
				}
				avatar.setLocation(pos);
				avatar.repaint();
			}	
		}
	}
	
	class MonsterThread extends Thread{

		JLabel avatar;
		JLabel monster;
		final int MONSTER_MOVE = 5;
		Point pos = new Point(250,50);
	
		public MonsterThread(JLabel avatar, JLabel monster) {
			this.avatar = avatar;
			this.monster = monster;
			pos = new Point(monster.getX(), monster.getY()); 
		}
		
		@Override
		public void run() {
			// TODO Auto-generated method stub
			while(true) {
				if(avatar.getX() < monster.getX()) {
					pos.x -= MONSTER_MOVE;
				}else {
					pos.x += MONSTER_MOVE;
				}
					
				if(avatar.getY() < monster.getY()) {
					pos.y -= MONSTER_MOVE;
				}else {
					pos.y += MONSTER_MOVE;
				}
			
				if(Math.abs(avatar.getX() - monster.getX()) < avatar.getWidth() && Math.abs(avatar.getY() - monster.getY()) < avatar.getHeight() ) {
					JOptionPane.showMessageDialog(null, "몬스터에게 잡혔습니다. 게임을 종료합니다. ");
					return;
				}
				
				monster.setLocation(pos);
				monster.getParent().repaint();
				try {
					Thread.sleep(500);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}
	}
}

