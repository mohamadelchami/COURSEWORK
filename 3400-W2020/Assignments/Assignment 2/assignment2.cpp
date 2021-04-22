//  Assignment 2
//  Mohamad Elchami 
//  January 28th, 2020

#include <cmath>      // for std::sqrt
#include <array>      // for std::array
#include <vector>     // for std::vector
#include <limits>     // for std::numeric_limits
#include <string>     // for std::string
#include <istream>    // for std::istream
#include <ostream>    // for std::ostream
#include <iostream>   // for std::cin, std::cout
#include <algorithm>  // for std::transform

using namespace std;

struct rgb{
  unsigned char red;  //Hold the color value for red
  unsigned char green;  //hold the color value for green
  unsigned char blue; //hold the color valie for vlue
};

std::istream& operator >>(std::istream& is, rgb& colour){
  unsigned r, g, b;

  if(is >> r >> g >> b){
    colour.red = r;
    colour.green = g;
    colour.blue = b;
  }
  else{
    is.setstate(ios_base::failbit);
  }

  return is;

}

std::ostream& operator <<(std::ostream& os, rgb const& colour){
  os << static_cast<unsigned>(colour.red) << ' '
  << static_cast<unsigned>(colour.green) << ' '
  << static_cast<unsigned>(colour.blue) << ' ';

  return os;
}

double distance(rgb const& a, rgb const& b){
  float d1, d2, d3;

  d1 = ((a.red - b.red)*(a.red - b.red));
  d2 = ((a.green - b.green)*(a.green - b.green));
  d3 = ((a.blue - b.blue)*(a.blue - b.blue));

  return sqrt(d1 + d2 + d3);
}

int main()
{
  array<rgb,16> const colours{{
      { 0x00, 0x00, 0x00 }, // 0: black
      { 0x80, 0x00, 0x00 }, // 1: maroon
      { 0x00, 0x80, 0x00 }, // 2: green
      { 0x80, 0x80, 0x00 }, // 3: olive
      { 0x00, 0x00, 0x80 }, // 4: navy
      { 0x80, 0x00, 0x80 }, // 5: purple
      { 0x00, 0x80, 0x80 }, // 6: teal
      { 0xC0, 0xC0, 0xC0 }, // 7: silver
      { 0x80, 0x80, 0x80 }, // 8: grey
      { 0xFF, 0x00, 0x00 }, // 9: red
      { 0x00, 0xFF, 0x00 }, // 10: lime
      { 0xFF, 0xFF, 0x00 }, // 11: yellow
      { 0x00, 0x00, 0xFF }, // 12: blue
      { 0xFF, 0x00, 0xFF }, // 13: fushsia
      { 0x00, 0xFF, 0xFF }, // 14: aqua
      { 0xFF, 0xFF, 0xFF }  // 15: white
    }};

    array<string,16> const colour_names{
      "black", "maroon", "green", "olive", "navy", "purple", "teal", "silver",
      "gray", "red", "lime", "yellow", "blue", "fushsia", "aqua", "white"
    };



    for (rgb value{}; cin >> value; ) {
      vector<double> distances;
      distances.reserve(colours.size());

      transform( begin(colours), end(colours), back_inserter(distances), [&value](auto const& colour){
         return distance(colour, value);
       }
      );

      size_t index = std::numeric_limits<size_t>::max();

      double smallest_distance = std::numeric_limits<double>::max();

      for(auto i=begin(distances), iEnd=end(distances); i != iEnd ; ++i){
        if(*i < smallest_distance){
          smallest_distance = *i;
          index =  i - begin(distances);
        }
      }


      cout << colour_names[index] << '\n';

      if(index < 0 || index > 15){
        cout << "ERROR occurred. Aborting...\n";
          return 1;
      }
    }

    return 0;
}
