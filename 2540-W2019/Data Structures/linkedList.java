public class linkedList<E> extends Node<E>{

    public Node<E> head = null;
    public Node<E> tail = null;
    protected int size = 0;

    public linkedList(){

    }

    public void addFirst(E e){
        head = new Node<E>(e, head);

        if (size == 0){
            tail = head;
        }
        size ++;
    }

    public E removeFirst(){
        if(isEmpty()){
            return null;
        }

        E ans = head.getElement();
        head = head.getNext();
        size--;

        if(size == 0){
            tail = null;
        }
        return ans;
    }

    public void addLast(E e){
        Node<E> add = new Node<>(e, null);

        if(isEmpty()){
            head = add;
        }
        else{
            tail.setNext(add);
        }

        tail = add;
        size++;
    }

    public E removeLast(){
        if(isEmpty()){
            return null;
        }

        Node current = new Node();

        while(head.getNext() != tail) {
            current = head.getNext();
        }

        E ans = tail.getElement();
        tail = current;
        size--;

        if(size == 0){
            tail = null;
        }
        return ans;
    }

    public E getFirst(){
        if(isEmpty()){
            return null;
        }
        else{
            return head.getElement();
        }
    }

    public E getLast(){
        if(isEmpty()){
            return null;
        }
        else{
            return tail.getElement();
        }
    }

    public int size(){
        return size;
    }

    public boolean isEmpty() {
        if(size == 0) {
            return true;
        }
        else {
            return false;
        }
    }

    public Node getHead(){
        return head;
    }


}
