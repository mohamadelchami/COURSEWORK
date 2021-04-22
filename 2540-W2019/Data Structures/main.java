import java.util.*;

public class main {

    public static void main(String args[]) {

        Comparator C = new Comparator() {
            @Override
            public int compare(Object o1, Object o2) {
                return 0;
            }
        };

        Scanner sc = new Scanner(System.in);
        System.out.println("---------- Lab 1 ----------");
        boolean end = false;
        boolean answer;
        int size;

        while (!end) {
            System.out.println("What would you like to check?");
            System.out.print("1. Check equation(Complete) \n2. Check On1n(Balance)\n3. Merge\n4. Insertion Sort\n5. Quick Sort\n6. Merge Sort\n7. Heap Sort(input)\n8. Heap Sort(automated)\n9. Binary Search Tree\n10. Exit\nEnter Command: ");
            int choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Enter an equation: ");
                    String str1 = sc.nextLine();
                    boolean valid = isValid(str1);
                    if (valid) {
                        answer = bracketMatch(str1);

                        if(answer){
                            System.out.println("Complete.\n");
                        }
                        else{
                            System.out.println("Not complete.\n");
                        }
                    }
                    else {
                        System.out.println("Equation contains invalid characters, try again;");
                    }

                    break;

                case 2:
                    System.out.print("Enter a series of numbers: ");
                    String str2 = sc.nextLine();
                    valid = isValid2(str2);
                    if(valid){
                        answer = numberCount(str2);

                        if(answer){
                            System.out.println("Balanced.\n");
                        }
                        else{
                            System.out.println("Not Balanced\n");
                        }
                    }
                    else {
                        System.out.println("Equation contains invalid characters, try again;");
                    }
                    break;

                case 3:
                    int current;
                    String input;
                    queue Queues = new queue();
                    queue Queues2 = new queue();
                    boolean endloop = false;

                    System.out.println("---- List A ----");
                    while(endloop == false){
                        System.out.println("Enter a digit (E to end): ");
                        input = sc.nextLine();
                        current = input.charAt(0);

                        if(current == 'E'){
                            endloop = true;
                        }
                        else{
                           current = Integer.parseInt(input);
                           Queues.enqueue(current);
                        }

                    }

                    endloop = false;

                    System.out.println("---- List B ----");
                    while(endloop == false){
                        System.out.println("Enter a digit (E to end): ");
                        input = sc.nextLine();
                        current = input.charAt(0);

                        if(current == 'E'){
                            endloop = true;
                        }
                        else{
                            current = Integer.parseInt(input);
                            Queues2.enqueue(current);
                        }

                    }

                   merge(Queues, Queues2);
                   break;

                case 4:


                    break;

                case 5:

                    System.out.print("How many numbers will you be entering?: ");
                    size = sc.nextInt();

                    int[] quicksort = new int[size];

                    for(int i=0; i < size ; i++){
                        System.out.print("Enter a number: ");
                        quicksort[i] = sc.nextInt();
                    }

                    int low = 0;
                    int high = size-1;

                    displayArray(quickSort(quicksort, low, high));
                    break;

                case 6:

                    System.out.print("How many numbers will you be entering?: ");
                    size = sc.nextInt();

                    int temp;

                    queue MergeQueue = new queue();

                    for(int i=0; i < size ; i++){
                        System.out.print("Enter a number: ");
                        temp = sc.nextInt();
                        MergeQueue.enqueue(temp);
                    }


                    mergeSort(MergeQueue, C).print();


                    break;

                case 7:
                    System.out.print("How many numbers will you be entering?: ");
                    size = sc.nextInt();

                    int[] heapsortarr = new int[size];

                    for(int i=0; i < size ; i++){
                        System.out.print("Enter a number: ");
                        heapsortarr[i] = sc.nextInt();
                    }

                    break;



                case 8:
                    Random rand = new Random();
                    for(int i = 8; i > 1048576; i *= 2){
                        int heapsortarr2[] = new int[i];

                        for(int j=0; j < i ; j++){
                            heapsortarr2[j] = rand.nextInt();
                        }

                        long starttime = System.currentTimeMillis();
                        heapSort(heapsortarr2);
                        long endtime = System.currentTimeMillis();
                        long runtime = endtime - starttime;
                        System.out.println("Time: " + runtime);

                    }

                case 9:
                    BST BinaryTree = new BST();
                    System.out.print("How many items would you like to enter: ");
                    size = sc.nextInt();
                    int currentitem;

                    System.out.println("Would you like to: ");
                    System.out.println("1. Generate 1 to n ");
                    System.out.println("2. Input Numbers ");
                    System.out.println("3. Question 7 ");
                    System.out.println("Enter Command: ");
                    int operation = sc.nextInt();

                    switch(operation){

                        case 1:
                            for(int i=1 ; i<size+1 ; i++ ){
                                BinaryTree.insert(i);
                            }
                            break;

                        case 2:
                            for(int i = 0; i<size; i++){
                                System.out.print("Enter a number: ");
                                currentitem = sc.nextInt();
                                BinaryTree.insert(currentitem);
                            }
                            break;

                        case 3:
                            BinaryTree.insert(8);
                            BinaryTree.insert(4);
                            BinaryTree.insert(12);
                            BinaryTree.insert(2);
                            BinaryTree.insert(6);
                            BinaryTree.insert(10);
                            BinaryTree.insert(14);
                            BinaryTree.insert(1);
                            BinaryTree.insert(3);
                            BinaryTree.insert(5);
                            BinaryTree.insert(7);
                            BinaryTree.insert(9);
                            BinaryTree.insert(11);
                            BinaryTree.insert(13);
                            BinaryTree.insert(15);
                            break;

                    }

                    boolean loop = true;

                    while(loop == true){
                        System.out.println("What would you like to do?");
                        System.out.println("1. Search for item");
                        System.out.println("2. Print Tree");
                        System.out.println("3. Search 100,000 times");
                        System.out.println("4. Remove");
                        System.out.println("5. Exit");
                        System.out.print("Enter command: ");
                        size = sc.nextInt();
                        switch(size){
                            case 1:
                                System.out.print("What item would you like to search for: ");
                                currentitem = sc.nextInt();
                                BinaryTree.search(BinaryTree.root, currentitem);
                                break;

                            case 2:
                                BinaryTree.print();
                                break;

                            case 3:
                                System.out.print("What item would you like to search for: ");
                                currentitem = sc.nextInt();
                                long starttime = System.currentTimeMillis();
                                for( int i =0; i<100000; i++){
                                    BinaryTree.searchMULTI(BinaryTree.root, currentitem);
                                }
                                long endtime = System.currentTimeMillis();
                                long runtime = endtime - starttime;
                                System.out.println("The CPU runtime is: " + runtime);
                                break;

                            case 4:
                                System.out.print("What item would you like to remove: ");
                                currentitem = sc.nextInt();
                                BinaryTree.remove(currentitem);
                                break;

                            case 5:
                                loop = false;
                                break;
                        }
                    }
                    break;

                case 10:
                    end = true;
                    break;
            }
        }

    }

    private static boolean bracketMatch(String str){
        stack Stack = new stack();
        char current;


        for(int i = 0; i < str.length(); i++){
            current = str.charAt(i);

            if(current == '('){
                Stack.push(current);
            }
            else if (current == '{'){
                Stack.push(current);
            }
            else if(current == '[') {
                Stack.push(current);
            }

            else if (current == ')'){
                if(Stack.isEmpty()){
                    return false;
                }
                else if (Stack.top().equals('(')){
                    Stack.pop();
                }
                else{
                    return false;
                }
            }

            else if (current == '}'){
                if(Stack.isEmpty()){
                    return false;
                }
                else if (Stack.top().equals('{')){
                    Stack.pop();
                }
                else{
                    return false;
                }

            }

            else if (current == ']'){
                if(Stack.isEmpty()){
                    return false;
                }
                else if (Stack.top().equals('[')){
                    Stack.pop();
                }
                else{
                    return false;
                }
            }

        }

        if(Stack.isEmpty()){
            return true;
        }
        else{
            return false;
        }
    }


    private static boolean numberCount(String str){
        stack Stack = new stack();
        char current;

        for(int i = 0; i < str.length(); i++){
            current = str.charAt(i);

            if( i > 0 && Stack.isEmpty()){
                return false;
            }

            else if(current == '0') {
                Stack.push(current);
            }
            else if (current == '1'){
                Stack.pop();
            }
        }

        if(Stack.isEmpty()){
            return true;
        }
        else{
            return false;
        }
    }


    private static boolean isValid(String str){
        boolean x = true;
        for(int i = 0; i < str.length(); i++){
            switch(str.charAt(i)) {
                case '{': break;
                case '}': break;
                case '[': break;
                case ']': break;
                case '(': break;
                case ')': break;
                case '0': break;
                case '1': break;
                case '2': break;
                case '3': break;
                case '4': break;
                case '5': break;
                case '6': break;
                case '7': break;
                case '8': break;
                case '9': break;
                case '+': break;
                case '-': break;
                case '*': break;
                case '/': break;
                default: x = false;
                         break;
            }
        }
        return x;
    }

    private static boolean isValid2(String str){
        boolean x = true;
        for(int i = 0; i < str.length(); i++){
            switch(str.charAt(i)) {
                case '0': break;
                case '1': break;
                default: x = false;
                    break;
            }
        }
        return x;
    }

    public static queue merge(queue Q1, queue Q2){

        queue SORTED = new queue();


        for(; !Q1.isEmpty() || !Q2.isEmpty();){

            if(Q1.isEmpty()){
                while(!Q2.isEmpty()){
                    SORTED.enqueue(Q2.first());
                    System.out.print(SORTED.dequeue());
                    Q2.dequeue();
                }
            }

            else if(Q2.isEmpty()){
                while(!Q1.isEmpty()){
                    SORTED.enqueue(Q1.first());
                    System.out.print(SORTED.dequeue());
                    Q1.dequeue();
                }
            }

            else if((int)Q1.first() < (int)Q2.first()){
                SORTED.enqueue(Q1.first());
                System.out.print(SORTED.dequeue()+ " ");
                Q1.dequeue();
            }

            else{
                SORTED.enqueue(Q2.first());
                System.out.print(SORTED.dequeue() + " ");
                Q2.dequeue();
            }
        }

        return SORTED;
    }

    public static int[] insertionSort(int array[], int n){

        int temp;
        int key;

        for(int i = 1; i < n ; i++){

            key = array[i];
            int j = i - 1;

            for(; j >=0 && array[j] > key; j--) {
                    array[j+1] = array[j];
            }

            array[j+1] = key;
        }

        displayArray(array);

        return array;
    }

    public static int[] quickSort(int[] array, int a, int b){

        if(a >= b){
            return array;
        }

        int p = array[b];
        int l = a;
        int r = b-1;
        int temp;

        while(l <= r){
            while(l <= r && array[l] <= p){
                l += 1;
            }

            while(l <= r && array[r] >= p){
                r -= 1;
            }

            if(l < r){
                temp = array[l];
                array[l] = array[r];
                array[r] = temp;
            }
        }

        temp = array[l];
        array[l] = array[b];
        array[b] = temp;

        quickSort(array, a, l-1);
        quickSort(array, l+1, b);

        return array;
    }


    public static queue mergeSort(queue Q, Comparator C){

        if(Q.size() > 1){

            queue L = new queue();
            queue G = new queue();

            while(L.size() < Q.size()){
                L.enqueue(Q.dequeue());
            }

            while(!Q.isEmpty()){
                G.enqueue(Q.dequeue());
            }

            L = mergeSort(L, C);
            G = mergeSort(G, C);



            Q = mergeQ(L, G, C);
        }

        return Q;

    }

    public static queue mergeQ(queue L, queue G, Comparator C){

        queue Q = new queue();

        while(!L.isEmpty() && !G.isEmpty()){
            if((int)L.first() < (int)G.first()){
                Q.enqueue(L.dequeue());
                //Q.print();
                //System.out.print("\n");
                //System.out.println("1");
            }
            else{
                Q.enqueue(G.dequeue());
                //Q.print();
                //System.out.print("\n");
                //System.out.println("2");
            }
        }

        while(!L.isEmpty()){
            Q.enqueue(L.dequeue());
            //.print();
            //System.out.print("\n");
            //System.out.println("3");
        }

        while(!G.isEmpty()){
            Q.enqueue(G.dequeue());
            //Q.print();
           // System.out.print("\n");
            //System.out.println("4");
        }
        //Q.print();

        return Q;
    }

    public static void displayArray(int[] array){

        for(int i = 0; i < array.length; i++) {

            System.out.println(array[i]);
        }
    }


    public static void displayQueue(queue Q){

        for(int i = 0; i < Q.size(); i++) {

            System.out.print(Q.dequeue() + " ");
        }

        System.out.println("\n");
    }

    public static void heapSort(int[] array){

    }

}
