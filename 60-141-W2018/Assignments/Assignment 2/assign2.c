//Author: Mohamad Elchami Date: Feb 26th, 2018 Description: 2D Array Manipulation

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define COL 20
#define ROW 20

//prototypes
void PopulateArray2DUnique (int A[][COL], unsigned int rowsize, unsigned int colsize, int min, int max);
int Check (int A[][COL], int number, unsigned int rowsize, unsigned int colsize);
void DisplayArray2D(int A[][COL], unsigned int rowsize, unsigned int colsize);
int FindLargest(int A[][COL], unsigned int rowsize, unsigned int colsize);
int FindColSum(int A[][COL], unsigned int rowsize, unsigned int colsize, unsigned int col_to_sum);
int Sort2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize);
int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize);
int CopyArray2DSpiral(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize);

int main()
{
  unsigned int rowsize, colsize, min, max, largest, col_to_sum, sum;
  int A[ROW][COL];
  int B[ROW][COL];

  //Ask user to input amount of rows and columns
  printf("Enter the number of rows and columns (rows,columns): ");
  scanf("%d,%d", &rowsize, &colsize);

  //Ask user for minimum number
  printf("Enter the minimum number: ");
  scanf("%d", &min);

  //Ask user for maximum number
  printf("Enter the maximum number: ");
  scanf("%d", &max);

  //Funtions

  PopulateArray2DUnique (A, rowsize, colsize, min, max);
  printf("DisplayArray2D:\n");
  DisplayArray2D(A, rowsize, colsize);

  largest = FindLargest(A, rowsize, colsize);
  printf("Find Largest: %d\n", largest);

  printf("What column would you like to find the sum of?: ");
  scanf("%d", &col_to_sum);
  sum = FindColSum(A, rowsize, colsize, col_to_sum);
  printf("FindColSum of col %d: %d\n", col_to_sum, sum);


  Sort2DArray(A, rowsize, colsize);
  printf("Sort2DArray followed by DisplayArray2D:\n");
  DisplayArray2D(A, rowsize, colsize);

  printf("\n");
  CopyArray2D(A, B, rowsize, colsize);
  printf("Copy2DArray:\n");
  DisplayArray2D(B, rowsize, colsize);

  printf("\n");
  CopyArray2DSpiral(A, B, rowsize, colsize);
  printf("Copy2DArraySwirl:\n");
  DisplayArray2D(B, rowsize, colsize);

  printf("-- end run --\n");

  return 0;
}

//PopulateArray2DUnique: Populates an array with 0 and then random unique numbers
//Input: A/Array, rowsize/The number of rows, colsize/Number of columns, min/ Minimum number to generate, max/ Maximum number to generate
//Outout: Void, populates array
void PopulateArray2DUnique (int A[][COL], unsigned int rowsize, unsigned int colsize, int min, int max)
{
  int number;
  srand(time(NULL));

  for(int i=0; i < rowsize; i++)
  {
    for(int j=0; j < colsize; j++)
    {
      A[i][j]=0;
    }
  }

  int flag=0;

  for(int i=0; i < rowsize; i++)
  {
    for(int j=0; j < colsize; j++)
    {
      for(;;) {
        if(flag==0)
        {
          number = rand()%(max-min+1)+min;
          flag = Check(A, number, rowsize, colsize);
        }

        else
        {
          A[i][j] = number;
          flag = 0;
          break;
        }
      }
    }
  }

}

//check: Checks if a generated number is unique
//Input: A/Array, number/The random number in question, rowsize/The number of rows, colsize/The number of columns
//Output: determines if the number is uniques (1) or not(0)
int Check(int A[][COL], int number, unsigned int rowsize, unsigned int colsize)
{
  for(int i=0; i < rowsize; i++)
  {
    for(int j=0; j < colsize; j++)
    {
      if(number == A[i][j])
      {
        return 0;
      }
    }
  }
  return 1;
}

//DisplayArray2D: Prints the array in a visual representation
//Input: A/Array, rowsize/The number or rows, colsize/The number of columns
//Output: Void, Prints the array
void DisplayArray2D(int A[][COL], unsigned int rowsize, unsigned int colsize)
{
  for(int i=0; i<rowsize; i++)
    {
      for(int j=0; j<colsize; j++)
      {
        printf("%d\t", A[i][j]);
      }
      printf("\n");
    }
}

