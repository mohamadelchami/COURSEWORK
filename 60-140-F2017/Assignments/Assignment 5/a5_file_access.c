// Author: Mohamad Elchami  Date: December 1st, 2017

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int prepareData(int pd)
{
  int num, fn;
  num = (rand()%10)+20;


  for( ; ; )
  {

  }

}

int obtainData(int od)
{

  for(int m=0 ; m != 15 || ;m++ )
  {
    printf("Item Number: ");
    scanf("%d", &a2d[0,m]);

    printf("Item name: ");
    scanf("%s",&a2d[1,m]);

    printf("\nUnit Price: ");
    scanf("%d", &a2d[2,m]);

    printf("\nPurchase Date: (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &a2d[3,m]);
  }

}

int printData(int prd)
{

  for( ; ; )

  {

  }

}

int monthDay(int md)
{
  int mon, day, ran;

  mon = (rand()*12)+1);

  if(mon==2)
  {
    day=28;
  }

  else
  {
    if(mon<8)
    {
      if(mon%2 != 1)
      {
        day=31;
      }

      else
      {
        day=30;
      }
    }
    else
    {
      if(mon%2 != 0)
      {
        day=30;
      }
      else
      {
        day=31;
      }
    }
  }
ran = (rand()*day)+1;
printf("%d\n", ran);

return (day);
}

int main(void)
{
  int a1d[15] = {0};
  int a2d[4,15] = {0};

  return 0;
}
