package week10.lab.swing1;

import java.awt.*;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import javax.swing.*;

public class MyFrame3 extends JFrame implements ItemListener{
	String[] data = {"사과","포도","배"};
	JRadioButton[] R = new JRadioButton[3];
	JLabel[] label = new JLabel[3];
	JPanel north = new JPanel();
	JPanel center = new JPanel();
	
	public MyFrame3() {
		this("202011390 한재윤");
	}
	
	public MyFrame3(String title) {
		super(title);
		this.setSize(500,500);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	public void init() {
		
		ButtonGroup g = new ButtonGroup();
		
		for(int i=0; i<data.length;i++) {
			R[i] = new JRadioButton(data[i]);
			R[i].addItemListener(this);
			g.add(R[i]);
			north.add(R[i]);
			label[i] = new JLabel(data[i]);
		}
		this.add(north, BorderLayout.NORTH);
		this.add(center, BorderLayout.CENTER);
	}

	@Override
	public void itemStateChanged(ItemEvent e) {
		// TODO Auto-generated method stub
		int i = -1;
		if(e.getSource()==R[0]) {
			i = 0;
		}else if(e.getSource()==R[1]) {
			i = 1;
		}else if(e.getSource()==R[2]) {
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