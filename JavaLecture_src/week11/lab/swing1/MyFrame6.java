package week11.lab.swing1;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class MyFrame6 extends JFrame implements ActionListener {
	
	Container frame = this.getContentPane();
	String[] itemName = {"삼성전자","LG전자","네이버","카카오"};
	JTextField[] tf = new JTextField[4];
	JPanel panel = new JPanel();
	
	int[] data = {0,0,0,0};
	int[] arcAngle = new int[4];
	Color[] color = {Color.RED,Color.CYAN,Color.GREEN,Color.ORANGE};
	
	ChartPanel chart = new ChartPanel();
	
	public MyFrame6() {
		this("202011390 한재윤");
	}

	public MyFrame6(String title) {
		// TODO Auto-generated constructor stub
		super(title);
		this.setSize(500,500);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	public void init() {

		initPanel();
	}
	
	public void initPanel() {
		
		panel.setBackground(Color.YELLOW);
		for(int i=0;i<tf.length;i++) {
			tf[i] = new JTextField("0",5);
			tf[i].addActionListener(this);
			panel.add(new JLabel(itemName[i]));
			panel.add(tf[i]);
		}
		frame.add(panel, BorderLayout.NORTH);
		frame.add(chart, BorderLayout.CENTER);
	}

	public void drawChart() {
		int sum = 0;
		for(int i=0;i<data.length;i++) {
			data[i] = Integer.parseInt(tf[i].getText());
			sum+=data[i];
		}
		
		if(sum==0) return;
		
		for(int i=0;i<data.length;i++) 
			arcAngle[i] = (int)Math.round((double)data[i]/(double)sum*360);

		chart.repaint();
	}
	
	
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		drawChart();
	}

	class ChartPanel extends JPanel{

		@Override
		protected void paintComponent(Graphics g) {
			// TODO Auto-generated method stub
			
			Color[] color = {Color.RED,Color.CYAN,Color.GREEN,Color.ORANGE};
			
			super.paintComponent(g);
			for(int i=0;i<data.length;i++) {
				g.setColor(color[i]);
				g.drawString(itemName[i]+" "+Math.round(arcAngle[i]*100./360.)+"%", 50+i*100, 20);
			}
			
			for(int i=0;i<data.length;i++) {
				for(int j=i+1;j<data.length;j++) {
					
					if(arcAngle[i]<arcAngle[j]) {
						int tmp = arcAngle[i];
						arcAngle[i] = arcAngle[j];
						arcAngle[j] = tmp;
						
						Color tmp1 = color[i];
						color[i] = color[j];
						color[j] = tmp1;
					}
				}
			}
			
			int startAngle = 0;
					
			for(int i=0;i<data.length;i++) {
				g.setColor(color[i]);
				g.fillArc(150, 50, 200, 200, startAngle, arcAngle[i]);
				startAngle += arcAngle[i];
			}
		}
	}
}
