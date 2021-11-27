package week03.hjy.konkuk;

public class ScoreRank {

	public static void main(String[] args) {

		System.out.println("202011390 한재윤");
		String[] name = new String[] {"홍길동","이길동","김길동","고길동"};
		int[][] score = new int[][] {
			{10,20,30,0,1},
			{15,30,20,0,1},
			{20,20,10,0,1},
			{5,30,20,0,1}
		};
		for(int[] arr: score) {
			for(int i=0; i<arr.length-2;i++) {
				arr[arr.length-2] += arr[i];
			}
		}
		for(int i=0;i<score.length;i++) {
			for(int j=i+1;j<score.length;j++) {
				if(score[i][score[0].length-2] < score[j][score[0].length-2])
					score[i][score[0].length-1]++;
				else
					score[j ][score[0].length-1]++;
			}
		}
		
		for(int i=0;i<score.length;i++) {
			System.out.print(name[i]+" >> ");
			int k=0;
			for(int j: score[i]) {
				if(k==3)
					System.out.print(": ");
				if(k==4)
					System.out.print(": ");
				System.out.print(j+" ");
				k++;
			}
			System.out.println();
		}
	}
}
