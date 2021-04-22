#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main(int argc, char *argv[]){
  unsigned long page;
  unsigned long offset;
  unsigned long address;

  //set the minimum and maximum for random generation of address
  unsigned int min = 0;
  unsigned long max = pow(2,32) - 1;

  //Loop controller
  unsigned long n = 1000000;

  srandom((unsigned) time(NULL));

  //for CPU time calculation
  clock_t begin, end;
  double time;

  //capture startinh time
  begin = clock();

  //Loop until i  == n
  for(unsigned long i = 0; i < n; ++i){

    //generate a random address between min and max
    address = rand() % (min-max+1) + min;
    page = address >> 12;
    offset = address & 0xfff;

  }

  //capture ending time
  end = clock();

  //calculate CPU run time
  time = (double) (end-begin)/CLOCKS_PER_SEC;

  //print runtime to screen
  printf("Total CPU time: %f\n", time);

}
