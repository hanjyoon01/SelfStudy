package week10.hjy.konkuk;

import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

import javax.swing.DefaultComboBoxModel;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

public class MyFrame extends JFrame implements ActionListener, ListSelectionListener, ItemListener {
	
	String[] data = {"Bold","Italic"};
	JCheckBox[] check = new JCheckBox[2];
	JTextField text;
	String[] f = {"바탕체","돋움체","굴림체","궁서체"};
	Integer[] fontsize = {10,12,14,16,18,20,22,24,26};
	DefaultComboBoxModel<String> model1;
	DefaultComboBoxModel<Integer> model2;
	JComboBox<String> combo1;
	JComboBox<Integer> combo2;
	JPanel north = new JPanel();
	JPanel center = new JPanel();
	JLabel label = new JLabel("202011390 한재윤");
	
	public MyFrame() {
		this("202011390 한재윤");
	}
	
	public MyFrame(String title) {
		super(title);
		this.setSize(500,500);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	public void init() {
		
		this.setLayout(new BorderLayout(10,180));
		
		text = new JTextField(20);
		model1 = new DefaultComboBoxModel<String>(f);
		model2 = new DefaultComboBoxModel<Integer>(fontsize);
		combo1 = new JComboBox<String>(model1);
		combo2 = new JComboBox<Integer>(model2);
		
		combo1.setSelectedIndex(0);
		combo2.setSelectedIndex(1);
		
		north.add(combo1);
		north.add(combo2);
		
		for(int i=0; i<data.length;i++) {
			check[i] = new JCheckBox(data[i]);
			check[i].addItemListener(this);
			north.add(check[i]);
		}
	
		int fs = fontsize[combo2.getSelectedIndex()];
		String font = f[combo1.getSelectedIndex()];
		
		label.setFont(new Font(font,Font.PLAIN,fs));
		
		north.add(text);
		center.add(label);
		this.add(north, BorderLayout.NORTH);
		this.add(center, BorderLayout.CENTER);
		
		initListener();
	}

	public void initListener() {
		text.addActionListener(this);
		combo1.addActionListener(this);
		combo2.addActionListener(this);
	}
	

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		
		Font lf = label.getFont();
		int lfs = lf.getStyle();
		
		if(e.getSource()==text) {
			String str1 = text.getText();
			label.setText(str1);
			
		}else if(e.getSource()==combo1) {
			@SuppressWarnings("unchecked")
			JComboBox<String> cb= (JComboBox<String>)e.getSource();
			int fs = fontsize[combo2.getSelectedIndex()];
			label.setFont(new Font((String)cb.getSelectedItem(),lfs,fs));
			
		}else if(e.getSource()==combo2) {
			@SuppressWarnings("unchecked")
			JComboBox<Integer> cb= (JComboBox<Integer>)e.getSource();
			String font = f[combo1.getSelectedIndex()];
			label.setFont(new Font(font,lfs,(int)cb.getSelectedItem()));
			
		}
	}

	@Override
	public void itemStateChanged(ItemEvent e) {
		// TODO Auto-generated method stub
		if(e.getSource()==check[0]) {
			int fs = fontsize[combo2.getSelectedIndex()];
			String font = f[combo1.getSelectedIndex()];
			
			if(e.getStateChange()==ItemEvent.SELECTED) {
				if(check[1].isSelected()) {
					label.setFont(new Font(font,Font.BOLD|Font.ITALIC,fs));
				}else {
					label.setFont(new Font(font,Font.BOLD,fs));
				}
			}else {
				if(check[1].isSelected()) {
					label.setFont(new Font(font,Font.ITALIC,fs));
				}else {
					label.setFont(new Font(font,Font.PLAIN,fs));
				}
			}
		
		}else if(e.getSource()==check[1]) {
			int fs = fontsize[combo2.getSelectedIndex()];
			String font = f[combo1.getSelectedIndex()];
			
			if(e.getStateChange()==ItemEvent.SELECTED) {
				if(check[0].isSelected()) {
					label.setFont(new Font(font,Font.BOLD|Font.ITALIC,fs));
				}else {
					label.setFont(new Font(font,Font.ITALIC,fs));
				}
			}else {
				if(check[0].isSelected()) {
					label.setFont(new Font(font,Font.BOLD,fs));
				}else {
					label.setFont(new Font(font,Font.PLAIN,fs));
				}
			}
		}
	}

	@Override
	public void valueChanged(ListSelectionEvent e) {
		// TODO Auto-generated method stub
		
	}
}
