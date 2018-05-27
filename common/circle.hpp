#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.hpp"

class Circle: public Shape
{
public:
  Circle(const point_t &p,const double r);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const double dx,const double dy) override;
  void move(const point_t &p) override;
  void scale(const double k) override;
  void print() const override;
  std::unique_ptr<Shape> clone() const override;
  double getRadius() const;
  void rotate(const double ) override;
private:
  point_t pos_;
  double radius;
};
#endif
