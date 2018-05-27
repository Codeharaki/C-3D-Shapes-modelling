#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Shapes.hpp"

class Triangle : public Shapes 
{
public:
  Triangle(int x, int y);

  void draw(std::ostream&) const override;
};

#endif
