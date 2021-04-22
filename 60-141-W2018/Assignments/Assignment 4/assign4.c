//Author: Mohamad Elchami Date:Match 28th, 2018
//Assignment 4

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//tweet structure: Holds a complete tweet
struct tweet
{
  int id; // Hold the id of the tweet
  char created_at[51]; // Hold the time of the tweet
  char user[21]; //Hold the username
  char text[141]; // Hold the actual tweet content (text)
  struct tweet* ptrNext; // Use to point to the next structure
};

typedef struct tweet Tweet;

struct tweet *ptrFirst = NULL;
struct tweet *ptrLast = NULL;

//Prototypes
void LoadTweet(struct tweet* ptrF);
void newline(char *ptrnewline);
void AddToEnd(struct tweet* ptrPoint);
int isEmptyList(struct tweet* ptrF);
void SortTweet(struct tweet* ptrF);
void SaveTweet(struct tweet* ptrF);
void ResetList(struct tweet* ptrF);

int main()
{
  LoadTweet(ptrFirst);
  SortTweet(ptrFirst);
  SaveTweet(ptrFirst);
  ResetList(ptrFirst);

  printf("Complete.\n");

  return 0;
}

//LoadTweets: Loads tweets into structs from tweets.txt
//Input: pointer to ptrFirst
//Output: VOID
void LoadTweet(struct tweet* ptrF)
{
  //create file pointer
  FILE *fp;
  //Opens the file "tweets.txt" in read mode
  fp = fopen("tweets.txt", "r");

  //holds new line
  char temp[100];
  struct tweet* position;

  //Checks if the file is empty
  if(fp == NULL)
  {
    printf("The file is empty\n");
    return ;
  }

  //scans each tweet into a new struct
  while (fscanf(fp, "%s\n", temp) != EOF)
  {
    position = malloc(sizeof(struct tweet));

    //retreives the id
    position->id = atoi(temp);

    //retreives the time created
    fgets(position->created_at, 51, fp);
    newline(position->created_at);

    //retreives the username
    fgets(position->user, 21, fp);
    newline(position->user);

    //retreive the text
    fgets(position->text, 141, fp);
    newline(position->text);

    AddToEnd(position);
  }
fclose(fp);//closes the file
printf("Tweets Loaded.\n");
}

//NewLine: removes the newline character from inputs
//Input: pointer to the current struct being read
//Output:VOID
void newline(char *ptrnewline)
{
  for( ; *ptrnewline != '\0'; ptrnewline++)
  {
    if(*ptrnewline == '\n')
    {
      *ptrnewline = '\0';
      break;
    }
  }
}

//AddToEnd: Adds the next tweet to a new struct
//Input: Pointer to the current struct
//Output: VOID
void AddToEnd(struct tweet* ptrPoint)
{
  if(ptrPoint == NULL)
  {
    printf("Out of memory.\n");
  }

  else
  {
    if(ptrFirst == NULL)
    {
      ptrFirst = ptrPoint;
      ptrLast = ptrPoint;
    }

    else
    {
      struct tweet* ptrNavi = ptrFirst;

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

//SortTweet: Alphabetically sorts tweets based off username
//Input: Pointer to ptrFirst
//Output: VOID
void SortTweet(struct tweet* ptrF)
{
  int empty;
  struct tweet* position;

  //checks if the list is empty
  empty = isEmptyList(ptrFirst);

  //if empty then display this msg
  if(empty == 0)
  {
    printf("List is empty.\n");
  }

  else
  {
    int swap;

    //allocated memory for temp struct
    struct tweet *temp = malloc(sizeof(struct tweet));
  	do
    {
		swap = 0;
		position = ptrFirst;
  	while(position != NULL) {
			if(position->ptrNext == NULL)
			{
				break;
			}
			if(strcmp(position->user , position->ptrNext->user) > 0)
			{
			  //moves first struct to temp
			  temp->id = position->id;
			  strcpy(temp->created_at, position->created_at);
			  strcpy(temp->user, position->user);
			  strcpy(temp->text, position->text);

			  //moves second struct into First
			  position->id = position->ptrNext->id;
			  strcpy(position->created_at,position->ptrNext->created_at);
			  strcpy(position->user, position->ptrNext->user);
			  strcpy(position->text, position->ptrNext->text);

			  //moves temp struct to second struct
			  position->ptrNext->id = temp->id;
			  strcpy(position->ptrNext->created_at, temp->created_at);
			  strcpy(position->ptrNext->user, temp->user);
			  strcpy(position->ptrNext->text, temp->text);

			  swap = 1;
			}
			position = position->ptrNext;
		}
	} while(swap != 0);

    //free temp stuct from memory
    free(temp);
  }
  printf("Sort Complete.\n");
}

//isEmptyList: Checks if the list is empty
//Input: pointer to ptrFirst
//Output: 0 if empty, 1 is not empty
int isEmptyList(struct tweet* ptrF)
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

//SaveTweet: Saves the tweets back to the file overwriting it
//Input: pointer to prtFirst
//Output: VOID
void SaveTweet(struct tweet* ptrF)
{
  FILE *fp;
  //opens the file "tweets.txt" in write mode
  fp = fopen("tweets.txt", "w");

  struct tweet *position = ptrFirst;

  do
  {
    fprintf(fp, "%d\n%s\n%s\n%s\n", position->id, position->created_at, position->user, position->text);
    position = position->ptrNext;
  }while(position != NULL);
  printf("Tweets Saved.\n");
}

//ResetList: Resets the list and frees the memory
//Input: pointer to ptrFirst
//Output: VOID
void ResetList(struct tweet* ptrF)
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
