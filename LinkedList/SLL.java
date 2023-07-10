class Node {
    public int data;
    public Node next;
    Node(){
        this.data  = 0;
        this.next = null;
    }
    Node(int data){
        this.data = data;
        this.next = null;
    }
}

class LL{
    private Node head;
    private Node tail;
    LL(){
        this.head = this.tail = null;
    }
    @Override
    public String toString(){
        String ans = "";
        Node ptr = head;
        while(ptr != null){
            ans = ans + ptr.data + " -> ";
            ptr = ptr.next;
        }
        ans = ans + "NULL";
        return ans;
    }
    public void addFirst(int data){
        Node node = new Node(data);
        if(head == null){
            head = tail = node;
            return;
        }
        node.next = head;
        head = node;
    }
    public void addLast(int data){
        Node node = new Node(data);
        if(this.head == null){
            head = tail = node;
            return;
        }
        tail.next = node;
        tail = node;
    }
    public void addAt(int index, int data){
        if(index == 0){
            addFirst(data);
            return;
        } 
        Node node = new Node(data);
        Node ptr = head;
        for(int i=1;(i<=index-1 && ptr!=null);i++){
            ptr = ptr.next;
        }
        if(ptr != null){
            node.next = ptr.next;
            ptr.next = node;
        }
        
    }
    public void removeFirst(){
        if(head == null) return;
        head  = head.next;
        if(head == null) tail = null;
    }
    public void removeLast(){
        if(head == null) return;
        if(head.next == null){
            head = tail = null;
            return;
        }
        Node ptr = head;
        while(ptr.next.next != null){
            ptr = ptr.next;
        }
        ptr.next = null;
    }
    public void removeAt(int index){
        if(index == 0){
            removeFirst();
            return;
        }
        Node ptr = head;
        for(int i=1;(i<=index-1 && ptr!=null);i++){
            ptr = ptr.next;
        }
        if(ptr!=null && ptr.next!=null){
            ptr.next = ptr.next.next;
        }
        else throw new IndexOutOfBoundsException("Linked List Index out of Bounds");
    }
    public int valueAt(int index){
        Node ptr = head;
        for(int i=1;(i<=index && ptr!=null);i++){
            ptr = ptr.next;
        }
        if(ptr == null) throw new IndexOutOfBoundsException("Linked List Index Out of Bounds");
        return ptr.data;
    }

}




public class SLL {
    public static void main(String[] args) {
        LL lis = new LL();
        lis.addFirst(1);
        lis.addLast(2);
        lis.addFirst(0);
        lis.addLast(3);
        lis.addAt(3, 78348);
        lis.addLast(5);
        lis.addAt(4, 4);
        lis.addFirst(-1);
        lis.addLast(-49);
        System.out.println(lis);
        lis.removeFirst();
        lis.removeLast();
        lis.removeAt(3);
        System.out.println(lis);
        System.out.println(lis.valueAt(3));

    }
}
