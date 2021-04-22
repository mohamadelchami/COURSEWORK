//Assignment 1 -
//Submitted by: Mohamad Elchami
//Submit Date: Jan 27th, 2020
//Practicing reading and writing characters

#include <iostream>
#include <iomanip>

using namespace std;

int main(){

  char c; // This will hold the character read in

  //a While loops to read every character
  //noskipws = do not skip white spaces
  while(cin >> noskipws >>c){
    //The swtich case will test the character for any of the
    // condition characters and act accordingly
    switch(c){
      case '.' : cout << ' ';
                 break;
      case ',' : cout << ' ';
                 break;
      case '?' : cout << ' ';
                 break;
      case '-' : cout << ' ';
                 break;
      case '\''  : cout << ' ';
                 break;
      //if it is not any of the special cases the character is printed
      default  : cout << c;
                 break;
    }
  }

return 0;
}
