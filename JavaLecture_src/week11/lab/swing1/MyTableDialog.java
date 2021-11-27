package week11.lab.swing1;

import java.awt.Container;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;
import javax.swing.JTextField;

public class MyTableDialog extends JDialog {
	
	MyFrame4 parent = null;
	boolean modal = false;
	boolean check = false;
	Container pane = this.getContentPane();
	JTextField uID;
	JPasswordField uPasswd1;
	JPasswordField uPasswd2;
	JTextField uName;
	JTextField uPhone;
	JButton btn1, btn2;
	
	public MyTableDialog(MyFrame4 parent, String title, boolean modal) {
		super(parent, title, modal);
		this.parent = parent;
		this.modal = modal;
		this.setSize(500,500);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		init();
		parent.setVisible(false);
		this.setVisible(true);
	}
	
	public void init() {
		
		pane.setLayout(new GridLayout(8,2));
		
		pane.add(new JLabel("아이디"));
		uID = new JTextField(15);
		pane.add(uID);
		
		pane.add(new JLabel("비밀번호"));
		uPasswd1 = new JPasswordField(15);
		uPasswd1.setEchoChar('*');
		pane.add(uPasswd1);
		
		pane.add(new JLabel("비밀번호 확인"));
		uPasswd2 = new JPasswordField(15);
		uPasswd2.setEchoChar('*');
		pane.add(uPasswd2);
		
		pane.add(new JLabel("이름"));
		uName = new JTextField(15);
		pane.add(uName);
		
		pane.add(new JLabel("전화번호"));
		uPhone = new JTextField(15);
		pane.add(uPhone);
		
		btn1 = new JButton("입력");
		btn2 = new JButton("취소");
		pane.add(btn1);
		pane.add(btn2);
		
		initListener();
	}
	
	public void initListener() {
		
		uPasswd2.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				String passwd1 = new String(uPasswd1.getPassword());
				String passwd2 = new String(uPasswd2.getPassword());
				if(passwd1.equals(passwd2)) {
					JOptionPane.showMessageDialog(null, "비밀번호가 일치합니다.");
					check = true;
				}else {
					JOptionPane.showMessageDialog(null, "비밀번호가 일치하지 않습니다.");
				}
			
			}
			
		});
		
		btn1.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(!modal) {
					String sid = uID.getText();
					if(sid.length()==0) {
						JOptionPane.showMessageDialog(null, "아이디는 필수입력 항목입니다.");
						uID.requestFocus();
						return;
					}
					if(!check) {
						JOptionPane.showMessageDialog(null, "비밀번호 확인이 필요합니다.");
						uPasswd2.requestFocus();
						return;
					}
					String[] data = {sid, new String (uPasswd1.getPassword()), uName.getText(), uPhone.getText()};
					parent.model.addRow(data);
					parent.dlg = null;
				}
				parent.setVisible(true);
				dispose();
			}
			
		});
		
		btn2.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(!modal) {
					parent.dlg = null;
				}
				parent.setVisible(true);
				dispose();
			}
			
		});
		
		this.addWindowListener(new WindowAdapter() {

			@Override
			public void windowClosing(WindowEvent e) {
				// TODO Auto-generated method stub
				super.windowClosing(e);
				if(!modal) {
					parent.dlg = null;
				}
				parent.setVisible(true);
				dispose();
			}
		});
	}
}
