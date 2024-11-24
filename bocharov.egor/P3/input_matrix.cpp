#include "matrix.h"
#include <istream>
#include <cstddef>
std::istream & bocharov::input_matrix(std::istream & input, int * const t,  size_t m, size_t n)
{
  for (size_t i = 0; i < ((m * n) + 2) && input.good(); i++)
  {
    input >> t[i];
  }
  return input;
}
