#include "Circles.hpp"

Circles::Circles(const int x, const int y):
  Shapes(x, y)
{
}

void Circles::draw(std::ostream &ostream) const
{
  ostream << "CIRCLE " << '(' << x_ << "; " << y_ << ")\n";
}
