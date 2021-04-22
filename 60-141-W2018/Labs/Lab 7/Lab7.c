//Author: Mohamad Elchami Date: March 23rd, 2018 Description: Lab 7

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//structure
struct point
{
 int x;
 int y;
 char label[21];
 struct point *ptrNext;
 struct point *ptrPrevious;
};

//prototypes
int isEmptyList(struct point *ptrF);
void PrintList(struct point *ptrF);
void ResetList(struct point *ptrF);
void AddToBeginning(struct point *ptrF, struct point *ptrL);
void AddToEnd(struct point *ptrF, struct point *ptrL);
struct point* InputRecord(void);
void SaveList(struct point *ptrF);
void ReadList(void);


struct point *ptrFirst = NULL;
struct point *ptrLast = NULL;

int main()
{
  int menu;

  for(int i = 0 ; i == 0 ; )
  {
    printf("========================== Main Menu =================================\n");
    printf("| 1. Add a point at the END of the list.                             |\n");
    printf("| 2. Add a point at the BEGINNING of the list.                       |\n");
    printf("| 3. Is the list empty?                                              |\n");
    printf("| 4. Reset list.                                                     |\n");
    printf("| 5. Display List.                                                   |\n");
    printf("| 6. Save the list to a sequential file.                             |\n");
    printf("| 7. Read the list back from a sequential file.                      |\n");
    printf("| 8. Exit.                                                           |\n");
    printf("======================================================================\n");

    printf("\nEnter a command: ");
    scanf("%d", &menu);
    getchar();

    switch(menu)
    {
      case 1: printf("================= Add a point at the END of the list =================\n");
              AddToEnd(ptrFirst, ptrLast);
              printf("======================================================================\n");
              break;

      case 2: printf("============= Add a point at the BEGINNING of the list. ==============\n");
              AddToBeginning(ptrFirst, ptrLast);
              printf("======================================================================\n");
              break;

      case 3: printf("========================= Is the list empty? =========================\n");
              int empty;
              empty = isEmptyList(ptrFirst);

              if(empty == 0)
              {
                printf("List is empty.\n");
              }

              else
              {
                printf("List is not empty. \n");
              }
              printf("======================================================================\n");
              break;

      case 4: printf("============================ Reset list. =============================\n");
              ResetList(ptrFirst);
              ptrFirst = NULL;
              ptrLast = NULL;
              printf("List Reset.\n");

              printf("======================================================================\n");
              break;

      case 5: printf("============================ Display List. ===========================\n");
              PrintList(ptrFirst);
              printf("======================================================================\n");
              break;

      case 6: printf("================ Save the list to a sequential file. =================\n");
              SaveList(ptrFirst);
              printf("======================================================================\n");
              break;

      case 7: printf("============= Read the list back from a sequential file. =============\n");
              ReadList();
              printf("======================================================================\n");
              break;

      case 8: i = 1;
              break;
    }
  }

  //free memory before termination


  printf("Program Terminated.\n");
}

//AddToBeginning: Adds a new point to the beginning of the List
//Input: Pointer ot the struct first and last
//Output: VOID
void AddToBeginning(struct point *ptrF, struct point *ptrL)
{
  struct point* ptrPoint = InputRecord();

  struct point* ptrPosition = ptrFirst;

  ptrFirst = ptrPoint;
  ptrFirst->ptrNext = ptrPosition;

}

//AddToEnd: Adds a point to the end of the list
//Input: Point to the first point and last point
//Output: VOID
void AddToEnd(struct point *ptrF, struct point *ptrL)
{

  struct point* ptrPoint = InputRecord();

  if(ptrPoint == NULL)
  {
    printf("Out of memory.\n");
  }

  else
  {
    if(ptrFirst == NULL)
    {
      ptrFirst = ptrPoint;
    }

    else
    {
      struct point* ptrNavi = ptrFirst;

      while(ptrNavi->ptrNext != NULL)
      {
        ptrNavi = ptrNavi->ptrNext;
      }

      ptrNavi->ptrNext = ptrPoint;
      ptrNavi = ptrNavi->ptrNext;
      ptrNavi->ptrNext = NULL;
    }

  }

}

//isEmptyList: Checks of the list is empty
//Input: Pointer to the first point
//Output: If the list is empty(0) or not(1)
int isEmptyList(struct point *ptrF)
{
  if (ptrF == NULL)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

//ResetList: Clears the list of all record
//Input: Pointer to the first record
//Output: VOID
void ResetList(struct point *ptrF)
{
  if(ptrF != NULL)
  {
    ResetList(ptrF->ptrNext);
    free(ptrF);
  }
  else
  {
    return;
  }

}

//PrintList: Prints the list to the screen
//Input: Pointer to the first record
//Output: VOID
void PrintList(struct point *ptrF)
{
  if(ptrF != NULL)
  {
    printf("%d %d\t%s\n", ptrF->x, ptrF->y, ptrF->label);
    PrintList(ptrF->ptrNext);
  }

  else
  {
    return;
  }
}


//InputRecord: Ask user for a record to input
//Input: Pointer
//Output: void
struct point* InputRecord(void)
{
  struct point* ptrPoint = malloc(sizeof(struct point));

  if (ptrPoint == NULL)
  {
    return ptrPoint;
  }

  else
  {
    printf("Enter a new record (20 characters max): ");
    scanf("%[^\n]", ptrPoint->label);

    printf("Enter the value of X: ");
    scanf("%d", &ptrPoint->x);

    printf("Enter the value of Y: ");
    scanf("%d", &ptrPoint->y);

    return ptrPoint;
  }

}

//SaveList: Creates a file and saves the data into it
//Input: pointer to ptr first
//Output:
void SaveList(struct point *ptrF)
{
  //used to store the filename
  char filename[100];

  //promots user for filename
  //use just the filename excluding .txt as that will be appended to the end of the filename buy the next line
  printf("Enter a filename: ");
  scanf(" %s", filename);

  //appends .txt to the end of the filename
  strcat(filename,".txt");

  //opens the file in write mode
  FILE *fp;
  fp = fopen(filename, "w");

  //Loops throught the structures
  for(; ptrF != NULL; ptrF = ptrF->ptrNext)
  {
    fprintf(fp, "%d\t%d\t%s\n", ptrF->x, ptrF->y, ptrF->label);
  }

  fclose(fp); // closes the file

  printf("Data saved to file.\n"); //confirms termination
}

//ReadList: prints the list to the screen from the file
//Input: read from file
//Output: VOID
void ReadList(void)
{
  //reset the list before adding to the list from the file
  ResetList(ptrFirst);
  ptrFirst = NULL;
  ptrLast = NULL;

  //used to store the filename
  char filename[100];
  //promots user for filename
  //use just the filename excluding .txt as that will be appended to the end of the filename buy the next line
  printf("Enter a filename: ");
  scanf("%s", filename);

  //appentds .txt to the end of the filename
  strcat(filename,".txt");

  //opens the file in write mode
  FILE *fp;
  fp = fopen(filename, "r");

  //holds new line
  char temp[100];
  struct point* position;

  while (fscanf(fp, "%s\t", temp) != EOF)
  {
    position = malloc(sizeof(struct point));

    position->x = atoi(temp);

    fscanf(fp, "%d\t%s\n", &position->y, position->label);
    printf("safhiasiofhasif");

    //position = position->ptrNext;
    //sposition->ptrNext = NULL;
  }


fclose(fp);//closes the file

}
