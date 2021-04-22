//Author: Mohamad Elchami
//Date: Feb. 12th, 2018
//Description: Pointer Practice

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void PopulateArray(int* NumList);
void PrintArray(int* NumList);
void Swap(int* a, int* b);
int Triple(int* NumList);
void BubbleSort(int* NumList, int size, int sort);

int main()
{
  int NumList[MAX];

  PopulateArray(NumList);
  printf("Array: %d\n", *NumList);
  PrintArray(NumList);

  Triple(NumList);
  printf("Tripled Array:\n");
  PrintArray(NumList);

  printf("Ascending: \n");
  BubbleSort(NumList, MAX, 1);
  PrintArray(NumList);

  printf("\nDescending:\n");
  BubbleSort(NumList, MAX, -1);
  PrintArray(NumList);

}

//PopulateArray: Populates the array with values starting at 4 and incrementing by 2
//Input: Pointer to the array NumList
//Output: Values to the array from 4 incerementing by 2
void PopulateArray(int* NumList)
{
  for(int i = 0, j = 4; i < MAX; i++)
  {
    *NumList++ = j;
    j += 2;
  }
}

//PrintArray: Prints the array in a visual table
//Input: Pointer to NumList array
//Output: Prints the array elements in a visual table
void PrintArray(int* NumList)
{
  for(int i = 0 ; i < MAX ; i++)
  {
    printf("%d\t", *NumList++);
    printf("-- %d -- \n", *NumList);
  }
  printf("\n\n");
}

//Triple: Triples each element value in the array
//Input: Pointer to NumList array
//Output: The array with tripled values
int Triple(int* NumList)
{
  for(int i = 0; i < MAX ; i++ )
  {
    *NumList++ *= 3;
  }
return 0;
}

//BubbleSort: Sorts the array in ascending order
//Input: Pointer to the NumList array
//Output: a sorted array
void BubbleSort(int* NumList, int size, int sort)
{

  if(sort == 1)
  {
    for(int i = 0; i < (size-1) ; i++ )
    {
        for(int j = (size-1) ; j > i  ; j-- )
        {
          if((NumList+j) < (NumList+(j-1)))
          {
            Swap((NumList+j), (NumList+(j-1)));
          }
        }
    }
  }

  else if( sort == -1)
  {
    for(int i = 0; i < (size-1) ; i++ )
    {
      for(int j = (size-1) ; j > i  ; j-- )
      {
        if((NumList+j) > (NumList+(j-1)))
        {
          Swap((NumList+j), (NumList+(j-1)));
        }
      }
    }
  }
}

//Swap: Swaps the value of two integers
//Input: pointes to two integers
//Output: None
void Swap(int* a, int* b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
