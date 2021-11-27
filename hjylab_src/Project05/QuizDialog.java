package Project05;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.Random;

import javax.swing.ButtonGroup;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JRadioButton;

@SuppressWarnings("serial")
public class QuizDialog extends JDialog implements ActionListener, ItemListener{

	
	JRadioButton[] R = new JRadioButton[4];	//사지선다의 선지 표현
	JButton startButton = new JButton("시작");	//퀴즈 시작 버튼
	JButton choiceButton = new JButton("확인");	//답 입력 버튼
	JLabel Q1,Q2;	//객관식 문제 표시
	JLabel Label = new JLabel("객관식 퀴즈를 시작합니다.");
	Font font = new Font("굴림체", Font.BOLD, 30);
	JPanel panel1 = new JPanel(new FlowLayout(FlowLayout.CENTER,50,50));	//시작 화면 출력 패널
	JPanel mainPanel = new JPanel(new BorderLayout());	//문제, 선지, 버튼 채널을 붙힐 메인 패널
	GridLayout qPanel = new GridLayout(2,1,0,20);	//문제 출력 방식
	JPanel questionPanel= new JPanel(qPanel);	//문제를 출력할 패널
	GridLayout aPanel = new GridLayout(4,1,0,20);	//선지 출력 방식
	JPanel answerPanel = new JPanel(aPanel);	//선지를 출력할 패널
	JPanel choicePanel = new JPanel();	//확인 버튼을 출력할 패널
	ButtonGroup g = new ButtonGroup();	//RadioButton 묶기
	
	boolean modal = false;
	
	Random rand = new Random();
	static int number = MyFrame.number;
	int[] count = new int[number]; //이미 문제에 출제된 단어인지 확인하는 용도
	int[] questionList = new int[10]; //출제될 10문제 정하는 용도
	int rightCount = 0; //정답의 갯수
	static int wrongCount = 0; //오답노트용 count
	int start = 0;	//출제한 문제 수를 카운트하는 용도
	long time1 = System.currentTimeMillis();

	String c = null;
	MyFrame parent = null;
	
	//기본 다이얼로그 구현
	public QuizDialog(MyFrame parent, String title, boolean modal) {
		super(parent, title, modal);
		this.parent = parent;
		this.setSize(500,300);
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		init();
		this.setVisible(true);
	}
	
	
	public void init() {
		
		//객관식 퀴즈 10문제 랜덤 배치
		for(int i=0;i<10;i++) {
			int r = rand.nextInt(number);
			//count가 0이면 배열에 넣은 후 count,출제 빈도를 증가
			if(count[r] == 0 ) {
				questionList[i] = r;
				count[r]++;
				MyFrame.voc[r].Freq++;
			}else {
				//count가 0이 아니면(1이면) 인덱스 감소
				i--;
			}
		}
		
		//시작 화면 출력
		startButton.setPreferredSize(new Dimension(100, 40));
		Label.setFont(font);
		panel1.add(Label);
		panel1.add(startButton);
		this.add(this.panel1);
		initListener();
	}

	public void initListener() {
		
		startButton.addActionListener(this);
		choiceButton.addActionListener(this);
		
		this.addWindowListener(new WindowAdapter() {

			@Override
			public void windowClosing(WindowEvent e) {
				// TODO Auto-generated method stub
				super.windowClosing(e);
				if(!modal) {
					parent.dlg3 = null;
				}
				dispose();
			}
		});
	}


	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		if(e.getActionCommand()=="시작") {
			
			time1 = System.currentTimeMillis();	//시작 시간 저장
			//시작 버튼 클릭 시 패널을 지우고 퀴즈를 시작
			panel1.removeAll();
			panel1.revalidate();
			//panel1.repaint();
		
			//첫 번째 퀴즈 시작
			multipleChoiceQuiz(start);
			
		}
		
