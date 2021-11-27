package week08lab1;

public class MyArray<E> {
	int capacity;
	int count = 0;
	E[] arr;
	@SuppressWarnings("unchecked")
	public MyArray(int capacity) {
		this.capacity = capacity;
		arr = (E[])new Object[this.capacity];
	}
	
	public void add(E e) {
		if(this.capacity > count) {
			arr[count++] = e;
		}else {
			System.out.println("공간 부족");
		}
	}
	
	public E getObject(int i) {
		if(i<count)
			return arr[i];
		else
			return null;
	}
}
