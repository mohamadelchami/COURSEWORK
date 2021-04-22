#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

enum State{ R_OKAY = 0, R_EXIT = -1, R_ERROR = -2 };

int prompt(const char * ps, int (*handler)(const char *));
int handler (const char *string);

int main(int argc, char * argv[]){
  int runcode = prompt("ps ", &handler);
  printf("\n");

  return printf("%d",runcode);
}

int prompt(const char * ps, int (*handler)(const char *)){
  printf("%s", ps);
  char str[80];
  scanf("%s", str);
  return (*handler)(str);
}

int handler (const char *string){

  if(strcmp(string,"pid") == 0){
    printf("%d",getpid());
    return R_OKAY;
  }
  else if(strcmp(string,"uid") == 0){
    printf("%d", getuid());
    return R_OKAY;
  }
  else if(strcmp(string,"exit")== 0){
    return R_EXIT;
  }
  else if(strcmp(string,"*") == 0){
    printf("Error: Uknown Command *");
    return R_ERROR;
  }
  else{
    return R_ERROR;
  }

}
