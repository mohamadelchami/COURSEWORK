/* Athur: Mohamad Elchami
   Date: October 15th, 2017
   Description: Reverses the order of a given two-digit number */
#include <stdio.h>
#include <math.h>

int main(void)
{
int n, firstdigit, seconddigit;

printf("Enter a two-digit number: ");
scanf("%d", &n);

seconddigit = n%10;
firstdigit = floor(n/10);

printf("The reverse is: %d%d\n", seconddigit, firstdigit);

return 0;
}
