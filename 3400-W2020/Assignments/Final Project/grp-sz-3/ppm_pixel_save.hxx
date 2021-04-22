#ifndef comp3400_2020w_project_ppm_pixel_save_hxx_
#define comp3400_2020w_project_ppm_pixel_save_hxx_

//===========================================================================

  std::ostream& save(std::ostream& os, bool binary = false) const
  {
    if (!binary)
    {
      // use static_cast to ensure values are written out as human-readable 
      // integers...
      os 
        << static_cast<std::size_t>(r) << ' ' 
        << static_cast<std::size_t>(g) << ' ' 
        << static_cast<std::size_t>(b)
      ;
    }
    else
    {
      // use .put() to ensure data is written out unformatted...
      os.put(r).put(g).put(b);
    }
    return os;
  }

//===========================================================================

#endif // #ifndef comp3400_2020w_project_ppm_pixel_save_hxx_
