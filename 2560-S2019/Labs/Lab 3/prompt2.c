#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

enum State{ R_OKAY = 0, R_EXIT = -1, R_ERROR = -2 };

int prompt(const char * ps, int (*handler)(const char *));
int handler (const char *string);

int main(int argc, char * argv[]){
  for(int i=0; i<4; i++){
    prompt("ps ", &handler);
    printf("\n");
  }



}

int prompt(const char * ps, int (*handler)(const char *)){
  char str[80];
  scanf("%s", str);
  (*handler)(str);
  return 0;
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
  else if(strcmp(string,"broken") == 0){
    printf("Error: Uknown Command BROKEN");
    return R_ERROR;
  }
  else{
    return R_ERROR;
  }

}
