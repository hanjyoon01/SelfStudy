package week11.lab.swing1;

import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class MyFrame3 extends JFrame {

	JButton btn;
	Container frame = this.getContentPane();
	MyDialog dlg = null;
	
	public MyFrame3() {
		this("202011390 한재윤");
	}

	public MyFrame3(String title) {
		// TODO Auto-generated constructor stub
		super(title);
		this.setSize(500,500);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	public void init() {
		btn = new JButton("Show Modal Dialog");
		btn.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(dlg == null) {
					dlg = new MyDialog(MyFrame3.this, "TestDialog", false);
				}else {
					dlg.requestFocus();
				}
				
//				String text = dlg.getInput();
//				if(text==null) return;
//				JButton btn = (JButton)e.getSource();
//				btn.setText(text);
			}
			
		});
		frame.add(btn);
	}
}