		if(e.getActionCommand()=="확인") {
			
			//선지 중 선택된 선지의 답을 추출
			if(R[0].isSelected()) {
				c = R[0].getText();
			}else if(R[1].isSelected()) {
				c = R[1].getText();
			}else if(R[2].isSelected()) {
				c = R[2].getText();
			}else if(R[3].isSelected()) {
				c = R[3].getText();
			}else {
				c = null;
			}
				
			//아무 선지도 선택하지 않았으면 알림창을 띄우고 다시 선택하도록 함
			if(c == null) {
				JOptionPane.showMessageDialog(null, "답을 선택해주세요.");
			}
			
			
			else {
				//정답일 경우 메세지 출력 후 맞은 갯수를 증가함
				if(c.equals(MyFrame.voc[questionList[start]].getKor())) {
					JOptionPane.showMessageDialog(null, "정답입니다.");
					rightCount++;
				}else {
					//오답일 경우 맞는 답도 함께 출력한 후 오답노트 배열에 문제에 출제된 단어,정답,선택한 오답을 차례로 저장
					JOptionPane.showMessageDialog(null, "오답입니다.\n정답은 \""+MyFrame.voc[questionList[start]].getKor()+"\"입니다.");
					
					String v1 = MyFrame.voc[questionList[start]].getEng();
					String v2 = MyFrame.voc[questionList[start]].getKor();
					
					int m = 0;
					
					//단어를 추가할때 마다 wrongCount증가
					if(wrongCount > 0) {
						//이미 오답노트에 등록된 단어라면 잘못 찍은 답만 추가
						for(int i=0;i<wrongCount;i++) {
							if(v1.equals(MyFrame.wrongVoclist[i][0])) {
								m++;
								if(!MyFrame.wrongVoclist[i][2].contains(c)) 
									MyFrame.wrongVoclist[i][2] += (", "+c);
							}
						}
						if(m==0) {
							MyFrame.wrongVoclist[wrongCount][0] = v1;
							MyFrame.wrongVoclist[wrongCount][1] = v2;
							MyFrame.wrongVoclist[wrongCount++][2] = c;
						}
						
					}else {
						MyFrame.wrongVoclist[wrongCount][0] = v1;
						MyFrame.wrongVoclist[wrongCount][1] = v2;
						MyFrame.wrongVoclist[wrongCount++][2] = c;
					}
				}
				
				//문제가 끝나면 패널을 모두 지운 뒤 다음 문제를 재귀호출함
				questionPanel.removeAll();
				answerPanel.removeAll();
				choicePanel.removeAll();
				
				mainPanel.removeAll();
				mainPanel.revalidate();
				//mainPanel.repaint();
				
				multipleChoiceQuiz(++start);
			}
		}
		parent.dlg3 = null;
	}
	
	
	public void multipleChoiceQuiz(int i) {
		
		long time2;
		
		//10문제를 다 출제했을 때 퀴즈 종료 후 맞힌 갯수,소요시간을 출력
		if(i>=10) {
			time2 = System.currentTimeMillis();	//종료 시간 저장
			String s = "퀴즈가 종료되었습니다.\n";
			s += "맞힌 갯수: "+rightCount+"개\n";
			s += "총 소요시간: "+(time2-time1)/1000+"초";
			JOptionPane.showMessageDialog(null, s);
			parent.dlg3 = null;
			dispose();
		}
		
		int[] answer = new int[number];	//이미 출제된 선지인지 확인하는 용도 (한 문제 출제 후 다시 0으로 초기화)
		
		int n = 0;
		
		if(i<10)
			n = questionList[i];
		
		//문제 패널에 문제 출력(북)
		Q1 = new JLabel("객관식 "+(i+1)+"번째 문제");
		Q1.setHorizontalAlignment(JLabel.CENTER);
		Q2 = new JLabel(MyFrame.voc[n].getEng()+"의 뜻은 무엇일까요?");
		Q2.setHorizontalAlignment(JLabel.CENTER);
		
		questionPanel.add(Q1);
		questionPanel.add(Q2);
		
		int[] answerList = new int[4];	//선지 4개를 담을 배열
		
		//첫 번째 인덱스에 답인 선지를 배치
		answerList[0] = n;
		
		//3개의 틀린 선지를 무작위로 선택해 배치
		for(int j=1; j<4; j++) {
			int r = rand.nextInt(number);
			//정답이 선지가 아닌 경우
			if(r != n) {
				//선지의 뜻이 같으면 인덱스 감소
				if(MyFrame.voc[n].getKor().equals(MyFrame.voc[r].getKor())) {
					j--;
					continue;
				}
				//0이면 선지 배열에 포함
				if(answer[r] == 0) {
					answerList[j] = r;
					answer[r]++;
				}
				//이미 선택된 선지면 인덱스 감소
				else {
					j--;
					continue;
				}
			}
			//답인 선지와 같은 선지인 경우 인덱스 감소
			else
				j--;
		}
		//4개의 선지를 무작위로 배치
		change(answerList);
		
		//4개의 라디오버튼에 저장한 선지 출력, 선지 패널에 부착
		for(int k=0; k<4; k++) {
			R[k] = new JRadioButton(MyFrame.voc[answerList[k]].getKor());
			g.add(R[k]);
			answerPanel.add(R[k]);
		}
		
		//메인패널에 문제패널(북), 선지패널(중앙) 부착
		mainPanel.add(questionPanel, BorderLayout.NORTH);
		mainPanel.add(answerPanel, BorderLayout.CENTER);
		
		//버튼 패널에 확인버튼 부착, 메인 패널에 추가(남)
		choicePanel.add(choiceButton);
		mainPanel.add(choicePanel, BorderLayout.SOUTH);
		
		//메인 패널을 frame에 부착
		this.add(mainPanel);
	}
	
	//선지 무작위 배치 메소드
	public static void change(int[] a) {
		Random rand = new Random();
		
		for(int i=0;i<10;i++) {
			int r = rand.nextInt(4);
			int s = rand.nextInt(4);
			int temp;
			temp = a[r];
			a[r] = a[s];
			a[s] = temp;
		}
	}

	@Override
	public void itemStateChanged(ItemEvent e) {
		// TODO Auto-generated method stub
		
	}
}
