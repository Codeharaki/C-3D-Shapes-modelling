#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "shape.hpp"

class Triangle: public Shape
{
public:
  Triangle(const point_t &pA,const point_t &pB,const point_t &pC);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(const point_t &new_p) override;
  void move(const double dx,const double dy) override;
  void scale(const double k) override;
  void print() const override;
  std::unique_ptr<Shape> clone() const override;
  void rotate(const double angle) override;
private:
  point_t pos_;
  point_t a_;
  point_t b_;
  point_t c_;
  double getDistance(const point_t &point_1,const point_t &point_2) const;
};
#endif
