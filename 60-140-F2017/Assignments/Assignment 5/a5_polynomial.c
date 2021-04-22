// Author: Mohamad Elchami Date: November 30th, 2017

#include<stdio.h>
#include<math.h>

float polynomial(x)
{
  float solution;

  solution = 3*pow(x,5) + 2*pow(x,4) - 5*pow(x,3) - pow(x,2) + 7*(x) -6;

  return (solution);
}

int main(void)
{
  int x;

  printf("Enter value of x: ");
  scanf("%d", &x);

  printf("%f\n", polynomial(x));

  return 0;
}
