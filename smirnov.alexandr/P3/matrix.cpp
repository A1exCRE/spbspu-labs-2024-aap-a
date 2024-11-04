#include "matrix.hpp"
#include <cstddef>
#include <iostream>

std::istream & smirnov::inputMatrix(std::istream & input, int * matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows * cols; ++i)
  {
    input >> matrix[i];
  }
  return input;
}

void smirnov::processMatrix(int * matrix, size_t rows, size_t columns)
{
  size_t row_start = 0;
  size_t row_end = rows - 1;
  size_t col_start = 0;
  size_t col_end = columns - 1;
  int k = 1;
  size_t index = 0;
  while (row_start <= row_end && col_start <= col_end)
  {
    for (size_t i = col_start; i <= col_end && index < rows * columns; ++i)
    {
      matrix[index++] -= k++;
    }
    row_start++;
    for (size_t j = row_start; j <= row_end && index < rows * columns; ++j)
    {
      matrix[index++] -= k++;
    }
    col_end--;
    if (row_start <= row_end)
    {
      for (size_t i = col_end; i >= col_start && index < rows * columns; --i)
      {
        matrix[index++] -= k++;
      }
      row_end--;
    }
    if (col_start <= col_end)
    {
      for (size_t j = row_end; j > row_start; --j)
      {
        matrix[index++] -= k++;
      }
      col_start++;
    }
  }
}

void smirnov::outputMatrix(std::ostream & output, int * matrix, size_t rows, size_t columns)
{
  output << matrix[0] << " ";
  for (size_t i = 1; i < rows * columns; ++i)
  {
    if (i % rows == 0)
    {
      output << matrix[i] << "\n";
    }
    else
    {
      output << matrix[i] << " ";
    }
  }
  output << "\n";
}





