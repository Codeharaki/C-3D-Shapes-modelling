#include "Square.hpp"

Square::Square(const int x, const int y):
  Shapes(x, y)
{
}

void Square::draw(std::ostream &ostream) const
{
  ostream << "SQUARE " << '(' << x_ << "; " << y_ << ")\n";
}
