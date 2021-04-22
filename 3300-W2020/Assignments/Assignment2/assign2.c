#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  pid_t pid = fork();

  if(pid > 0){
    printf("Parent process: %d \n", getpid());
    sleep(10);
  }
  else if (pid == 0){
      printf("Child procesd: %d \n", getpid());
  }
  else{
    printf("Proccess failed.");
    return -1;
  }

  return 0;
}
