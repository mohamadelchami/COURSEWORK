#ifndef comp3400_2020w_project_mandelbrot_par_hxx_
#define comp3400_2020w_project_mandelbrot_par_hxx_

//===========================================================================

#include <cmath>                    // for std::abs
#include <complex>                  // for std::complex

#include <string>                   // for std::string
#include <vector>                   // for std::vector

#include <algorithm>                // for various algorithms
#include <numeric>                  // e.g., for std::iota

#include <chrono>                   // for timing and clocks
#include <execution>                // for std::execution::par
#include <thread>                   // e.g., for std::thread::get_id()

#include <iostream>                 // for std::cerr and std::cout

#include "ppm.hxx"
#include "hsv.hxx"
#include "utils.hxx"
#include "program_cli_args.hxx"
#include "mandelbrot.hxx"

//===========================================================================

template <typename Image, typename Real, typename MandelToColourFunc>
void draw_mandelbrot_set_par(
  Image& image,
  std::complex<Real> const& min_point,
  std::complex<Real> const& max_point,
  MandelToColourFunc&& m2c,
  std::size_t const& max_iter,
  std::size_t chunks_per_x_axis
)
{
  auto const image_width = image.width();

  auto const image_height = image.height();

  auto const pointDifference = max_point - min_point;


  auto const compute_cell = [&](size_t const& ilow, size_t const& ihigh, size_t const& jlow, size_t const& jhigh)
    {
      //4
      write_cell_info_concurrently(ilow, jlow, ihigh, jhigh);

      for (size_t i = ilow; i != ihigh; ++i)
      {
        Real const x =
          image_index_to_real(i, image_width,
            pointDifference.real(), min_point.real());
        ;
        for (size_t j = jlow; j != jhigh; ++j)
        {
          Real const y =
            image_index_to_real(j, image_height,
              pointDifference.imag(), min_point.imag());
          ;
          std::complex<Real> const c(x,y);
          image(i,j) = m2c(compute_mandelbrot_at(c,max_iter),max_iter);
        }
      }
    };

  //5
    std::vector<std::size_t> idivs_lo;
    std::vector<std::size_t> idivs_hi;

    evenly_divide_n(back_inserter(idivs_lo), image_width, chunks_per_x_axis);
    std::inclusive_scan(begin(idivs_lo),end(idivs_lo),back_inserter(idivs_hi));
    std::exclusive_scan(begin(idivs_lo),end(idivs_lo),begin(idivs_lo),0);

  //6
    std::vector<std::size_t> jdivs_lo;
    std::vector<std::size_t> jdivs_hi;

    evenly_divide_n(back_inserter(jdivs_lo), image_height, chunks_per_x_axis);
    std::inclusive_scan(begin(jdivs_lo),end(jdivs_lo),back_inserter(jdivs_hi));
    std::exclusive_scan(begin(jdivs_lo),end(jdivs_lo),begin(jdivs_lo),0);

  //7
  std::vector<std::size_t> vectorSeven(idivs_lo.size());
  std::iota(begin(vectorSeven), end(vectorSeven), 0);

  //8
  auto startTime = std::chrono::high_resolution_clock::now();

   for (long unsigned int i = 0; i < vectorSeven.size(); i++)
  {
      //Inner for loop
      std::for_each(std::execution::par, begin(vectorSeven), end(vectorSeven), [&](std::size_t const& j){

          compute_cell(idivs_lo[i], idivs_hi[i], jdivs_lo[j], jdivs_hi[j]);

      });
  }

  auto endTime = std::chrono::high_resolution_clock::now();

  auto runTime = endTime - startTime;

  std::cout << "MANDELBROT_TIME: " << image_width << " by " << image_height << " Mandelbrot set took " << runTime.count() << " seconds.\n";
}

#endif // #ifndef comp3400_2020w_project_mandelbrot_par_hxx_
