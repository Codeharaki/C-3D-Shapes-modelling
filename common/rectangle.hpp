#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.hpp"

class Rectangle: public Shape
{
public:
  Rectangle(const point_t &p, const double w, const double h);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &p) override;
  void move(const double dx,const double dy) override;
  void scale(const double k) override;
  double getWidth() const;
  double getHeight() const;
  void print() const override;
  std::unique_ptr<Shape> clone() const override;
  void rotate(const double angle) override;

private:
  point_t pos_;
  double width_;
  double height_;
  point_t a_;
  point_t b_;
  point_t c_;
  point_t d_;
};
#endif
