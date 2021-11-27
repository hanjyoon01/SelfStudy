package week09lab2;

import java.util.*;

class Student implements Comparable<Student> {
	String name;
	String sid;
	int score;
	
	public Student(String name) {
		this(name,"no info", 0);
	}

	public Student(String name, String sid, int score) {
		this.name = name;
		this.sid = sid;
		this.score = score;
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return this.name+" : "+this.sid+" : "+this.score;
	}

	@Override
	public int compareTo(Student o) {
		// TODO Auto-generated method stub
		return this.name.compareTo(o.name);
	}
}

class StdComparator implements Comparator<Student>{

	int flag;
	StdComparator(){
		flag = 0;
	}
	StdComparator(int flag){
		this.flag = flag;
	}
	@Override
	public int compare(Student o1, Student o2) {
		// TODO Auto-generated method stub
		switch(flag) {
		case 0:
			return o1.name.compareTo(o2.name);
		case 1:
			return o1.sid.compareTo(o2.sid);
		case 2:
			return (o1.score-o2.score)*-1;
		default:
			return o1.name.compareTo(o2.name);
		}
	}
}

public class TestMain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		List<Student> list = new ArrayList<>();
		list.add(new Student("홍길동", "2000", 95));
		list.add(new Student("고길동", "2010", 85));
		list.add(new Student("이길동", "2001", 75));
		list.add(new Student("차길동", "2012", 90));
		list.add(new Student("김길동", "2007", 88));
		
		Collections.shuffle(list);
		Collections.sort(list, new StdComparator(2));
		int index = Collections.binarySearch(list, new Student("이길동"));
		if(index>=0) {
			System.out.println(list.get(index));
		}else {
			System.out.println("등록되어 있지 않음");
		}
		
//		Collections.sort(list, new Comparator<Student>(){
//
//			@Override
//			public int compare(Student o1, Student o2) {
//				// TODO Auto-generated method stub
//				return o1.name.compareTo(o2.name);
//			}
//			
//		});
		
		System.out.println(list);

	}

}
