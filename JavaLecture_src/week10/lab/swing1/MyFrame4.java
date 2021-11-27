package week10.lab.swing1;

import javax.swing.JFrame;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class MyFrame4 extends JFrame implements ActionListener, ListSelectionListener {
	JTextField text1;
	JPasswordField text2;
	JList<String> list;
	DefaultListModel<String> model;
	DefaultComboBoxModel<String> model2;
	String[] arr = {"사과","배","포도"};
	JComboBox<String> combo;
	
	JPanel panel;
	JSlider fontsize;
	JLabel label = new JLabel("greenjoa");
	
	
	public MyFrame4() {
		this("202011390 한재윤");
	}
	
	public MyFrame4(String title) {
		super(title);
		this.setSize(500,500);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	public void init() {
		this.setLayout(new FlowLayout());
		text1 = new JTextField(15);
		text1.setFont(new Font("굴림체", Font.BOLD, 15));
		text2 = new JPasswordField(15);
		text2.setEchoChar('*');
		this.add(text1);
		this.add(text2);
		model = new DefaultListModel<String>();
		list = new JList<String>(model);
		this.add(new JScrollPane(list));
		model2 = new DefaultComboBoxModel<String>(arr);
		combo = new JComboBox<String>(model2);
		this.add(combo);
		
		//slider
		panel = new JPanel(new GridLayout(2,1));
		panel.setPreferredSize(new Dimension(300,200));
		fontsize = new JSlider(JSlider.HORIZONTAL,1,50,10);
		fontsize.setToolTipText("폰트 크기 설정");
		fontsize.setPaintLabels(true);
		fontsize.setPaintTicks(true);
		fontsize.setMajorTickSpacing(10);
		fontsize.setMinorTickSpacing(2);
		
		panel.add(label);
		panel.add(fontsize);
		this.add(panel);
		
		initListener();
	}
	
	public void initListener() {
		text1.addActionListener(this);
		text2.addActionListener(this);
		list.addListSelectionListener(this);
		combo.addActionListener(this);
		fontsize.addChangeListener(new ChangeListener() {

			@Override
			public void stateChanged(ChangeEvent e) {
				// TODO Auto-generated method stub
				Font font = new Font("굴림체", Font.BOLD, fontsize.getValue());
				label.setFont(font);
			}
			
		});
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource()==text1) {
			String str1 = text1.getText();
			text1.setText("");
			model.addElement(str1);
			model2.addElement(str1);
//			Font f1 = text1.getFont();
//			//text1.setText("");
//			String str2 = new String (text2.getPassword());
//			Font f2 = text2.getFont();
//			text1.setText(str2);
//			text1.setFont(f2);
//			text2.setText(str1);
//			text2.setFont(f1);;
//			text2.requestFocus();
		}else if(e.getSource()==text2) {
			String str2 = new String (text2.getPassword());
			if(str2.equals("greenjoa")) {
				JOptionPane.showMessageDialog(this, "일치합니다.");
			}else {
				JOptionPane.showMessageDialog(this, "일치하지 않습니다.");
			}
		}else if(e.getSource()==combo) {
			@SuppressWarnings("unchecked")
			JComboBox<String> cb= (JComboBox<String>)e.getSource();
			JOptionPane.showMessageDialog(this, cb.getSelectedItem());
		}
	}

	@Override
	public void valueChanged(ListSelectionEvent e) {
		// TODO Auto-generated method stub
		if(!e.getValueIsAdjusting())
			JOptionPane.showMessageDialog(this, list.getSelectedValue());
	}
	
}
