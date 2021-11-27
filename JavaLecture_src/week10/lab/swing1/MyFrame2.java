package week10.lab.swing1;

import java.awt.*;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import javax.swing.*;

public class MyFrame2 extends JFrame implements ItemListener{
	String[] data = {"사과","포도","배"};
	JCheckBox[] check = new JCheckBox[3];
	JLabel[] label = new JLabel[3];
	JPanel north = new JPanel();
	JPanel center = new JPanel();
	
	public MyFrame2() {
		this("202011390 한재윤");
	}
	
	public MyFrame2(String title) {
		super(title);
		this.setSize(500,500);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	public void init() {
		for(int i=0; i<data.length;i++) {
			check[i] = new JCheckBox(data[i]);
			check[i].addItemListener(this);
			north.add(check[i]);
			label[i] = new JLabel(data[i]);
//			label[i].setVisible(false);
//			center.add(label[i]);
		}
		
		this.add(north, BorderLayout.NORTH);
		this.add(center, BorderLayout.CENTER);
	}

	@Override
	public void itemStateChanged(ItemEvent e) {
		// TODO Auto-generated method stub
		int i = -1;
		if(e.getSource()==check[0]) {
			i = 0;
		}else if(e.getSource()==check[1]) {
			i = 1;
		}else if(e.getSource()==check[2]) {
			i = 2;
		}
		if(i>=0) {
			if(e.getStateChange()==ItemEvent.SELECTED) {
			//	label[i].setVisible(true);
				center.add(label[i]);
			}else {
			//	label[i].setVisible(false);
				center.remove(label[i]);
			}
			center.revalidate();
			center.repaint();
		}
	}
}
