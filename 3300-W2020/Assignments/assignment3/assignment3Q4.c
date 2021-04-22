#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <math.h>
#include <omp.h>

#define NUMBER_OF_POINTS 1000000


int omp_get_num_procs(void);

double random_double();

int circles = 0;

int main(int argc, const char *argv[]){

  int NUMBER_OF_SLAVES;
  printf("Enter the number of slaves: ");
  scanf("%d", &NUMBER_OF_SLAVES);

  double Pi;

  srandom((unsigned)time(NULL));
  clock_t begin = clock();

#pragma omp parallel
{
  int i;
  int hit_count = 0;
  double x, y;

  for(i=0 ; i < NUMBER_OF_POINTS ; i++)
  {
    x = random_double() * 2.0 - 1.0;
    y = random_double() * 2.0 - 1.0;

    if ( sqrt(x*x + y*y) < 1.0 )
    {
      ++hit_count;
    }
  }

#pragma omp critical
    {
      circles += hit_count;
    }

  }

  Pi = (4.0 * circles) / (NUMBER_OF_POINTS*omp_get_num_procs());
  clock_t end = clock();
  double time = (double)(end - begin)/CLOCKS_PER_SEC;

  printf("Number of point: %d \n", NUMBER_OF_POINTS);
  printf("Number of slaves: %d \n", NUMBER_OF_SLAVES);
  printf("Pi = %f \n", Pi);
  printf("Time spent: %f \n", time/(1024 * NUMBER_OF_SLAVES));

  return 0;
}

double random_double(){
  return random() / ((double)RAND_MAX + 1);
}
