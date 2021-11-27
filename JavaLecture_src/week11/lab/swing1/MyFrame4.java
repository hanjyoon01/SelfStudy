package week11.lab.swing1;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

public class MyFrame4 extends JFrame {

	Container frame = this.getContentPane();
	
	JPanel panel1 = new JPanel();
	JButton btn1 = new JButton("정보입력");
	
	String[] colum = {"아이디","비밀번호","이름","전화번호"};
	DefaultTableModel model = new DefaultTableModel(colum,0);
	JTable table = new JTable(model);
	
	MyTableDialog dlg = null;
	
	public MyFrame4() {
		this("202011390 한재윤");
	}

	public MyFrame4(String title) {
		// TODO Auto-generated constructor stub
		super(title);
		this.setSize(500,500);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	public void init() {
		panel1.add(btn1);
		frame.add(panel1, BorderLayout.NORTH);
		frame.add(new JScrollPane(table));
		initListener();
	}
		
	public void initListener() {
		btn1.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				if(dlg==null) {
					dlg = new MyTableDialog(MyFrame4.this, "정보입력", false);
					//MyFrame4.this.setVisible(false);
				}else {
					dlg.requestFocus();
				}
			}
			
		});
	}
}
