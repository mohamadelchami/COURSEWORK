// Name: Mohamad Elchami Date: Janurary 17th, 2018 Description: Calls fucntions based on users choice in the presented menu and following input

#include<stdio.h>
#include<math.h>

//protocals
int recursiveOne(int n); // int because it can return a negative number
unsigned int recursiveTwo(unsigned int m); //cant return a negative number
unsigned int recursiveThree(unsigned int m); //cant return a negative number
unsigned int recursiveFour(unsigned int m, unsigned int y); //wont return negative value
unsigned int recursiveFive(unsigned int m, unsigned int y); // wont return a negative value
unsigned int recursiveSix(unsigned int m); //wont return a negative number, stops at 1
unsigned int recursiveSeven(unsigned int m); // wont return a negative value
unsigned int recursiveEight(unsigned int m); // wont returen a negative value
int nonrecursiveOne(int n);
unsigned int nonrecursiveTwo(unsigned int m);
unsigned int nonrecursiveThree(unsigned int m);
unsigned int nonrecursiveFour(unsigned int m, unsigned int y);
unsigned int nonrecursiveFive(unsigned int m, unsigned int y);
unsigned int nonrecursiveSix(unsigned int m);
unsigned int nonrecursiveSeven(unsigned int m);
unsigned int nonrecursiveEight(unsigned int m);

int main(void)
{
  //Using short as the value they contain will be single digits
  short type, calc;

  //User inputs
  int n; // used for any int values
  unsigned int m, y; // used for unsigned int values

  //Function returns
  int sum;

  //Initially asks user is they want recursive or non-recursive before progressing to the next menu
  printf("=========================== Main Menu ===========================\n");
  printf("| Choose your type of fucntion:                                 |\n");
  printf("| 1. Recursive                                                  |\n");
  printf("| 2. Non-recursive                                              |\n");
  printf("=================================================================\n");
  printf("Enter command: ");
  scanf("%hd", &type);
  printf("\n");

  //The 2nd menu asking the user which fuction they would like to call
  printf("========================= Function Menu =========================\n");
  printf("| Which function would you like to call?                        |\n");
  printf("| 1. Sum                                                        |\n");
  printf("| 2. Squared Sum                                                |\n");
  printf("| 3. Fibonacci                                                  |\n");
  printf("| 4. Greatest Common Denominator                                |\n");
  printf("| 5. Exponent                                                   |\n");
  printf("| 6. Integer Counter                                            |\n");
  printf("| 7. Draw an Inverse Triangle                                   |\n");
  printf("| 8. Draw a Triangle                                            |\n");
  printf("=================================================================\n");
  printf("Enter command: ");
  scanf("%hd", &calc);
  printf("\n");

  //The initial menu option is tested and based on which path is taken direction is changed towards the respective switch statements and the second menu is tested
  //If main menu option 1 - Recursive
  if(type == 1)
  {
    switch(calc)
    {
      case 1:
        printf("============================== Sum ==============================\n");
        printf("Enter a digit: ");
        scanf("%d", &n);
        printf("The answer is: %d\n", recursiveOne(n));
        break;

      case 2:
        printf("========================== Squared Sum ==========================\n");
        printf("Enter a digit: ");
        scanf("%u", &m);
        printf("The answer is: %u\n", recursiveTwo(m));
        break;

      case 3:
        printf("=========================== Fibonacci ===========================\n");
        printf("Enter a number: ");
        scanf("%u", &m);
        printf("The answer is: %u\n", recursiveThree(m));
        break;

      case 4:
        printf("================== Greatest Common Denominator ==================\n");
        printf("Enter two digits (x,y): ");
        scanf("%u,%u", &m, &y);
        printf("The answer is: %d\n", recursiveFour(m, y));
        break;

      case 5:
        printf("=========================== Exponent ============================\n");
        printf("Enter two digits (base,exponent): ");
        scanf("%u,%u", &m, &y);
        printf("The answer is: %u\n", recursiveFive(m, y));
        break;

      case 6:
        printf("======================== Integer Counter ========================\n");
        printf("Enter an integer: ");
        scanf("%u", &m);
        printf("The answer is: ");
        printf("%u\n",recursiveSix(m));
        break;

      case 7:
        printf("=================== Draw an Inverse Triangle ====================\n");
        printf("Enter the number of * in the first row: ");
        scanf("%u", &m);
        recursiveSeven(m);
        break;

      case 8:
        printf("======================== Draw a Triangle ========================\n");
        printf("Enter command: ");
        printf("Enter the number of * in the last row: ");
        scanf("%u", &m);
        recursiveEight(m);
        break;

    }
  }

// if main menu option 2 - Non-Recursive
  else if(type == 2)
  {
    switch(calc)
    {
      case 1:
        printf("============================== Sum ==============================\n");
        printf("Enter a digit: ");
        scanf("%d", &n);
        printf("The answer is: %d\n", nonrecursiveOne(n));
        break;

      case 2:
        printf("========================== Squared Sum ==========================\n");
        printf("Enter a digit: ");
        scanf("%u", &m);
        printf("The answer is: %u\n", nonrecursiveTwo(m));
        break;

      case 3:
        printf("=========================== Fibonacci ===========================\n");
        printf("Enter a number: ");
        scanf("%u", &m);
        printf("The answer is: %u\n", nonrecursiveThree(m));
        break;

      case 4:
        printf("================== Greatest Common Denominator ==================\n");
        printf("Enter two digits (x,y): ");
        scanf("%u,%u", &m, &y);
        printf("The answer is: %u\n", nonrecursiveFour(m, y));
        break;

      case 5:
        printf("=========================== Exponent ============================\n");
        printf("Enter two digits (base,exponent): ");
        scanf("%u,%u", &m, &y);
        printf("The answer is: %u\n", nonrecursiveFive(m, y));
        break;

      case 6:
        printf("======================== Integer Counter ========================\n");
        printf("Enter an integer: ");
        scanf("%u", &m);
        printf("The answer is: ");
        nonrecursiveSix(m);
        break;

      case 7:
        printf("=================== Draw an Inverse Triangle ====================\n");
        printf("Enter the number of * in the first row: ");
        scanf("%u", &m);
        nonrecursiveSeven(m);
        break;

      case 8:
        printf("======================== Draw a Triangle ========================\n");
        printf("Enter command: ");
        printf("Enter the number of * in the last row: ");
        scanf("%u", &m);
        nonrecursiveEight(m);
        break;

    }
  }

  else
  {
    printf("Invalid input.");
  }

  return 0;
}


