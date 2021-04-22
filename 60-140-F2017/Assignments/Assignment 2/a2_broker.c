/* Author: Mohamad Elchami
   Date: October 15th, 2017
   Description: Calculates the commission of two competing brokers */

#include <stdio.h>
#include <math.h>

int main(void)
{
  int ns;
  float pps, value, rival, commission;

  printf("Enter the number of shares: ");
  scanf("%d", &ns);

  printf("Enter price per share: ");
  scanf("%f", &pps);

  value = ns*pps;

  rival = ns<2000 ? 33.00f+0.03f*ns : 33.00f+0.02f*ns;

  printf("Rival Commission:%.02f\n", rival);

  if(value<2500)
  {
    commission=30.00f+0.017f*value;
  }

  else if(value<6250)
  {
    commission=56.00f+0.0066f*value;
  }

  else if(value<20000)
  {
    commission=76.00f+0.0034f*value;
  }

  else if(value<50000)
  {
    commission=100.00f+0.0022f*value;
  }

  else if(value<500000)
  {
    commission=155.00f+0.0011f*value;
  }

  else
  {
    commission=255.00f+0.0009f*value;
  }

  if(commission<39.00)
  {
    commission=39.00f;
  }

  printf("Commission:$%.02f\n", commission);

return 0;

}
