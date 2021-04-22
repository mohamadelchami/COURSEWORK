// Author: Mohamad Elchami Date: November 27th, 2017

#include<stdio.h>
double calculateCharges(float a[3][2]);

int main(void)
{
  float a[3][2];
  double y=0, z=0;

  //input
  printf("Enter the hours parked for 3 cars: ");
  scanf("%f %f %f", &a[0][0], &a[1][0], &a[2][0]);

  // prints first row
  printf("Car\t Hours\t Charge\n");

  y= calculateCharges(a);
  z = z + a[0][0]+a[1][0]+a[2][0];

  printf("TOTAL\t %.1lf\t %.2lf \n", z, y);
}

double calculateCharges(float a[3][2])
{
  double y=0;

  for(int x=0; x < 3; x++)
  {
    if(a[x][0] <= 3)
    {
      a[x][1]=2.00;
    }

    else if(a[x][0]>=19)
    {
      a[x][1]= 10.00;
    }

    else
    {
      a[x][1] = ((a[x][0]-3)*0.5)+2;
    }
    printf("%d\t %.1f\t %.2f \n", x+1, a[x][0], a[x][1]);
    y = y+a[x][1];
  }

  return (y);
}
