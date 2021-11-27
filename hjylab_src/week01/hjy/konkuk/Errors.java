package week01.hjy.konkuk; // -> 패키지 이름 추가했습니다.

// public class errors -> 클래스와 파일의 이름이 같아야 한다.
public class Errors

{
  // public Static main(string[] args) { -> static의 s는 소문자, string의 s는 대문자로 바꿔야 한다. / 타입(void) 추가
	public static void main(String[] args) {

		System.out.println("202011390 한재윤");
	
		//System.out.println(“이 프로그램은 많은 오류를 가지고 있다.”); -> 따옴표 형식이 잘못되었다.
		System.out.println("이 프로그램은 많은 오류를 가지고 있다.");
		//System.0ut.println(“그러나 프로그램이 이 문장을 출력된다면”) -> out의 o를 소문자로 바꾸고, 괄호 뒤에 ;를 추가해야 한다.
		System.out.println("그러나 프로그램이 이 문장을 출력된다면");
		//System.out.Println(“모든 오류를 고친 것이다.); -> println의 p를 소문자로 바꾸고, 문장을 끝마치고 "를 추가해야 한다.
		System.out.println("모든 오류를 고친 것이다.");
		
		//문장들의 따옴표 형식이 잘못되어서 모두 "로 바꿔주었습니다.
  }
}
