#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
  system("gcc assign2.c");
  system("./a.out &");
  puts("Current process: ");
  system("ps -l");
  puts("The parent id is:");
  system("ps -l | grep -w Z | tr - s U+0200 | cut -c 18-22");
  system("kill -9 $(ps -l | grep -w Z | tr - s U+0200 | cut -c 18-22)");
  puts("Exited.\n\n");
  puts("Updated list: ");
  system("ps -l");
  return 0;
}
