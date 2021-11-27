package week12lab1;

public class TestMain implements Runnable {
	
	static Thread mainth;
	static Thread th;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
	
		mainth = Thread.currentThread();
		System.out.println(mainth.getName()+" : "+mainth.getState());
		
		th = new Thread(new TestMain());
		System.out.println(th.getName()+" : "+th.getState());
		th.start();
		System.out.println(th.getName()+" : "+th.getState());
		
	}

	@Override
	public void run() {
		// TODO Auto-generated method stub
		MyThread a = new MyThread("A");
		System.out.println(a.getName()+" : "+a.getState());
		a.start();
		System.out.println(a.getName()+" : "+a.getState());
		
		try {
			a.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		System.out.println(a.getName()+" : "+a.getState());
		MyThread b = new MyThread("B");
		System.out.println(b.getName()+" : "+b.getState());
		b.start();
		
	}
	
	class MyThread extends Thread{
		MyThread(String name){
			this.setName(name);
		}

		@Override
		public void run() {
			// TODO Auto-generated method stub
			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			//System.out.println(th.getName()+" : "+th.getState());
		}
	}
}
