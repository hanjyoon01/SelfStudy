package week09lab1;

import java.util.*;

public class TestMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Integer[] arr = {10,5,8,3,2,7,9};
		List<Integer> list = new ArrayList<>();
		Collections.addAll(list, arr);
		Collections.sort(list, Collections.reverseOrder());
//		Collections.shuffle(list);
//		Collections.reverse(list);
		for(int num:list) 
			System.out.print(num+"\t");
		System.out.println();

//		Deque <Word> queue = new LinkedList<>();
//		queue.offer(new Word("red", "빨강"));
//		queue.offer(new Word("green", "초록"));
//		queue.offer(new Word("blue", "파랑"));
//		
//		Iterator<Word> it = queue.iterator();
//		while(it.hasNext()) {
//			Word word = it.next();
//			System.out.println(word);
//		}
//		
//		while(!queue.isEmpty()) {
//			Word word = queue.poll();
//			System.out.println(word);
//		}
		
	
//		Deque <Word> stack = new ArrayDeque<>();
//		stack.push(new Word("red", "빨강"));
//		stack.push(new Word("green", "초록"));
//		stack.push(new Word("blue", "파랑"));
//		
//		Iterator<Word> it = stack.iterator();
//		while(it.hasNext()) {
//			Word word = it.next();
//			System.out.println(word);
//		}
//		
//		while(!stack.isEmpty()) {
//			Word word = stack.pop();
//			System.out.println(word);
//		}
	}
}
