#ifndef comp3400_2020w_project_write_image_hxx_
#define comp3400_2020w_project_write_image_hxx_

//===========================================================================

#include <string>                   // for std::string
#include <chrono>                   // for timing and clocks
#include <fstream>                  // for std::ofstream
#include <iostream>                 // for std::cerr and std::cout

//===========================================================================

template <typename Image>
void write_image(Image const& image, std::string const& fname)
{
  using namespace std;

  cout << "Writing " << fname << '\n';
  cout.flush();

  auto t1 = chrono::high_resolution_clock::now();
  {
    ofstream out(fname, ios::binary);
    image.save(out, true);
  }
  auto t2 = chrono::high_resolution_clock::now();

  chrono::duration<float> secs = t2 - t1;
  cout << "OFSTREAM_TIME: " << fname << " took " << secs.count()
    << " seconds to write.\n";
}

//===========================================================================

#endif // #ifndef comp3400_2020w_project_write_image_hxx_
