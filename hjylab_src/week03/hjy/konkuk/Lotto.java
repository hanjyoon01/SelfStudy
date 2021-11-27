package week03.hjy.konkuk;

import java.util.Random;

public class Lotto {

	public static void main(String[] args) {
			int[] Lotto = makelotto();
			
			for(int i=0; i<Lotto.length-1;i++) {
				int Min = i;
				for(int j=i+1; j<Lotto.length;j++) {
					if(Lotto[j] < Lotto[Min])
						Min = j;
				}
				if(Min != i) {
					int temp = Lotto[Min];
					Lotto[Min] = Lotto[i];
					Lotto[i] = temp;
				}
			}
			System.out.println("202011390 한재윤");
			for(int i: Lotto) {
				System.out.print(i+" ");
			}
	}
	
	public static int[] makelotto() {
		Random rand = new Random();
		int[] Lotto = new int[6];
		for(int i=0;i<Lotto.length;i++){
			Lotto[i] = rand.nextInt(46) + 1;
			for (int j=0;j<i;j++){
				if (Lotto[j] == Lotto[i]) {
					i--;
					break;
				}
			}
		}
		return Lotto;
	}
}
