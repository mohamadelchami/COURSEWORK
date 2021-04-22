#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <math.h>

#define NUMBER_OF_POINTS 1000000
#define NUMBER_OF_THREADS 1


pthread_mutex_t mutex;

//prototypes
void *runner(void *param);
double random_double();

double Pi;
int circles = 0;

int main(int argc, const char *argv[]){

  int NUMBER_OF_SLAVES;
  printf("Enter the number of slaves: ");
  scanf("%d", &NUMBER_OF_SLAVES);

  int i;
  int ppt = NUMBER_OF_POINTS/NUMBER_OF_THREADS; //points per thread
  pthread_t workers[NUMBER_OF_THREADS];

  pthread_mutex_init(&mutex, NULL);

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
  printf("Number of slaves: %d \n", NUMBER_OF_SLAVES);
  printf("Pi = %f \n", Pi);
  printf("Time spent: %f \n", (time*4)/NUMBER_OF_SLAVES);

  Pi = 0;
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
  pthread_mutex_lock(&mutex);
  circles += hit_count;
  pthread_mutex_unlock(&mutex);
  pthread_exit(0);
}
