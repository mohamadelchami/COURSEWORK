public class BST {

    tnode root;


    public BST(){
        root=null;
    }

    public void insert(int item){

        root = insertRecursive(root, item);

    }

    public tnode insertRecursive(tnode root, int item){
        if(root == null){
            root = new tnode(item);
            return root;
        }

        if(item < root.getKey()){
            root.left = insertRecursive(root.left,item);

        }
        else if(item > root.getKey()){
            root.right = insertRecursive(root.right, item);
        }

        return root;
    }

    public void remove(int item ) {
        root = removeRecursive(root, item);
    }

    public tnode removeRecursive(tnode root, int item){
        if(root == null){
            return root;
        }
        if(item < root.getKey()){
            root.left = removeRecursive(root.left, item);
        }
        else if(item > root.getKey()){
            root.right = removeRecursive(root.right, item);
        }
        else{
           if(root.left == null){
               return root.right;
           }
           else if(root.right == null){
               return root.left;
           }

           root.setKey(minValue(root.right));

           root.right = removeRecursive(root.right, root.getKey());
        }

        return root;
    }

    public int minValue(tnode root){
        int minvalue = root.getKey();
        for ( ;root.left !=null; ){
            minvalue = root.left.getKey();
            root = root.left;
        }

        return minvalue;
    }


    public tnode search(tnode root, int item){
        if(root == null){
            System.out.println("NOT FOUND!");
            return root;
        }
        else if(root.getKey() == item){
            System.out.println("FOUND!");
            return root;
        }
        else if(root.getKey() > item){
            return search(root.left, item);
        }
        else{
            return search(root.right, item);
        }
    }

    public tnode searchMULTI(tnode root, int item){
        if(root == null){
            return root;
        }
        else if(root.getKey() == item){
            return root;
        }
        else if(root.getKey() > item){
            return searchMULTI(root.left, item);
        }
        else{
            return searchMULTI(root.right, item);
        }
    }

    public void print(){
        inOrderRecursive(root);
    }

    public void inOrderRecursive(tnode root){
        if(root!=null){
            inOrderRecursive(root.left);
            System.out.println(root.getKey());
            inOrderRecursive(root.right);
        }
    }




}
