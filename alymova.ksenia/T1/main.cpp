#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "inputProcess.hpp"

int main()
{
  alymova::Shape* shapes[1000] = {};
  int shapes_now = 0;
  shapes[0] = alymova::makeShape(std::cin, shapes);
  shapes_now++;

  print(std::cout, shapes);
  std::cout << "\n";
  scale(shapes, alymova::point_t(0.0, 0.0), 2);
  print(std::cout, shapes);
  std::cout << "\n";
  clear(shapes);
}

