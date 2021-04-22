//Assignment 3
//Name: Mohamad Elchami Date: March 21st, 2018

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_TWEETS 100 // max amount of tweets allowed to input

struct tweet
{
  int id;
  char created_at[51];
  char text[141];
  char user[21];
};

typedef struct tweet Tweet;

//prototypes
void createtweet(Tweet tweetary[], char username[], int ID, int numberoftweets);
void searchtweet(Tweet tweetary[], int numberoftweets);
void displaytweet(Tweet tweetary[], int numberoftweets);
void savetweet(Tweet tweetary[], int numberoftweets);
int loadtweet(Tweet tweetary[]);
void newline(char *ptrnewline);

int main()
{
  int ID = 1000; //keeps track of tweet id
  int numberoftweets = 0; //keeps track of amount of tweets
  int loadreturn = 0; //return value form the loadtweet fucntion
  int menu = 0;
  Tweet tweetary[MAX_TWEETS];
  printf("\n----------------------------Welcome to Simple Twitter----------------------------\n");

  //ask for username and store it in local variable
  //This will pass the username into the struct of each tweetary element when a tweet it created
  char username[21];
  printf("Please enter your user name: ");
  scanf("%[^\n]", username);
  printf("Welcome %s, let's start tweeting... \n\n", username);


  for(int i = 0 ; i == 0 ; )
  {
    printf("========================== Main Menu =================================\n");
    printf("| 1. Create a new tweet                                              |\n");
    printf("| 2. Search tweets                                                   |\n");
    printf("| 3. Display Tweets                                                  |\n");
    printf("| 4. Save tweets to file                                             |\n");
    printf("| 5. Load tweets from file                                           |\n");
    printf("| 6. Exit                                                            |\n");
    printf("======================================================================\n");

    printf("\nEnter a command: ");
    scanf("%d", &menu);

    switch(menu)
    {
      case 1: printf("========================= Create a New Tweet =========================\n");
              createtweet(tweetary, username, ID, numberoftweets);

              ID++; // increments the id
              numberoftweets++; // increments the total number of tweets

              printf("======================================================================\n");
              break;

      case 2: printf("=========================== Search Tweets ============================\n");
              searchtweet(tweetary, numberoftweets);
              printf("======================================================================\n");
              break;

      case 3: printf("=========================== Display Tweets ===========================\n");
              displaytweet(tweetary, numberoftweets);
              printf("======================================================================\n");
              break;

      case 4: printf("======================== Save Tweets to File =========================\n");
              savetweet(tweetary, numberoftweets);
              printf("======================================================================\n");
              break;

      case 5: printf("======================= Load Tweets from a File ======================\n");
              loadreturn = loadtweet(tweetary);

              ID += loadreturn; //continues the ID
              numberoftweets += loadreturn; // continues the number of tweets

              printf("======================================================================\n");
              break;

      case 6: i = 1;
              break;
    }

  }

  printf("Terminated.\n");

  return 0;
}

//createtweet: Asks user to input tweet and saves tweet
//Input: Pointer to the tweetary array
//Output: Adds a new tweet
void createtweet(Tweet tweetary[], char username[], int ID, int numberoftweets)
{
  printf("Enter a tweet: ");
  scanf(" %[^\n]", tweetary[numberoftweets].text);
  printf("New tweet created.\n\n");

  tweetary[numberoftweets].id = ID; //copies the current id into the struct within the element

  //calculates the time
  struct tm *currenttime;
  time_t thetime;
  time(&thetime);
  currenttime = localtime(&thetime);
  //removes the newline character from the end of the time string.
  char *ttime = asctime(currenttime);
  ttime[strlen(asctime(currenttime))-1] = '\0';


  strcpy(tweetary[numberoftweets].created_at, ttime); //copies the time string into the struct of the current element

  strcpy(tweetary[numberoftweets].user, username); //copies the username string into the struct of the current element

  //prints the newly created tweet
  for(int i = numberoftweets; i == numberoftweets; i++)
  {
    printf("id: %d\t Created at: %s\t by: %s\n%s\n\n", tweetary[i].id, tweetary[i].created_at, tweetary[i].user, tweetary[i].text);
  }

}

