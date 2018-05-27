#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP
#include <memory>
#include "shape.hpp"

class CompositeShape : public Shape
{
public:
  CompositeShape();
  CompositeShape(const CompositeShape &comp);
  CompositeShape(CompositeShape &&comp) ;
  ~CompositeShape();

  CompositeShape & operator = (const CompositeShape &comp);
  CompositeShape & operator = (CompositeShape &&comp) ;
  const Shape& operator[](int index) const;

  void addShape(const Shape &new_shape);
  void move(const double dx,const double dy) override;
  void move(const point_t &new_p) override;
  void scale(const double k) override;

  size_t size() const noexcept;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void print() const override;
  std::unique_ptr<Shape> clone() const override;
  void rotate(const double angle) override;
private:
  std::unique_ptr<Shape> *arr_forms;//added
  int reserved_,arr_size;
};
#endif // COMPOSITESHAPE_HPP
