#ifndef CIRCLES_HPP
#define CIRCLES_HPP

#include "Shapes.hpp"
#include <ostream>

class Circles : public Shapes 
{
public:
  Circles(int, int);
  void draw(std::ostream&) const override;
};

#endif
