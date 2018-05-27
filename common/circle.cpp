#include "circle.hpp"
#include <stdexcept>
#include <cmath>
#include <iostream>

using namespace std;

Circle::Circle(const point_t &p,const double r):
  pos_(p),
  radius(r)
{
  if (radius <= 0)
  {
    throw std::invalid_argument("Error! Invalid Radius!");
  }
    
}
double Circle::getArea() const
{
  return M_PI*radius*radius;
}
void Circle::move(const double dx,const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
void Circle::move (const point_t &p)
{
  pos_ = p;
}
void Circle::scale(const double k)
{
  if (k<=0)
  {
    throw std::invalid_argument("Scaling value is not valid");
  }
  radius *= k;
}
double Circle::getRadius() const
{
  return radius;
}
rectangle_t Circle::getFrameRect() const
{
  rectangle_t localRect;
  localRect.pos.x = Circle::pos_.x;
  localRect.pos.y = Circle::pos_.y;
  localRect.width = 2 * Circle::radius;
  localRect.height = 2 * Circle::radius;
  return localRect;
}
void Circle::print() const
{
  rectangle_t outFrRect = getFrameRect();
  std::cout << "Circle area is " << getArea() << std::endl;
  cout<<"  r = "<<radius<<endl;
  std::cout << "centre position is point (" << outFrRect.pos.x << ";" << outFrRect.pos.y << ")."<< std::endl;
  std::cout << " width is " << outFrRect.width << " and height is " << outFrRect.height << "."<< std::endl;
}
void Circle::rotate(const double )
{}
std::unique_ptr<Shape> Circle::clone() const
{
  return std::unique_ptr<Shape>(new Circle(pos_, radius));
}
