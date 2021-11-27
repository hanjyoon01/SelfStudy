package Project05;

public class Word {
	private String eng;
	private String kor;
	public int Freq;
	
	public String getEng() {
		return eng;
	}

	public void setEng(String eng) {
		this.eng = eng;
	}

	public String getKor() {
		return kor;
	}

	public void setKor(String kor) {
		this.kor = kor;
	}

	public int getFreq() {
		return Freq;
	}

	public void setFreq(int freq) {
		this.Freq = freq;
	}

	public Word(String eng, String kor, int Freq) {
		super();
		this.eng = eng;
		this.kor = kor;
		this.Freq = Freq;
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return eng+" : "+kor;
	}
}
