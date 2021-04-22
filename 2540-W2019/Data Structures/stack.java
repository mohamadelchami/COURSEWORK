
public class stack<E> {

    private linkedList<E> list; //Creates array

    public stack(){

        list= new linkedList<>(); //initializes array length
    }


    //check if full first
    public void push(E data){
        list.addFirst(data);
    }

    //check if empty first
    public E pop(){
        return list.removeFirst();
    }

    //return the top value in the stack
    public E top(){

        if(list.isEmpty()){
            return null;
        }

        else{
            return list.getFirst();
        }
    }


    //return the size of the stack
    public int size(){
       return list.size();
    }

    //return if it empty=true or notempty = flase
    public boolean isEmpty(){
        return list.isEmpty();
    }
}
