#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"
class Rectangle: public Shape
{
public:
  Rectangle (const point_t &p, double w, double h);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move (const point_t &p) override;
  void move (const double dx, const double dy) override;

private:
  point_t pos;
  double width;
  double height;
};
#endif
