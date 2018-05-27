#include "Shapes.hpp"

Shapes::Shapes(int x, int y):
  x_(x),
  y_(y)
{
}

bool Shapes::isMoreLeft(const Shapes &shape) const 
{
  return (x_ < shape.x_);
}

bool Shapes::isUpper(const Shapes & shape) const 
{
  return (y_ > shape.y_);
}
