package week11.lab.swing1;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JCheckBoxMenuItem;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JToolBar;

public class MyFrame2 extends JFrame implements ActionListener{
	
	Container frame;
	String[] color = {"Red","Green","Blue"};
	JLabel char1 =  new JLabel(new ImageIcon("img/char1.png"));
	
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
		frame = this.getContentPane();
		frame.add(char1);
		char1.setVisible(false);
		initMenu();
		initToolBar();
	}
	
	public void initToolBar() {
		JToolBar toolBar = new JToolBar("Color");
		JButton red = new JButton("Red1");
		red.addActionListener(this);
		red.setActionCommand("Red");
		JButton green = new JButton("Green1");
		green.addActionListener(this);
		green.setActionCommand("Green");
		JButton blue = new JButton("Blue1");
		blue.addActionListener(this);
		blue.setActionCommand("Blue");
		toolBar.add(red);
		toolBar.addSeparator();
		toolBar.add(green);
		toolBar.add(blue);
		//toolBar.setFloatable(false);
		frame.add(toolBar, BorderLayout.PAGE_START);
	}
	
	public void initMenu() {
		JMenuBar mb = new JMenuBar();
		JMenu colorMenu = new JMenu("색상");
		for(String str:color) {
			JMenuItem menu = new JMenuItem(str);
			menu.addActionListener(this);
			colorMenu.add(menu);
		}
		JMenu colorMenu2 = new JMenu("기타색상");
		JMenuItem menu = new JMenuItem("Yellow");
		menu.addActionListener(this);
		colorMenu2.add(menu);
		colorMenu.add(colorMenu2);
		
		JMenu iconMenu = new JMenu("아이콘");
		JCheckBoxMenuItem checkMenu = new JCheckBoxMenuItem("홍길동",false);
		checkMenu.addItemListener(new ItemListener() {

			@Override
			public void itemStateChanged(ItemEvent e) {
				// TODO Auto-generated method stub
				if(e.getStateChange()==ItemEvent.SELECTED) {
					char1.setVisible(true);
				}else {
					char1.setVisible(false);
				}
				
			}
			
		});
		
		iconMenu.add(checkMenu);
		
		mb.add(colorMenu);
		mb.add(iconMenu);
		this.setJMenuBar(mb);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		switch(e.getActionCommand()) {
		case "Red": frame.setBackground(Color.RED);break;
		case "Green": frame.setBackground(Color.GREEN);break;
		case "Blue": frame.setBackground(Color.BLUE);break;
		case "Yellow": frame.setBackground(Color.YELLOW);break;
		}
	}
	
	
	
	
	
}