//FindLargest: Find the largest number in the array
//Input: A/The columns, rowsize/The number of rows, colsize/ The number of columns
//Output: The largest number
int FindLargest(int A[][COL], unsigned int rowsize, unsigned int colsize)
{
  int largest = 0;

  for(int i=0; i<rowsize; i++)
  {
    for(int j=0; j<colsize; j++)
    {
      if(A[i][j]>largest)
      {
        largest = A[i][j];
      }
    }
  }

  return largest;
}

//FindColSum: Find the sum of a columns elements
//Input: A/Array, rowsize/ The number of rows, colsize/ The number of columns, col_to_sum/ the column being sumed
//Output: the sum of the chosen column
int FindColSum(int A[][COL], unsigned int rowsize, unsigned int colsize, unsigned int col_to_sum)
{
  int sum;

  for (int i=0; i < rowsize; i++)
  {
    sum += A[i][col_to_sum-1];
  }

  return sum;
}

//Sort2DArray: Sorts the array elements in increasing order
//Input: A/Array, rowsize/The number of columns, colsize/The number of columns
//Output: a value based on if the rowsize/column size is within range or not
int Sort2DArray(int A[][COL], unsigned int rowsize, unsigned int colsize)
{
  int temp;

  if(colsize > 20 || rowsize > 20 || colsize == 0 || rowsize == 0)
  {
    return -1;
  }

  else
  {
    for(int counter=0; counter < (rowsize*colsize);)
    {

      for(int i=0;i < rowsize; i++)
      {
        for(int j=0; j < colsize; j++)
        {
          if(j == colsize - 1 && i == rowsize - 1) {
            continue;
          }
          if (j == colsize - 1 && i != rowsize - 1 )
          {
            if(A[i+1][0] < A[i][j])
            {
              temp = A[i+1][0];
              A[i+1][0]=A[i][j];
              A[i][j]=temp;
              counter = 0;
            }
          }
          else
          {
            if(A[i][j] > A[i][j+1])
            {
              temp = A[i][j+1];
              A[i][j+1]=A[i][j];
              A[i][j]=temp;
              counter = 0;
            }
          }
          counter++;
        }
      }


    }
  }

  return 0;
}

//CopyArray2D: Copies array A to array B
//Input: A/Array A, B/Array B, rowsize/the number of rows, colsize/The number of columns
//Output:
int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize)
{
  for(int i=0; i<rowsize; i++)
  {
    for(int j=0; j<colsize; j++)
    {
      B[i][j] = A[i][j];
    }
  }

  return 0;
}

//CopyArray2DSpiral: copy array A to array B in a closewise spiral order
//Input: A/ Array A, B/Array B, rowsize/The number of rows, colsize/The number of columns
//Output: copies array A to array B in spiral formation
int CopyArray2DSpiral(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize)
{
  int top = 0, right = colsize - 1, bottom = rowsize - 1, left = 0, x = 0,y = 0;
  char direction = 'R';

  for(int i=0; i<rowsize; i++)
  {
    for(int j=0; j<colsize; j++)
    {
        B[i][j] = 0;
    }
  }

  //x = 0;

  for(int i = 0; i < rowsize; i++) {
    for(int j = 0; j < colsize; j++) {
        switch (direction)
        {
          case 'D':
            B[x][y] = A[i][j];
            if(x < bottom) {
              x++;
            }
            else {
              direction = 'L';
              y--;
              top++;
            }
            break;
          case 'L':
            B[x][y] = A[i][j];
            if (y > left) {
              y--;
            }
            else {
              direction = 'U';
              x--;
              left++;
            }
            break;
          case 'U':
            B[x][y] = A[i][j];
            if (x > top) {
              x--;
            }
            else {
              direction = 'R';
              y++;
              bottom--;
            }
            break;
          case 'R':
            B[x][y] = A[i][j];
            if (y < right) {
              y++;
            }
            else {
              direction = 'D';
              x++;
              right--;
            }
            break;
          }
        }
      }

  return 0;
}
