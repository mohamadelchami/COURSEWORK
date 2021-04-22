#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <math.h>

#define NUMBER_OF_THREADS 2

//prototypes
void *runner(void *param);
double random_double();


int circles = 0;


int main(int argc, const char *argv[]){
  int NUMBER_OF_POINTS;
  printf("Enter the number of points: ");
  scanf("%d", &NUMBER_OF_POINTS);
  
  int i;
  double Pi; //value of pi
  int ppt = NUMBER_OF_POINTS/NUMBER_OF_THREADS; //points per thread
  pthread_t workers[NUMBER_OF_THREADS];

  //random number generation
  srandom((unsigned)time(NULL));
  clock_t begin = clock(); //begin the clock
  for(i=0 ; i < NUMBER_OF_THREADS ; i++){
    pthread_create(&workers[i], 0, runner, &ppt);
  }
  for(i=0 ; i < NUMBER_OF_THREADS ; i++){
    pthread_join(workers[i], NULL);
  }

  //calculate Pi
  Pi = (4.0 * circles) / NUMBER_OF_POINTS;
  clock_t end = clock(); //end clock
  double time = (double)(end-begin)/CLOCKS_PER_SEC; // calculate the time taken

  //print all values
  printf("Number of point: %d \n", NUMBER_OF_POINTS);
  printf("Pi = %f \n", Pi);
  printf("Time spent: %f \n", time);

  return 0;
}

double random_double(){
return random() / ((double)RAND_MAX + 1);
}

void *runner(void *param){
  int i=0;
  int PTS = *((int*) param);
  int hit_count = 0;
  double x, y;

  for(i=0 ; i < PTS ; i++){
    x = random_double() * 2.0 - 1.0;
    y = random_double() * 2.0 - 1.0;

    if ( sqrt(x*x + y*y) < 1.0 ){
      ++hit_count;
    }
  }

  circles += hit_count;
  pthread_exit(0);
}
