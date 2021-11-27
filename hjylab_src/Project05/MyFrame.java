package Project05;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

@SuppressWarnings("serial")
public class MyFrame extends JFrame implements ActionListener {

	//버튼에 추가할 Label
	String[] menu = {"단어장 생성","단어 검색 1","단어 검색 2","객관식 퀴즈","빈출 단어","오답 노트"};

	//단어장 메인화면 
	Font font = new Font("휴먼편지체", Font.BOLD, 30);
	JLabel Label = new JLabel("한재윤의 단어장");
	
	//메인화면과 버튼을 추가할 패널 2개
	JPanel panel1, panel2;

	//버튼을 누를 때 나올 각 다이얼로그
	SearchDialog1 dlg1 = null;
	SearchDialog2 dlg2 = null;
	QuizDialog dlg3 = null;
	FrequencyDialog dlg4 = null;
	answerNoteDialog dlg5 = null;
	
	static Word[] voc = new Word[100];	//생성할 단어장
	static int number = 0;	//단어 갯수 count용
	static List<Word> freqlist = new ArrayList<>();	//빈출 단어 메뉴에서 정렬 위해 사용
	static String[][] wrongVoclist = null;	//오답 노트 메뉴에서 사용

	
	// 기본 Frame 설정
	public MyFrame() {
		this("202011390 한재윤");
	}

	public MyFrame(String title) {
		// TODO Auto-generated constructor stub
		super(title);
		this.setSize(500,300);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	public void init() {
		
		this.setLayout(new BorderLayout());
		
		panel1 = new JPanel();
		panel2 = new JPanel(new FlowLayout(FlowLayout.CENTER, 40, 40));
		
		
		Label.setFont(font);
		panel1.add(Label);
		
		//메뉴 버튼 만들기
		for(int i=0;i<menu.length;i++) {
			JButton b = new JButton(menu[i]);
			b.setPreferredSize(new Dimension(100, 40));
			b.addActionListener(this);
			panel2.add(b);
		}	
		
		this.add(panel1, BorderLayout.NORTH);
		this.add(panel2, BorderLayout.CENTER);
	}
	
	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		
		//단어장 생성
		if(e.getActionCommand()=="단어장 생성") {
			
			JFileChooser dlg = new JFileChooser();
			int ret = dlg.showOpenDialog(this);
			if(ret==JFileChooser.APPROVE_OPTION) {
				
				String path = dlg.getSelectedFile().getAbsolutePath();
				
				//텍스트 파일을 읽고 과제4 VocManager의 addVoc, makeVoc을 통해 단어장 생성,  
				try {
					makeVoc(path, voc);
					wrongVoclist = new String[number][3];	//오답노트 2차원 배열도 생성
				} catch (FileNotFoundException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				JOptionPane.showMessageDialog(null, "한재윤님의 단어장이 생성되었습니다.");
			}
			
		//단어 검색 1	
		}else if(e.getActionCommand()=="단어 검색 1") {
			
			if(number==0) {
				JOptionPane.showMessageDialog(null, "단어장을 생성해주세요.");
			}else {
				if(dlg1==null) {
					dlg1 = new SearchDialog1(MyFrame.this, "단어 검색 1", false);
				}else {
					dlg1.requestFocus();
				}	
			}
			
		//단어 검색 2	
		}else if(e.getActionCommand()=="단어 검색 2") {
			
			if(number==0) {
				JOptionPane.showMessageDialog(null, "단어장을 생성해주세요.");
			}else {
				if(dlg2==null) {
					dlg2 = new SearchDialog2(MyFrame.this, "단어 검색 2", false);
				}else {
					dlg2.requestFocus();
				}	
			}
			
		//객관식 퀴즈	
		}else if(e.getActionCommand()=="객관식 퀴즈") {
			if(number==0) {
				JOptionPane.showMessageDialog(null, "단어장을 생성해주세요.");
			}else {
				if(dlg3==null) {
					dlg3 = new QuizDialog(MyFrame.this, "객관식 퀴즈", false);
				}else {
					dlg3.requestFocus();
				}	
			}
			
		//빈출 단어
		}else if(e.getActionCommand()=="빈출 단어") {
			if(number==0) {
				JOptionPane.showMessageDialog(null, "단어장을 생성해주세요.");
			}else {
				if(dlg4==null) {
					dlg4 = new FrequencyDialog(MyFrame.this, "빈출 단어", false);
				}else {
					dlg4.requestFocus();
				}	
			}
			
		//오답 노트
		}else if(e.getActionCommand()=="오답 노트") {
			if(number==0) {
				JOptionPane.showMessageDialog(null, "단어장을 생성해주세요.");
			}else {
				if(dlg5==null) {
					dlg5 = new answerNoteDialog(MyFrame.this, "오답 노트", false);
				}else {
					dlg5.requestFocus();
				}	
			}
		}
	}
	
	//단어 추가 메소드
	void addword(Word word, Word[] voc) {
		if(number < voc.length) {
			voc[number++] = word;
			freqlist.add(word);	
		}
		else {
			JOptionPane.showMessageDialog(null, "단어장에 더이상의 단어를 등록할 수 없습니다.");
		}
	}
	
	//단어장 생성 메소드
	void makeVoc(String filename, Word[] voc) throws FileNotFoundException {
		Scanner scan = new Scanner(new File(filename));
		while(scan.hasNextLine()) {
			String str = scan.nextLine();
			String[] temp = str.split("\t");
			this.addword(new Word(temp[0].trim(), temp[1].trim(), 0), voc);
		}
	}
	
	//빈출단어 정렬 comparator
	static class FreqComparator implements Comparator<Word>{
		
		@Override
		public int compare(Word w1, Word w2) {
			// TODO Auto-generated method stub
			return (w1.getFreq() - w2.getFreq())*(-1);
		}
	}
	
	//빈출단어목록 정렬 메소드
	public static void FrequentVoc() {
		Collections.sort(MyFrame.freqlist, new FreqComparator());
	}
	
}
		
