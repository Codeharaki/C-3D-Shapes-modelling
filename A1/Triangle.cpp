#include "base-types.hpp"
#include "Triangle.hpp"
#include <stdlib.h>
#include <iostream>
#include <math.h>

Triangle::Triangle(const point_t &p1, const point_t &p2, const point_t &p3) :
  pos ({(p1.x_ + p2.x_ + p3.x_)/3, (p1.y_ + p2.y_ + p3.y_)/3}),
  a_ (p1),
  b_ (p2),
  c_ (p3)
{
   if (getArea() <= 0)
   {
     std::cerr << "Invalid triangle initialization." << std::endl;
     exit(1);
   }
    
}

double Triangle::getArea() const
{
  double f = (b_.x_ - a_.x_);
  double g = (c_.y_ - a_.y_);
  double h = (c_.x_ - a_.x_);
  double i = (b_.y_ - a_.y_);
  double s = (f*g - h*i)/2;
  return s;
}

rectangle_t Triangle::getFrameRect() const
{
  double maxX = 0;
  double maxY = 0;
  maxX = std::max(std::max(a_.x_ ,b_.x_),c_.x_);
  maxY = std::max(std::max(a_.y_, b_.y_),c_.y_);
  double minX = 0;
  double minY = 0;
  minX = std::min(std::min(a_.x_,b_.x_),c_.x_);
  minY = std::min(std::min(a_.y_, b_.y_),c_.y_);
  
  rectangle_t localRect;
  localRect.pos.x_ = pos.x_;
  localRect.pos.y_ = pos.y_;
  localRect.width  = maxX - minX;
  localRect.height = maxY - minY;
  return localRect;
}
void Triangle::move (const point_t &p)
{
  double dx = p.x_ - pos.x_;
  double dy = p.y_ - pos.y_;
  move (dx,dy);
}

void Triangle::move (const double dx, const double dy)
{
  pos.x_ += dx;
  a_.x_ += dx;
  b_.x_ += dx;
  c_.x_ += dx;
  pos.y_ += dy;
  a_.y_ += dy;
  b_.y_ += dy;
  c_.y_ += dy;
}

