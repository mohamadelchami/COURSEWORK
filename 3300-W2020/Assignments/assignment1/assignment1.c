#include <stdio.h>
#include <stdlib.h>

int main(){

  FILE *fptRead, *fptWrite; //Open pointers to 2 files: fptRead = Reading file  fptWrite = Writing file
  char fileReadName[100], fileWriteName[100], c; //100 but Char array of file names and a singl but char variable to store a character when reading

  int choice = 0; //Used for switch cases
  int valid = 0; //Used to loop for valid input
    
  //Loop until a valid input is given or user chooses to exit
  while(valid == 0){
    printf("Enter the name of the file you would like to open: ");
    scanf("%s", fileReadName);

    fptRead = fopen(fileReadName, "r"); //Open the read file in Read-mode

    //if the file is NULL then the file has not opened
    if(fptRead == NULL){
      printf("File does not exist.\n Would you like to:\n 1. Provide a new name\n 2. Exit the program\n"); //prompt users for options
      printf("Enter Command: ");
      scanf("%d", &choice);
      //user input is taken and considered
      switch(choice){
        case 1: valid = 0;
                break;
        case 2: exit(1);
        default: exit(1);
      }
    }
    //the file != NULL, hence the file was open
    else{
      printf("The file has been opened.\n");
      valid = 1;
    }
  }

  valid = 0; //reset loop condition

  printf("Enter the name of the new or existing file you wish to copy to: ");
  scanf("%s", fileWriteName);

  fptWrite = fopen(fileWriteName, "w"); //open/create the write file in Write-Mode

  //Loop until a valid input is given or user chooses to exit
  while(valid == 0){
    //if the file is NULL then the file has not opened
    if(fptWrite == NULL){
      printf("File was not created.\n Would you like to:\n 1. Provide a new name\n 2. Exit the program\n"); //prompt users for options
      printf("Enter Command: ");
      scanf("%d", &choice);
      //user input is taken and considered
      switch(choice){
        case 1: valid = 0;
                break;
        case 2: exit(1);
        default: exit(1);
      }
    }
    //the file != NULL, hence the file was open
    else{
      printf("The file has been created.\n");
      valid = 1;
    }
  }

  c = fgetc(fptRead); //Read a single character into c from the read file
  //Cucle thorugh all the characters until you reach EOF(End of file)
  while (c != EOF){
    fputc(c, fptWrite); //write that character into the write file
    c = fgetc(fptRead);
  }

  //if c == EOF then the contents have all been copied completely, prompt user
  if(c == EOF){
    printf("All contents have been copied from %s into %s\n", fileReadName, fileWriteName);
  }
  //if c!=EOF then the contents have not been completely copied, prompt user
  else{
    printf("Contents have failed to copy.\n");
  }

  //Close the files
  fclose(fptRead);
  fclose(fptWrite);

  //close
  return 0;
}
