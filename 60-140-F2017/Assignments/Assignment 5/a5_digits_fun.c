// Author: Mohamad Elchami Date: November 30th, 2017

#include<stdio.h>

int num_digits(number)
{
  int counter=0;
  while (number != 0)
  {
    number /= 10;
    counter++;
  }
  return (counter);
}

int main(void)
{
  int number;

  printf("Enter a number: ");
  scanf("%d", &number);

  printf("The number of digits is: %d\n", num_digits(number));

  return 0;
}
