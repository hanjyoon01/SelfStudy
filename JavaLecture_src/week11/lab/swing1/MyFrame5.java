package week11.lab.swing1;

import java.awt.Color;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JColorChooser;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.filechooser.FileNameExtensionFilter;

public class MyFrame5 extends JFrame implements ActionListener {
	
	Container frame = this.getContentPane();
	JLabel label = new JLabel();
	
	public MyFrame5() {
		this("202011390 한재윤");
	}

	public MyFrame5(String title) {
		// TODO Auto-generated constructor stub
		super(title);
		this.setSize(500,500);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	public void init() {
		label.setOpaque(true);
		frame.add(label);
		
		initMenu();
	}
	
	public void initMenu() {
		JMenuBar mb = new JMenuBar();
		JMenu  menu = new JMenu("그리기");
		JMenuItem item1 = new JMenuItem("색상");
		JMenuItem item2 = new JMenuItem("그림 불러오기");
		menu.add(item1);
		menu.add(item2);
		mb.add(menu);
		this.setJMenuBar(mb);
		
		item1.addActionListener(this);
		item2.addActionListener(this);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getActionCommand()=="색상") {
			Color color = JColorChooser.showDialog(this, "Color", Color.BLACK);
			if(color!=null)
				label.setBackground(color);
					
		}else if(e.getActionCommand()=="그림 불러오기") {
			JFileChooser dlg = new JFileChooser();
			FileNameExtensionFilter filter = new FileNameExtensionFilter("jpg Images","jpg","jpeg");
			dlg.setFileFilter(filter);
			filter = new FileNameExtensionFilter("gif Images","gif");
			dlg.setFileFilter(filter);
			int ret = dlg.showOpenDialog(this);
			if(ret==JFileChooser.APPROVE_OPTION) {
				String path = dlg.getSelectedFile().getAbsolutePath();
				label.setIcon(new ImageIcon(path));
				pack();
			}
		
		}
	}
	
	
}
