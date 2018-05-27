#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <iostream>

class Shapes 
{
public:
  Shapes(int, int);

  virtual ~Shapes() = default;
  bool isMoreLeft(const Shapes&) const;
  bool isUpper(const Shapes&) const;

  virtual void draw(std::ostream&) const = 0;

protected:
  int x_, y_;
};

#endif
