package Project05;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;
import javax.swing.table.DefaultTableModel;

//단어 검색1 다이얼로그
@SuppressWarnings("serial")
public class SearchDialog1 extends JDialog implements ActionListener{
	
	JTextField tf = new JTextField(20);	//단어 입력창
	JButton sButton = new JButton("검색");	//검색 버튼
	JPanel panel1 = new JPanel();	//구현 패널
	Container pane = this.getContentPane();
	boolean modal = false;
	
	//테이블 생성
	String[] colum = {"단어","뜻"};
	DefaultTableModel model = new DefaultTableModel(colum,0);
	JTable table = new JTable(model);
	
	MyFrame parent = null;

	//기본 다이얼로그 구현
	public SearchDialog1(MyFrame parent, String title, boolean modal) {
		super(parent, title, modal);
		this.parent = parent;
		this.setSize(500,300);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	public void init() {
		panel1.add(tf);
		panel1.add(sButton);
		pane.setLayout(new BorderLayout());
		pane.add(panel1, BorderLayout.NORTH);
		pane.add(new JScrollPane(table));
		initListener();
	}
	
	public void initListener() {
		
		sButton.addActionListener(this);
		
		this.addWindowListener(new WindowAdapter() {

			@Override
			public void windowClosing(WindowEvent e) {
				// TODO Auto-generated method stub
				super.windowClosing(e);
				if(!modal) {
					parent.dlg1 = null;
				}
				dispose();
			}
		});
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getActionCommand()=="검색") {
				
			//검색할 때마다 행을 제거
			if(model.getRowCount() >= 1) 
				model.removeRow(0);
				
			//검색창에 입력한 단어 추출
			String sWord = tf.getText();
			
			sWord = sWord.trim();
			
			//알맞은 단어를테이블에 출력
			for(int i=0;i<MyFrame.number;i++) {
				if(MyFrame.voc[i].getEng().equals(sWord)) {
					String[] data = {MyFrame.voc[i].getEng(),MyFrame.voc[i].getKor()};
					model.addRow(data);
				}
			}
			//검색 단어가 존재하지 않는 경우 알림창을 띄움
			if(model.getRowCount() < 1)
				JOptionPane.showMessageDialog(null, "찾는 단어가 없습니다.");
		}		
		parent.dlg1 = null;
	}
}
