#ifndef comp3400_2020w_project_write_par_hxx_
#define comp3400_2020w_project_write_par_hxx_

//===========================================================================

#include <cstddef>                  // for std::size_t
#include <mutex>                    // for std::mutex
#include <thread>                   // for std::thread
#include <iostream>                 // for std::cerr

//===========================================================================

inline void write_cell_info_concurrently(
  size_t const& xlow, size_t const& ylow,
  size_t const& xhigh, size_t const& yhigh
)
{
	static std::mutex varOne;

  std::lock_guard<std::mutex> lg(varOne);

  std::cerr << "PROCESSING: (" << xlow << ',' << ylow << ")-(" << xhigh << ',' << yhigh << ") on thread " << std::this_thread::get_id() << '\n';
}

#endif // #ifndef comp3400_2020w_project_write_par_hxx_
