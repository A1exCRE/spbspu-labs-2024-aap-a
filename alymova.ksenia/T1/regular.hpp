#ifndef REGULAR_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"
#include <cstddef>
namespace alymova
{
  struct Regular final: public Shape
  {
  public:
    Regular() = default;
    Regular(point_t pos, point_t top, point_t other);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double shift_x, double shift_y) override;
    void move(point_t point) override;
    Shape* clone() const override;
  protected:
    point_t pos_, top_, other_;
    size_t sides_cnt_;
    rectangle_t frame_rect_;
    size_t getCntSides() const;
    rectangle_t setFrameRect();
    void unsafeScale(double ratio) override;
  };
}
#endif
