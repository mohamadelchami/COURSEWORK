public class queue<E> {

    private linkedList<E> list;

    public queue(){
        list= new linkedList<E>();
    }

    //check if full first
    public void enqueue(E data) throws IllegalStateException{
        list.addLast(data);
    }

    //check if empty first
    public E dequeue(){
        return list.removeFirst();
    }

    //return the top value in the stack
    public E first(){

        if(list.isEmpty()){
            return null;
        }

        else{
            return list.getFirst();
        }
    }

    public E last(){

        if(list.isEmpty()){
            return null;
        }

        else{
            return list.getLast();
        }
    }

    public int size(){

        return list.size();
    }

    public boolean isEmpty(){

        return list.isEmpty();
    }

    public void print(){
        Node pointer = list.head;

        for(int i = 0; i < size(); i++ ){
            System.out.print(pointer.getElement() + " ");
            pointer = pointer.getNext();
        }

        System.out.print("\n");
    }



}
