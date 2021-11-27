package week11.lab.swing1;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.SwingConstants;

public class MyFrame extends JFrame {
	
	Container contentPane;
	JLabel label = new JLabel("Hello");
	MyFrame() {
		setTitle("Menu 만들기 예제");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		contentPane = getContentPane();
		label.setHorizontalAlignment(SwingConstants.CENTER);
		contentPane.add(label, BorderLayout.CENTER);
		createMenu();
		setSize(250,200);
		setVisible(true);
	}
	
	void createMenu() {
		JMenuBar mb = new JMenuBar();
		JMenuItem [] menuItem = new JMenuItem [4];
		String[] itemTitle = {"Color", "Font", "Top", "Bottom"};
		JMenu textMenu = new JMenu("Text");
		for(int i=0; i<menuItem.length; i++) {
			menuItem[i] = new JMenuItem(itemTitle[i]);
			menuItem[i].addActionListener(new MenuActionListener());
			textMenu.add(menuItem[i]);
		}
		mb.add(textMenu);
		this.setJMenuBar(mb);
	}
	
	class MenuActionListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
		String cmd = e.getActionCommand();
		if(cmd.equals("Color"))
			label.setForeground(Color.BLUE);
		else if(cmd.equals("Font"))
			label.setFont(new Font("Ravie", Font.ITALIC, 30));
		else if(cmd.equals("Top"))
			label.setVerticalAlignment(SwingConstants.TOP);
		else
			label.setVerticalAlignment(SwingConstants.BOTTOM);
		}
	}
}
