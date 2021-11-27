package week10.lab.swing1;

import java.awt.event.WindowEvent;

import javax.swing.JOptionPane;

public class MyWindowAdapter extends java.awt.event.WindowAdapter {

	MyFrame frame;
	public MyWindowAdapter(MyFrame f) {
		frame = f;
	}
	
	@Override
	public void windowOpened(WindowEvent e) {
		// TODO Auto-generated method stub
		super.windowOpened(e);
		String name = JOptionPane.showInputDialog("닉네임을 입력하세요");
		frame.setTitle(name);
	}
	
}
