package week06lab2;

import week06lab2.Button.OnClickListener;

public class Window {
	Button btn1 = new Button();
	Button btn2 = new Button();
	Button btn3 = new Button();
	
	CallListener listener = new CallListener();
	OnClickListener listener2 = new OnClickListener() {
		@Override
		public void onClick() {
			// TODO Auto-generated method stub
			System.out.println("전화를 겁니다.");
		}
	};
	
	Window(){
		btn1.setOnClickListener(listener);
		btn3.setOnClickListener(listener2);
		
		//익명 객체
		btn2.setOnClickListener(new OnClickListener() {

			@Override
			public void onClick() {
				// TODO Auto-generated method stub
				System.out.println("메세지를 보냅니다.");
			}
		});
	}
	
	/*@Override
	public void onClick() {
		// TODO Auto-generated method stub
		System.out.println("버튼이 클릭됨");
	}*/
}
