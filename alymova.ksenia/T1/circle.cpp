#include "circle.hpp"
#include <cmath>
constexpr double PI = acos(-1.0);
alymova::Circle::Circle(point pos, double radius):
  pos_(pos),
  radius_(radius),
  frame_rect_(point_t(pos_.getX() - radius, pos_.getY() - radius), point_t(pos_.getX() + radius, pos_.getY() + radius))
{}
double alymova::Circle::getArea() const
{
  return PI * radius * radius;
}
alymova::rectangle_t alymova::Circle::getFrameRect() const
{
  return frame_rect_;
}
void alymova::Circle::move(double shift_x, double shift_y)
{
  point_t shift_point(shift_x, shift_y);
  pos_ += shift_point;
  frame_rect_.move(shift_x, shift_y);
}
void alymova::Circle::move(point_t point)
{
  double shift_x = point.getX() - pos_.getX();
  double shift_y = point.getY() - pos_.getY();
  move(shift_x, shift_y);
}
void alymova::Circle::scale(double ratio)
{
  if (ratio == 1)
  {
    return;
  }
  radius *= ratio;
  frame_rect_.scale(ratio);
}
