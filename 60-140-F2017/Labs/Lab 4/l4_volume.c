/* Author: Mohamad Elchami Date: October 16th, 2017 Description: Calculates the volume with a given height that is greater than the radius of 5 */

#include <stdio.h>
#include <math.h>

#define M_Pi 3.14159265358979323846

int main(void)
{
  int radius=5;
  float height, volume;

  //loop
  while(1)
  {
    printf("Enter height (0 to exit program): ");
    scanf("%f", &height);


    //height conditions
    if (height == 0) break;

    else if (height>radius)
    {
      volume = M_Pi * pow(radius,2) * height;
      printf("The volume is:%.02f\n", volume);
    }
    else
    {
      printf("Height needs to be bigger than radius (5.0).\n");
    }
  }

  printf("Thank you for using my software.\n");

  return 0;
}
