package week07lab3;

public class Word {
	String eng;
	public String kor;
	
	public Word(String eng, String kor) {
		super();
		this.eng = eng;
		this.kor = kor;
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return eng+" : "+kor;
	}
	
}
