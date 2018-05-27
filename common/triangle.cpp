#include "triangle.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

Triangle::Triangle(const point_t &p1,const point_t &p2,const point_t &p3):
  pos_ ({(p1.x + p2.x + p3.x)/3, (p1.y + p2.y + p3.y)/3}),
  a_(p1),
  b_(p2),
  c_(p3)
{
  if (getArea()<= 0)
  {
    throw std::invalid_argument("INVALID ARGUMENT TRIANGLE  !");
  }
}

void Triangle::move(const double dx,const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
  a_.x += dx;
  b_.x += dx;
  c_.x += dx;
  a_.y += dy;
  b_.y += dy;
  c_.y += dy;
 
}
void Triangle::move(const point_t &new_p)
{
  move(new_p.x-pos_.x,new_p.y-pos_.y);
  pos_ = new_p;
}
void Triangle::scale(const double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument ("Invalid scaling coefficient");
  }
  a_ = {pos_.x + k*(a_.x - pos_.x), pos_.y + k*(a_.y - pos_.y)};
  b_ = {pos_.x + k*(b_.x - pos_.x), pos_.y + k*(b_.y - pos_.y)};
  c_ = {pos_.x + k*(c_.x - pos_.x), pos_.y + k*(c_.y - pos_.y)};
}
double Triangle::getArea() const
{
  double f = (b_.x - a_.x);
  double g = (c_.y - a_.y);
  double h = (c_.x - a_.x);
  double i = (b_.y - a_.y);
  double s = (f*g - h*i)/2;
  return s;
}
rectangle_t Triangle::getFrameRect() const
{
  double maxX = std::max(std::max(a_.x ,b_.x),c_.x);
  double maxY = std::max(std::max(a_.y, b_.y),c_.y);
  double minX = std::min(std::min(a_.x,b_.x),c_.x);
  double minY = std::min(std::min(a_.y, b_.y),c_.y);
  rectangle_t localRect;
  localRect.pos.x = pos_.x;
  localRect.pos.y = pos_.y;
  localRect.width  = maxX - minX;
  localRect.height = maxY - minY;
  return localRect;
}
void Triangle::print() const
{
  rectangle_t outFrRect = getFrameRect();
  std::cout << "Triangle area is " << getArea() << std::endl;
  std::cout << "centre position is point (" << outFrRect.pos.x << ";" << outFrRect.pos.y << ")." << std::endl;
  std::cout << "width is " << outFrRect.width << " and height is " << outFrRect.height << "." << std::endl;
}
std::unique_ptr<Shape> Triangle::clone() const
{
  return std::unique_ptr<Shape>(new Triangle(a_, b_, c_));
}
void Triangle::rotate(const double angle)
{
  const double rad = M_PI*(angle/180);
  const double cosin = cos(rad);
  const double si = sin(rad);
  a_= {pos_.x + (a_.x - pos_.x)*cosin - (a_.y - pos_.y)*si, pos_.y + (a_.x - pos_.x)*si + (a_.y - pos_.y)*cosin};
  b_= {pos_.x + (b_.x - pos_.x)*cosin - (b_.y - pos_.y)*si, pos_.y + (b_.x - pos_.x)*si + (b_.y - pos_.y)*cosin};
  c_= {pos_.x + (c_.x - pos_.x)*cosin - (c_.y - pos_.y)*si, pos_.y + (c_.x - pos_.x)*si + (c_.y - pos_.y)*cosin};
}
