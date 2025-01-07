#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"
namespace petrov
{
  struct Rectangle final: Shape
  {
  public:
    Rectangle(point_t p1, point_t p2);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t concrete_point) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    point_t p1_, p2_;
  };
}
#endif
