package Project05;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

@SuppressWarnings("serial")
public class FrequencyDialog extends JDialog {

	Container pane = this.getContentPane();
	boolean modal = false;
	
	//기본 테이블 구성요소
	String[] colum = {"단어","뜻","출제 횟수"};	//테이블 제목
	DefaultTableModel model = new DefaultTableModel(colum,0);
	JTable table = new JTable(model);
	JPanel panel1 = new JPanel();
	
	MyFrame parent = null;
	
	//기본 다이얼로그 구현
	public FrequencyDialog(MyFrame parent, String title, boolean modal) {
		super(parent, title, modal);
		this.parent = parent;
		this.setSize(500,300);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		init();
		this.setVisible(true);
		initListener();
	}
	
	public void init() {
		
		pane.setLayout(new BorderLayout());
		pane.add(panel1, BorderLayout.NORTH);
		pane.add(new JScrollPane(table));
		
		MyFrame.FrequentVoc();	//MyFrame에 구현한 빈출단어 출력 메소드 호출
		
		int n=0;
		
		//빈출된 단어를 순서대로 출력 (내림차순 정렬)
		while(MyFrame.freqlist.get(n).Freq>0) {
			String s = Integer.toString(MyFrame.freqlist.get(n).getFreq());
			String[] data = {MyFrame.freqlist.get(n).getEng(),MyFrame.freqlist.get(n).getKor(),s};
			model.addRow(data);
			n++;
		}
	}
	
	public void initListener() {

		this.addWindowListener(new WindowAdapter() {

			@Override
			public void windowClosing(WindowEvent e) {
				// TODO Auto-generated method stub
				super.windowClosing(e);
				if(!modal) {
					parent.dlg4 = null;
				}
				dispose();
			}
		});
	}
}
