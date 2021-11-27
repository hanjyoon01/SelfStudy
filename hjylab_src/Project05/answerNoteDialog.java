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
public class answerNoteDialog extends JDialog {

	Container pane = this.getContentPane();
	boolean modal = false;
	
	//기본 테이블 구성요소
	String[] colum = {"문제","정답","고른 답"};	//테이블 제목
	DefaultTableModel model = new DefaultTableModel(colum,0);
	JTable table = new JTable(model);
	JPanel panel1 = new JPanel();
	
	MyFrame parent = null;
	
	//기본 다이얼로그 구현
	public answerNoteDialog(MyFrame parent, String title, boolean modal) {
		super(parent, title, modal);
		this.parent = parent;
		this.setSize(800,400);
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
	
		//오답노트 배열에 있는 단어수 만큼 테이블에 추가
		for(int i=0;i<QuizDialog.wrongCount;i++) {
			String[] data = {MyFrame.wrongVoclist[i][0]+"의 뜻은 무엇일까요?",MyFrame.wrongVoclist[i][1],MyFrame.wrongVoclist[i][2]};
			model.addRow(data);
		}
	}
	
	public void initListener() {

		this.addWindowListener(new WindowAdapter() {

			@Override
			public void windowClosing(WindowEvent e) {
				// TODO Auto-generated method stub
				super.windowClosing(e);
				if(!modal) {
					parent.dlg5 = null;
				}
				dispose();
			}
		});
	}
	
}
