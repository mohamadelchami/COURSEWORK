// Author: Mohamad Elchami
// Date: Feb. 2nd 2018
// Assignment 1

// I acknowledge that this is my own work and did not receive any unauthorized help with it.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

unsigned int ldiff=0; // global variable to keep track of max differnece of the squences

unsigned int reverseInteger(unsigned int num);
unsigned int generateMagicNumber(unsigned int num);

int main()
{
  //counter = terminates loop through any amount of inputs
  //num = the input numbers
  unsigned int counter, num;

  //Ask user how many integers they will input to help create a loop termination
  printf("How many integers would you like to reverse? : ");
  scanf("%u", &counter);

  //Ask for the sequence of numbers
  printf("Enter a series of numbers to reverse: ");

  //loops, scans, calculates the reverse and magic number, and prints for each input
  for(; counter != 0; counter--)
  {
    scanf("%u", &num);

    printf("%u\t", generateMagicNumber(num));
  }

  // prints the max differnce from the sequence
  printf("\n%u\n", ldiff);

  return 0;
}


//reverseInteger: Reverse the integer supplied
//Input: Integer
//Output: the reverse of the input integer
unsigned int reverseInteger(unsigned int num)
{
  unsigned int reverse = 0; // intitate as 0 to avoid garbage

  if(num<10)
  {
    return num; // because (num>10)%10 = num
  }

  else
  {

    for( ; num != 0 ; )
    {
      reverse *= 10;
      reverse += num%10;
      num = floor(num/10);
    }

    return reverse;

  }
}

//generateMagicNumber: calcualte the absolute difference between the input number and reverse, then calcualates the reverse of that difference
//Input: user input and reverseInteger(num)
//Output: magicNumber(num) - there reverse of the albsolute difference
unsigned int generateMagicNumber(unsigned int num)
{
  unsigned int reverse, difference, magicNumber=0, magicNumber2=0;

  difference = abs((int) num - (int) reverseInteger(num)); // calcualtes absolute difference

  //determine the largest difference
  if(difference > ldiff) //tests if the new difference is larger than the old difference
  {
    ldiff = difference; //if new diff is larger than old diff then keep new diff
  }


  if(difference<10)
  {
    return difference; // because (difference>10)%10 = difference
  }

  else
  {
    for ( ; difference != 0 ; )
    {
      magicNumber *= 10;
      magicNumber += (difference%10);
      difference = floor(difference /10);
    }

    return magicNumber;

  }
}
