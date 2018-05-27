#include "Triangle.hpp"

Triangle::Triangle(int x, int y):
  Shapes(x, y)
{
}

void Triangle::draw(std::ostream &ostream) const
{
  ostream << "TRIANGLE " << '(' << x_ << "; " << y_ << ")\n";
}
