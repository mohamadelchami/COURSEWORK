//Author: Mohamad Elchami
//Date: Feb. 12th, 2018
//Description: Pointer Practice

// I added a new line after each print statement for easier viewing in execrution

#include <stdio.h>

int main()
{
  int a = 7;
  int *aPtr;
  aPtr = &a;

  // prints the location of a in hexadecimal code
  printf("%p\n", &a);

  // prints the location of a in hexadecimal code
  printf("%p\n", aPtr);

  // Prints the location of the pointer in hexadecimal code
  printf("%p\n", &aPtr);

  //Prints the value of the variable in decimal
  printf("%d\n", a);

  //prints the value of the pointer aPtr in decimal
  printf("%d\n", *aPtr);

  //prints the address of the a varabile in hexadecimal
  printf("%p\n", *&aPtr);

  //prints the address of the varibale in hexadecimal
  printf("%p\n", &*aPtr);

  //prints the value of the A variable in decimal
  printf("%d\n", *&a);

  //printf("%d\n", &*a); a is not a pointer

  return 0;
}
