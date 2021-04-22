public class tnode {

    private int key;
    public tnode left;
    public tnode right;

    public tnode(){
        left = right = null;
    }

    public tnode(int item){
        key = item;
        left = right = null;
    }

    public int getKey(){
        return key;
    }

    public void setKey(int item ){
        key = item;
    }
}
