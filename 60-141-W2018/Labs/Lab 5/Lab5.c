//Author: Mohamad Elchami Date: March 5th, 2018 Description: Sort a string in alphabetical order
//completed: March 13th, 2017


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<strings.h>
#include<ctype.h>

#define N 100

//Prototypes
void ParseSentence(char string[N]);
void Sort(char* StringRevisedp[N], int counter);
void Print(char* StringRevisedp[N], int counter);

//main
int main()
{
  char string[N];

  printf("Enter a Sentence: ");
  scanf("%[^\n]", string);

  ParseSentence(string);

  return 0;
}

//ParseSentence: Takes a sentence and breaks it up into individual words
//Input: The string enetered by the user
//Output: The words printed individually
void ParseSentence(char string[N])
{
  char* StringRevised[N];

  int counter = 0;
  char *delimit;
  delimit = strtok(string, " ,;.");

  while(delimit != NULL)
  {
    StringRevised[counter] = delimit;
    counter++;
    delimit = strtok(NULL, " ,;.");
  }

  Sort(StringRevised, counter);
  Print(StringRevised, counter);
}

//Sort: Alphabetically sort the string
//Input: StringRevised, counter
//Output: Alphabetically ordered string
void Sort(char *StringRevised[N], int counter)
{

  int complete = 1;
  char *hold;
  short comp= 0;

  for( ; complete != 0 ; )
  {
    complete = 0;
    for(int i = 0 ; i < counter - 1 ; i++ )
    {

      comp = strcasecmp(StringRevised[i], StringRevised[i+1]);

      if(comp > 0)
      {
        hold = StringRevised[i+1];
        StringRevised[i+1] = StringRevised[i];
        StringRevised[i] = hold;
        complete = 1;
      }
    }
  }
}

void Print(char *StringRevised[N], int counter)
{
  for(int i = 0 ; i < counter ; i++ )
  {
    printf("%s\n", StringRevised[i]);
  }
}
