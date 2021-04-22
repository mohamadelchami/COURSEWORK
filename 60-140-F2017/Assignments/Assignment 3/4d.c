#include <stdio.h>
#include <math.h>

int main(void)
{
  float x;

  for ( x = 10.0; x > 1.001; x = sqrt(x))
  {
    printf("%.4f ", x);
  }


return 0;
}
