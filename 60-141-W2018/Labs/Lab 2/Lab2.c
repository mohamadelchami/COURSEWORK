//Author: Mohamad Elchami Date:January 30th, 2018 Description: Pactice arrays

#include<stdio.h>
#include<stdlib.h>
#include<time.h> //need to use to use rand function

#define M 10 //userdefined value for M
#define N 5 //userdefined value for N

void initializeArray(int a[M][N]);
void randomArray(int a[M][N]);
void sortArray(int *a);
void searchArray(int a[M][N]);
void printArray(int a[M][N]);

int main(void)
{
  int a[M][N]; //initiate the array with 0's
  short menu,search; //for linear search, short because it should not exceed 100

  //Navigation menu prompted with intially and after each fucntion.
  for(int q=0; q==0;)
  {
    printf("============================ Main Menu ===============================\n");
    printf("| 1. Initialize array                                                |\n");
    printf("| 2. Randomly Populate Array                                         |\n");
    printf("| 3. Sort Array                                                      |\n");
    printf("| 4. Search Array                                                    |\n");
    printf("| 5. Print Array                                                     |\n");
    printf("| 6. Quit                                                            |\n");
    printf("======================================================================\n");

    printf("Enter command: ");
    scanf("%hd", &menu);

    // tests command and executes as follows
    if (menu != 6)
    {
      switch(menu)
      {
        case 1:
          printf("========================== Initialize Array ==========================\n");
          initializeArray(a);
          printf("The array has been initilized.\n\n");
          break;

        case 2:
          printf("====================== Randomly Populate Array =======================\n");
          randomArray(a);
          printf("The array has been assigned random values.\n\n");
          break;

        case 3:
          printf("============================= Sort Array =============================\n");
          sortArray(a);
          printf("The array has been sorted.\n\n");
          break;

        case 4:
          printf("============================= Sort Array =============================\n");
          searchArray(a);
          printf("Complete.\n\n");
          break;

        case 5:
          printf("============================= Print Array ============================\n");
          printArray(a);
          printf("\n\n");
          break;
      }
    }

    // Terminates the program.
    else
    {
      q = 1;
      break;
    }
  }

  // printed to confirm that loop has been terminated
  printf("Termianted.\n");

  return 0;
}

//intitalizeArray: Initializes and array with elements of 0
//Input: The array
//output: The array elementes will be assigned values of 0
void initializeArray(int a[M][N])
{
  for(int i=0; i < M; ++i)
  {
    for(int j=0; j < N; ++j)
    {
      a[i][j]=0;
    }
  }
}

//randomArray: Assigned each element a random value
//Input: The array
//Output: Random values to each element in the array
void randomArray(int a[M][N])
{
  srand(time(NULL)); // generate a new random number everytime

  //populate the array with random numbers
  for(int i=0; i < M; ++i)
  {
    for(int j=0; j < N; ++j)
    {
      a[i][j]=rand()%100+1; //assigns random number 1-100
    }
  }
}

//sortArray: Sorts the elements in the array
//Input: The array
//Output: sorts the elements from least to greatest
void sortArray(int *a)
{
  //sorting the array with bubble sort
  int temp;

  for(int i=0;i < M * N; i++)
  {
    for(int j=0; j < M * N-1; j++)
    {
      if(a[j] > a[j+1])
      {
        temp = a[j+1];
        a[j+1]=a[j];
        a[j]=temp;
      }
    }
  }
}

//searchArray: Searchs the array for a specific number
//Input: array
//Output: sorted array elements from least to greatest
void searchArray(int a[M][N])
{
  short search, found=0;

  //prompt user to enter intereger
  printf("Which number would you like to search for? (1-100): ");
  scanf("%hd", &search);

  //Linear search for the user-supplied number
  for(int i=0; i < M; ++i)
  {
    for (int j=0; j < N; ++j)
    {
      if(a[i][j] == search) //if the number is found the location will be displayed
      {
        printf("The number is found at position [%d][%d] in the array.\n", i, j);
        ++found;
      }
    }
  }

  if(found <= 0)
  {
    printf("The number is not found in the array.\n"); // if not found
  }
}

//printArray: Prints the array in a visual table
//Input: Array
//Output: a visual table representations of the array elements
void printArray(int a[M][N])
{
  for(int i=0; i<M; ++i)
    {
      for(int j=0; j<N; ++j)
      {
        printf("%d\t", a[i][j]);
      }
      printf("\n");
    }
}
