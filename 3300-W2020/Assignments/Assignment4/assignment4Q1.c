#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

  //initiate the variables to hold the information
  unsigned long page;
  unsigned long offset;
  unsigned long address;


  //convert the address input from string to unsigned long using atoll
  address = atoll(argv[1]);

  page = address >> 12;

  offset = address & 0xfff;

  //print the information to the screen 
  printf("The address %lu contains: \n", address);
  printf("Page number = %lu \n", page);
  printf("Offset = %lu\n", offset);
}
