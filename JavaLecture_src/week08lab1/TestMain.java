package week08lab1;

import java.util.*;
import java.util.Map.Entry;

public class TestMain {

	public static void main(String[] args) {
		
		HashMap<String, Word> map = new HashMap<>();
		map.put("red", new Word("red","빨강"));
		map.put("green", new Word("green","초록"));
		map.put("blue", new Word("blue","파랑"));
		System.out.println(map);
		
		Collection<Word> word = map.values();
		for(Word w: word) {
			System.out.println(w);
		}
		
//		Set<Map.Entry<String, Word>> set = map.entrySet();
//		
//		Set<String> keyset = map.keySet();
//		Iterator<Entry<String, Word>> it = set.iterator();
//		while(it.hasNext()) {
//			Entry<String, Word> entry = it.next();
//			String key = entry.getKey();
//			Word word = entry.getValue();
//			System.out.println(key+" : "+word);
//		}
		
		
//		Set<Word> set = new HashSet<>();
//		set.add(new Word("red","빨강"));
//		set.add(new Word("green","초록"));
//		set.add(new Word("blue","파랑"));
//		set.add(new Word("blue","파랑"));
//		set.add(new Word("blue","파랑"));
//		
//		Set<Word> set2 = new HashSet<>();
//		set2.add(new Word("red","빨강"));
//		set2.add(new Word("green","초록"));
//		set2.add(new Word("yellow","노랑"));
//
//		Set<Word> set3 = new HashSet<>(set2);
//		set3.retainAll(set);
//		System.out.println(set3);

		
//		System.out.println(set);
//		System.out.println(set.size());
//		
//		Iterator<Word> it = set.iterator();
//		while(it.hasNext()) {
//			Word word = it.next();
//			System.out.println(word);
//		}
		
		
//		ListIterator<Word> it = list.listIterator();
//		while(it.hasNext()) {
//			Word word = it.next();
//			System.out.println(word);
//		}
//		while(it.hasPrevious()) {
//			Word word = it.previous();
//			System.out.println(word);
//		}
	
		
//		Word[] arr = list.toArray(new Word[list.size()]);
//		for(Word word:arr) 
//			System.out.println(word.kor);
//		}
		
		
//		Object[] obj = list.toArray();
//		
//		for(Object word:obj) {
//			if(word instanceof Word) {
//				Word a = (Word) word;
//				System.out.println(a.kor);
//			}
//		}
		
		
//		List<Integer> vec0 = new Vector<Integer>();
//		Vector<Integer> vec1 = new Vector<Integer>();
//		Vector<Integer> vec2 = new Vector<>();
//		Vector<Integer> vec3 = new Vector<>(5);
//		
//		Vector<String> vec4 = new Vector<String>();
//		vec4.add("greenjoa1");
//		vec4.add("greenjoa2");
//		vec4.add("greenjoa3");
//		vec4.add("greenjoa4");
//		vec4.add("greenjoa5");
//		vec4.add("greenjoa6");
//		vec4.add("greenjoa7");
//		vec4.add("greenjoa8");
//		vec4.add("greenjoa9");
//		vec4.add("greenjoa10");
//		vec4.add("greenjoa9");
//		vec4.add("greenjoa10");
//		
//		for(String str:vec4) {
//			System.out.println(str);
//		}
//		System.out.println("==================");
//		System.out.println(vec4.size());
//		System.out.println(vec4.capacity());
//		System.out.println("==================");
//		
//		List<String> list = vec4.subList(0,4);
//		list.set(1,"bluejoa");
//		vec4.subList(0,4).clear();
//		System.out.println(vec4);
//		
//		
//		
//		Vector<String> vec5 = new Vector<String>(3);
//		System.out.println(vec5.size());
//		System.out.println(vec5.capacity());
//		System.out.println("==================");
//		vec5.add("greenjoa1");
//		vec5.add("greenjoa2");
//		vec5.add("greenjoa3");
//		vec5.add("greenjoa4");
//		vec5.add("greenjoa5");
//		System.out.println(vec5.size());
//		System.out.println(vec5.capacity());
//		System.out.println("==================");
//		
//		Vector<String> vec6 = new Vector<>(3,5);
//		vec6.add("greenjoa1");
//		vec6.add("greenjoa2");
//		vec6.add("greenjoa3");
//		vec6.add("greenjoa4");
//		vec6.add("greenjoa5");
//		System.out.println(vec6.size());
//		System.out.println(vec6.capacity());
//		System.out.println("==================");
		
		
//		MyArray<Integer> arr1 = new MyArray<Integer>(10);
//		arr1.add(10);
//		arr1.add(20);
//		arr1.add(30);
//		Integer num = arr1.getObject(5);
//		if(num == null) {
//			System.err.println("인덱스 참조 오류");
//			return;
//		}
////		try {
////			int num = arr1.getObject(5);
////		}catch(NullPointerException e) {
////			System.err.println("인덱스 참조 오류")
////		}
//		
//		
//		MyArray<Integer> arr2 = new MyArray<>(20);
//		MyArray<String> arr3 = new MyArray<>(10);
//		arr3.add("greenjoa1");
//		arr3.add("greenjoa1");
//		arr3.add("greenjoa1");
//		arr3.add("greenjoa1");
//		String str = arr3.getObject(1);
	}

}
