#ifndef SQUARE_H
#define SQUARE_H

#include "Shapes.hpp"

class Square : public Shapes 
{
public:
  Square(int x, int y);

  void draw(std::ostream&) const override;
};

#endif
