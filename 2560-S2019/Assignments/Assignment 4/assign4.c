#include <stdlib.h>
#include <stdio.h>

#define MAX_DEPTH 5
int depth = 0;

unsigned long sp(void)
{
  __asm__("movq %rsp, %rax");
}

void f(void)
{
  int i =5;
  if(++depth < MAX_DEPTH){
    printf("%d \n", sp());
    f();
    printf("%d \n", sp());

    printf("Address of local: %d\n", &i);
    printf("Address of Global: %d\n", &depth);

    char *x = malloc(500 * sizeof(char));
    printf("Malloc 1: %d\n", &x);
    char *y = malloc(500 * sizeof(char));
    printf("Malloc 2: %d\n", &y);
  }
}

int main (){
  f();

  return 0;
}