//==============================================================================
//|                            Recursive Functions                             |
//==============================================================================

//recursiveOne: recusively adds to digits until reaching the input digit
//INPUT: (n) The last digit in the squence
//OUTPUT: the sum(sum) of all the digits
int recursiveOne(int n)
{
  if (n == 0)
  {
    return 0;
  }

  else
  {
    return n + recursiveOne(n-1);
  }
}

//recursiveTwo: recusively adds terms with given input with decreasing (n) value
//INPUT: n, which determins the amount of terms
//OUTPUT: the sum of all those terms added together
unsigned int recursiveTwo(unsigned int m)
{
  int sum = 0;

  if(m != 0)
  {
    sum += pow((m+1),2);
    return recursiveTwo(m-1) + sum;
  }

  else
  {
    return  sum;
  }
}

//recursiveThree: Calculates the fibonacci number of a given number
//INPUT: (n) a value in which the user seek the fibonacci number for.
//OUTPUT: The fibonacci number of the users input
unsigned int recursiveThree(unsigned int m)
{

  if (m == 0)
  {
    return 0;
  }

  else if (m == 1)
  {
    return 1;
  }

  else
  {
    return (recursiveThree(m-1) + recursiveThree(m-2));
  }
}

//recursiveFour: Takes 2 inputs and returns the greatest common divisor
//INPUT: 2 numerical inputs
//OUTPUT: The greatest commmon divisor
unsigned int recursiveFour(unsigned int m, unsigned int y)
{
  if (y == 0)
  {
    return m;
  }

  else
  {
    return recursiveFour(y, m%y);
  }
}

