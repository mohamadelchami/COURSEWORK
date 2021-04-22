public class heap {
    private int[] arr;
    private int maxSize;
    private int currentSize;

    public heap(int capacity, int[] a){
        currentSize = 0;
        maxSize = capacity;
        arr = new int[maxSize];
        arr = a;
    }

    void minHeapify(int i){
        int L = 2*i + 1;
        int R = 2*i +2;
        int smallest  = i;

        if(L < currentSize && arr[L] < arr[i]){
            smallest = L;
        }

        if(R < currentSize && arr[R] < arr[smallest]){
            smallest = R;
        }

        if(smallest != i){
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
            minHeapify(smallest);
        }
    }


    public int removeMin(){

        if(size() == 1){
            currentSize--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size()-1];
        currentSize--;

        minHeapify(0);

        return root;

    }

    public int min(){
        return arr[0];
    }

    public void insert(int k){
        if(size() == maxSize){
            System.out.println("Full.");
            return;
        }

        currentSize++;
        int i = size()-1;
        arr[i] = k;

        int parent = (i-1)/2;

        while(i != 0 && arr[parent]>arr[i]){
            int temp = arr[i];
            arr[i] = arr[parent];
            arr[parent] = temp;
            i = parent;
        }
    }

    public int size(){
        return currentSize;
    }

    public boolean isEmpty(){
        if(size() == 0){
            return true;
        }
        else{
            return false;
        }
    }


}
