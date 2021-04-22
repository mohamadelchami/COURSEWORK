#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  //variables to hold information
  unsigned long page;
  unsigned long offset;
  unsigned long address;
  unsigned long addressSpace;

  //check if a power of 2
  if(check_address(atoll(argv[1])) == 1){
    //store the first arguement from a string to long
    addressSpace = atoll(argv[1]);
  }

  //check if a power of 2
  if(check_power(atoll(argv[2])) == 1){
    //store the second arguement from a string to long
    page = atoll(argv[2]);
  }

  //Store the third arguement from a string to long
  address = atoll(argv[3]);
  offset = address & 0xfff;

  //print information
  printf("The address %lu contains: \n", address);
  printf("The address space = %lu\n", addressSpace);
  printf("Page number = %lu\n", page);
  printf("Offset = %lu\n", offset);
}


//check_power
//input: unsinged long
//output/return: 0 if not a power of 2, 1 if a power of 2
int check_power(unsigned long i){
  if(i == 0){
    return 0;
  }

  else{

    while(i != 1){

      if(i % 2 != 0){
        return 0;
      }

      else{
        if(i % 2 != 0)
         return 0;
         i /= 2;
      }

    }

    return 1;
  }
}

int check_address(unsigned long i){
  if(i == 16 || i == 32 || i == 64){
    return 1;
  }
  else{
    return 0;
  }
}
