package week11.lab.swing1;

import java.awt.Container;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JTextField;

public class MyDialog extends JDialog {

	JTextField tf = new JTextField("greenjoa");
	JButton okButton = new JButton("OK");
	Container pane = this.getContentPane();
	MyFrame3 parent = null;
	
	public MyDialog(MyFrame3 parent, String title, boolean modal) {
		super(parent, title, modal);
		this.parent = parent;
		this.setSize(500,500);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	public void init() {
		pane.setLayout(new FlowLayout());
		pane.add(tf);
		pane.add(tf);
		pane.add(okButton);
		okButton.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				parent.dlg = null;
				String str = getInput();
				if(str!=null)
					parent.btn.setText(str);
				dispose();
			}
			
		});
		this.addWindowListener(new WindowAdapter() {

			@Override
			public void windowClosing(WindowEvent e) {
				// TODO Auto-generated method stub
				super.windowClosing(e);
				tf.setText("");
				parent.dlg = null;
				dispose();
			}
			
		});
	}
	
	String getInput() {
		if(tf.getText().length()==0)
			return null;
		else
			return tf.getText();
	}
	
}