//searchtweet: Searches for a keyword in tweets
//Input: The tweetary array
//Output: The tweet containing the keyword printed to screen
void searchtweet(Tweet tweetary[], int numberoftweets)
{
  //keep track of how many tweet are found
  int counter = 0;

  //takes keyword input from the user
  char keyword[141];
  printf("Please enter the search keyword: ");
  scanf("%s", keyword);

  printf("\n");

  //checks tweets for keyword
  for(int i = 0; i < numberoftweets; i++)
  {

    //tests if the keyword is in the tweetary element
    if(strstr(tweetary[i].text, keyword))
    {
      printf("Found match:\n");
      printf("id: %d\t Created at: %s\t by: %s\n%s\n\n" ,tweetary[i].id, tweetary[i].created_at, tweetary[i].user, tweetary[i].text);
      counter++;
    }
  }

  //number of tweets found
  printf("Found %d tweets matching the criteria.\n", counter);
}

//displaytweet: Displays all the tweets
//Input: The tweetary array
//Output: Prints all the tweets onto the screen
void displaytweet(Tweet tweetary[], int numberoftweets)
{
  //notifies the amount of tweets
  printf("Displaying all %d tweets.\n\n", numberoftweets);

  //loops thought the struce of each element, terminating when printing the current amount of tweets
  for(int i = 0; i < numberoftweets; i++)
  {
    printf("id: %d\t Created at: %s\tby: %s\n%s\n\n", tweetary[i].id, tweetary[i].created_at, tweetary[i].user, tweetary[i].text);
  }
}

//savetweet: Saves the tweets to an file "tweets.dat"
//Input: the tweetary array
//Output: Saves the current data into a file of the users choice
void savetweet(Tweet tweetary[], int numberoftweets)
{
  //used to store the filename
  char filename[100];
  //promots user for filename
  //use just the filename excluding .txt as that will be appended to the end of the filename buy the next line
  printf("Enter a filename: ");
  scanf(" %s", filename);

  //appentds .txt to the end of the filename
  strcat(filename,".txt");

  //opens the file in write mode
  FILE *fp;
  fp = fopen(filename, "w");

  //Loops thought the array elements copying the struct into the file
  for(int i = 0; i < numberoftweets; i++)
  {
    fprintf(fp, "\n%d\n%s\n%s\n%s", tweetary[i].id, tweetary[i].created_at, tweetary[i].user, tweetary[i].text);
  }

  fclose(fp); // closes the file

  printf("File created.\n"); //confirms termination
}

//loadtweet: Loads the tweets from the file "tweets.dat"
//Input:
//Output
int loadtweet(Tweet tweetary[])
{
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

  //Loops thought the file and passes the data into the struct of each array element
  int i=0;

  //holds new line
  char temp[100];

  //scans the first new line
  //fgets(temp, 100, fp);

  while (fscanf(fp, "%s\n", temp) != EOF)
  {
    tweetary[i].id = atoi(temp);

    fgets(tweetary[i].created_at, 51, fp);
    newline(tweetary[i].created_at);

    fgets(tweetary[i].user, 21, fp);
    newline(tweetary[i].user);

    fgets(tweetary[i].text, 141, fp);
    newline(tweetary[i].text);

    //fscanf(fp, "%d %s %s %s", &tweetary[i].id, tweetary[i].created_at, tweetary[i].user, tweetary[i].text);

    i++;
  }
  /*  while( !feof(fp) )
    {
      fscanf(fp, "%d %s %s %s", &tweetary[i].id, tweetary[i].created_at, tweetary[i].user, tweetary[i].text);
      i++;
    }
  */
  fclose(fp);//closes the file

  return i;
}

void newline(char *ptrnewline)
{
  for( ; *ptrnewline != '\0'; ptrnewline++)
  {
    if(*ptrnewline == '\n')
    {
      *ptrnewline = '\0';
    }
  }
}
