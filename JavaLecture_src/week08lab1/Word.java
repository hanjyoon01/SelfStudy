package week08lab1;

public class Word {
	@Override
	public boolean equals(Object obj) {
		// TODO Auto-generated method stub
		if(obj instanceof Word) {
			Word temp = (Word)obj;
			return this.eng == temp.eng && this.kor == temp.kor;
		}else
			return super.equals(obj);
	}

	@Override
	public int hashCode() {
		// TODO Auto-generated method stub
		return eng.hashCode() + kor.hashCode();
	}

	public String eng;
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