//recursiveFive: Calculates the value of a exponential term
//INPUT: a base(m) and an exponenet(y)
//OUTPUT: the value of the base raised to the power
unsigned int recursiveFive(unsigned int m, unsigned int y)
{
  if(y == 0)
  {
    return 1;
  }

  else if(y%2 == 0)
  {
    return pow(recursiveFive(m,y/2),2);
  }

  else
  {
    return m*recursiveFive(m, y-1);
  }
}

//recursiveSix: Counts down from from a given value (m) to 1
//INPUT: The interger to start counting down from
//OUTPUT: Each value (m-1) until 1
unsigned int recursiveSix(unsigned int m)
{
  if (m > 1)
  {
    printf("%u ", m);
    return recursiveSix(m-1);
  }

  else
  {
    return 1;
  }
}

//recursiveSeven: Draw an upside down right angle triangle
//INPUT: the base character length
//OUTPUT: a triangle with each line decreasing my 1 character (m-1)
unsigned int recursiveSeven(unsigned int m)
{
  if(m != 0)
  {
    for (unsigned int count = m; count != 0; --count)
    {
     printf("*");
    }
   printf("\n");
   return recursiveSeven(m-1);
  }

  return 0;
}

//recursiveEight: Draws a right angle triangle
//INPUT: The base character length
//OUTPUT: a triangle stating at 1 and increasing by 1 till it equals input
unsigned int recursiveEight(unsigned int m)
{
  if(m != 0)
  {
    recursiveEight(m-1);
    for(unsigned int count = m; count != 0; --count)
    {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}


//==============================================================================
//|                         Non-recursive Functions                            |
//==============================================================================

//nonrecursiveOne: adds all digits upto the input value
//INPUT: Final digit
//OUTPUT: sum off all digits
int nonrecursiveOne(int n)
{
  int sum;
  for(; n != 0; n--)
  {
    sum += n;
  }
  return sum;
}

//recursiveTwo: add terms which are calculated using the input value
//INPUT: a value for the term (m+1)^2
//OUTPUT: The sum of all terms until m is decremeted to 1
unsigned int nonrecursiveTwo(unsigned int m)
{
  unsigned int sum;
  for(; m != 0; m--)
  {
    sum += pow((m+1),2);
  }
  return sum;
}

//recursiveThree: Find the fibonacci number at a given location
//INPUT: location of the number
//OUTPUT: the number based on location
unsigned int nonrecursiveThree(unsigned int m)
{
  unsigned int new = 1;
  unsigned int old = 0;
  int count = 1;
  while(count < m)
  {
    int i = new;
    new += old;
    old = i;
    count++;
  }
  return new;
}

//recursiveFour: Greatest common divisor
//INPUT: two values
//OUTPUT: the greatest common divisor between the two
unsigned int nonrecursiveFour(unsigned int m, unsigned int y)
{
  if(m==y)
  {
    return m;
  }

  else
  {
    while (m != y)
    {
      if(y <= m)
      {
        m -= y;
      }

      else
      {
        y -= m;
      }
    }
    return m;
  }

}

//recursiveFive: calculates an exponent
//INPUT: the base(m) and exponent (y)
//OUTPUT: the value
unsigned int nonrecursiveFive(unsigned int m, unsigned int y)
{
 int total = pow(m, y);
 return total;
}

//recursiveSix: Counts down from an input integer
//INPUT: Integer to begin counting down at
//OUTPUT: each integer until it reaches 1
unsigned int nonrecursiveSix(unsigned int m)
{
  for(; m != 0;)
  {
    printf("%u ", m);
    m--;
  }
  return 0;
}

//recursiveSeven:Draw an inverse right angle triangle
//INPUT: Width of base
//OUTPUT: Each line until the width in 1
unsigned int nonrecursiveSeven(unsigned int m)
{
  for(; m != 0; m--)
  {
    for(int i= m; i != 0; i--)
    {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}

//recursiveEight: Draws an right angle triangle
//INPUT: Amount of characters in base
//OUTPUT: each line until the line reaches the input base width
unsigned int nonrecursiveEight(unsigned int m)
{
  for(unsigned int count = 1 ; count <= m; count++)
  {
    for(unsigned int i = count; i != 0; i--)
    {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
