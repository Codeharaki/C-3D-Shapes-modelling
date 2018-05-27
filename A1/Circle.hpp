#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include "base-types.hpp"
#include <iostream>
#include <stdlib.h>
class Circle : public Shape
{
public:
  Circle (const point_t &p, double r);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move (const point_t &p) override;
  void move (const double dx, const double dy) override;
  
private:
  point_t pos;
  double radius;
};
#endif
