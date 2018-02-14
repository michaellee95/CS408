package individual.v2;

public class Node {

	String value;
	Node next;
	Node prev;
	
	public Node (String value, Node next, Node prev){
		this.value = value;
		this.next = next;
		this.prev = prev;
	}
	
	public void setNext(Node next){
		this.next = next;
	}
	
	public Node getNext(){
		return next;
	}
	
	public void setPrev(Node prev){
		this.prev = prev;
	}
	
	public Node getPrev(){
		return prev;
	}
	
	public void setValue(String value){
		this.value = value;
	}
	
	public String getValue(){
		return value;
	}
}
