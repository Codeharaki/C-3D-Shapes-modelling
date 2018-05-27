#ifndef SHAPE_H
#define SHAPE_H
#include <memory>
#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default ;
  virtual void move(const point_t &new_p) =0;
  virtual void move(const double dx,const double dy) =0;
  virtual void scale(const double k) =0;

  virtual double getArea() const=0;
  virtual rectangle_t getFrameRect() const=0;
  virtual void print() const=0;
  virtual std::unique_ptr<Shape> clone() const = 0;
  virtual void rotate(const double angle) =0;
};
#endif
