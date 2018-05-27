#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
struct point_t
{
  double x_;
  double y_;
};

struct rectangle_t
{
  point_t pos;
  double width;
  double height;
};
#endif
