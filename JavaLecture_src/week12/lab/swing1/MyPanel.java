package week12.lab.swing1;

import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.ImageIcon;
import javax.swing.JPanel;

@SuppressWarnings("serial")
public class MyPanel extends JPanel {
	
	ImageIcon imgicon = new ImageIcon("img/Back.jpg");
	Image img = imgicon.getImage();
	int xpos = 100, ypos = 100;
	
	MyPanel(){
		super();
		this.addMouseMotionListener(new MouseAdapter() {

			@Override
			public void mouseDragged(MouseEvent e) {
				// TODO Auto-generated method stub
				super.mouseDragged(e);
				xpos = e.getX();
				ypos = e.getY();
				
				repaint();
			}
		});
	}
	
	
	@Override
	protected void paintComponent(Graphics g) {
		// TODO Auto-generated method stub
		super.paintComponent(g);
		
//		g.setClip(xpos, ypos, 100, 100);
		g.drawImage(img, 0, 0, this.getWidth()-25, this.getHeight()-25, 0, 0, img.getWidth(null), img.getHeight(null), this);
		
	}

}
