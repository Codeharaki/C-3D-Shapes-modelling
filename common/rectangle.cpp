#include "rectangle.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>


Rectangle::Rectangle(const point_t &p, const double w, const double h):
  pos_(p),
  width_ (w),
  height_(h),
  a_({p.x -width_/2, p.y +height_/2}),
  b_({p.x +width_/2, p.y +height_/2}),
  c_({p.x +width_/2, p.y -height_/2}),
  d_({p.x -width_/2, p.y -height_/2})
{
  if (width_ <= 0)
  {
    throw std::invalid_argument ("Invalid rectangle width_.");
  };
  if (height_ <= 0)
  {
    throw std::invalid_argument ("Invalid rectangle height_.");
  };
}
void Rectangle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
  a_.x += dx;
  a_.y += dy;
  b_.x += dx;
  b_.y += dy;
  c_.x += dx;
  c_.y += dy;
  d_.x += dx;
  d_.y += dy;
}
void Rectangle::move(const point_t &p)
{
  pos_ = p;
}
double Rectangle::getHeight() const
{
  return height_;
}
double Rectangle::getWidth() const
{
  return width_;
}
void Rectangle::scale(const double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument ("Invalid scaling coefficient");
  }
  width_ *= k;
  height_ *= k;
  a_ = {pos_.x + k*(a_.x - pos_.x), pos_.y + k*(a_.y - pos_.y)};
  b_ = {pos_.x + k*(b_.x - pos_.x), pos_.y + k*(b_.y - pos_.y)};
  c_ = {pos_.x + k*(c_.x - pos_.x), pos_.y + k*(c_.y - pos_.y)};
  d_ = {pos_.x + k*(d_.x - pos_.x), pos_.y + k*(d_.y - pos_.y)};
}
double Rectangle::getArea() const
{
return (width_ * height_);
}
rectangle_t Rectangle::getFrameRect() const
{
  rectangle_t localRect;
  localRect.pos.x = pos_.x;
  localRect.pos.y = pos_.y;
  localRect.width  = width_;
  localRect.height = height_;
  return localRect;
}
void Rectangle::print() const
{
  rectangle_t outFrRect = getFrameRect();
  std::cout << "Rectangle area is " << getArea() << std::endl;
  std::cout << "centre position is point (" << outFrRect.pos.x << ";" << outFrRect.pos.y << ")." << std::endl;
  std::cout << "width is " << outFrRect.width << " and height is " << outFrRect.height << "." << std::endl;
}
std::unique_ptr<Shape> Rectangle::clone() const
{
  return std::unique_ptr<Shape>(new Rectangle(pos_, width_, height_));
}
void Rectangle::rotate(const double angle)
{
  const double rad = M_PI*(angle/180);
  const double cosi = cos(rad);
  const double si = sin(rad);
  a_= {pos_.x + (a_.x - pos_.x)*cosi - (a_.y - pos_.y)*si, pos_.y + (a_.x - pos_.x)*si + (a_.y - pos_.y)*cosi};
  b_= {pos_.x + (b_.x - pos_.x)*cosi - (b_.y - pos_.y)*si, pos_.y + (b_.x - pos_.x)*si + (b_.y - pos_.y)*cosi};
  c_= {pos_.x + (c_.x - pos_.x)*cosi - (c_.y - pos_.y)*si, pos_.y + (c_.x - pos_.x)*si + (c_.y - pos_.y)*cosi};
  d_= {pos_.x + (d_.x - pos_.x)*cosi - (d_.y - pos_.y)*si, pos_.y + (d_.x - pos_.x)*si + (d_.y - pos_.y)*cosi};
}
