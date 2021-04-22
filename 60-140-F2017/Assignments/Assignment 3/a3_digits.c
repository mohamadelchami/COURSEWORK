//Author: Mohamad Elchami Date: November 2nd, 2017 Discription: shows the reverse a of a number that contains 3 or more digits
#include <stdio.h>
#include <math.h>

int main(void)
{
  int number, remain, reverse;

  printf("Enter a number: ");
  scanf("%d", &number);

  if(number < 0)
  {
    printf("Invalid input!\n");
  }

  else if(number <= 99)
  {
    printf("No need to reverse the number.\n");
  }

  else
  {
    reverse = 0;
    do {
    remain = number%10;
    reverse = reverse * 10 + remain;
    number /= 10;
    } while(number > 0);

    printf("The reverse is: %d\n", reverse);
  }

  printf("Thank you for using the software.\n");

  return 0;
}
