// Author: Mohamad Elchami Date: September 26th Description: Calulates the volume of a sphere with a given radius //

#include <stdio.h>

int main(void)
{
  int radius;
  float volume, pi;

  radius = 10;
  pi = 3.141592;
  volume = 4.0f/3.0f * pi * radius * radius * radius;

  scanf("%d%f", &radius, &volume);
  printf("A volume of sphere with %d - meter radius is %f\n", radius, volume);

  return 0;
}
