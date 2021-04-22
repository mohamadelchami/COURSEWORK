// Authur: Mohamad Elchami Date: October 3rd, 2017 Description: Computes the volume of a cylinder //
#include<stdio.h>
#include<math.h>
#define M_Pi 3.14159265358979323846

int main(void)
{
  float volume, radius, height;

  printf("Enter radius and height (r,h): ");
  scanf("%f,%f", &radius, &height);
    if(radius<2)
    {
      printf("Radius cannot be smaller than 2.\n");
    }
    else if (height<radius)
    {
      printf("Height has to be bigger than radius.\n");
    }
    else
    {
      volume = M_Pi*pow(radius,2)*height;
      printf("The volume is %.2f\n", volume);
    }

  return 0;

}
