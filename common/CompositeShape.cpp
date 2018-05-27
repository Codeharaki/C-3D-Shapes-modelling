#include "CompositeShape.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>
CompositeShape::CompositeShape():
  reserved_(1),
  arr_size(0)
{
  arr_forms = new std::unique_ptr<Shape>[1];
}
CompositeShape::CompositeShape(const CompositeShape &comp):
  reserved_(comp.reserved_),
  arr_size(0)
{
  arr_forms = new std::unique_ptr<Shape>[comp.reserved_];
  *this = comp;
}
CompositeShape::CompositeShape(CompositeShape &&comp) :
  arr_forms(nullptr),
  reserved_(0) 
{
  arr_size=0;
  *this = std::move(comp);
}
CompositeShape::~CompositeShape()
{
  delete [] arr_forms;
  arr_forms=nullptr; 
}
CompositeShape & CompositeShape::operator =(const CompositeShape &comp)
{
  if(this != &comp)
  {  
    if(reserved_ >= comp.reserved_)
    {
      for(int i = 0; i < arr_size; i++)
      {
        arr_forms[i].reset(nullptr);
      }
      arr_size = 0;
    }
    else
    {
      delete [] arr_forms;
      arr_forms = nullptr;
      arr_size = 0;
    }
    for (int i = 0; i < comp.arr_size; i++)
    {
      addShape(comp[i]);
    }
  }
  return *this;
}
std::unique_ptr<Shape> CompositeShape::clone() const
{
  return std::unique_ptr<CompositeShape>(new CompositeShape(*this));
}

size_t CompositeShape::size() const noexcept
{
  return arr_size;
}
void CompositeShape::addShape(const Shape &new_shape)
{
  std::unique_ptr<Shape> *new_array = new std::unique_ptr<Shape>[2 * reserved_];
  for(int i = 0; i < arr_size; i++)
  {
    new_array[i] = std::move(arr_forms[i]);
  }
  delete[] arr_forms;
  arr_forms = new_array;
  reserved_ *= 2;
  arr_forms[arr_size++] = std::move(new_shape.clone());
}
CompositeShape& CompositeShape::operator=(CompositeShape &&comp) 
{
  if(this != &comp)
  {
    delete[] arr_forms;
    arr_forms = comp.arr_forms;
    comp.arr_forms = nullptr;
    arr_size = comp.arr_size;
    comp.arr_size = 0;
    reserved_ = comp.reserved_;
    comp.reserved_ = 0;
  }
  return *this;
}
const Shape& CompositeShape::operator[](int index) const
{
  if(index >= arr_size)
  {
    throw std::out_of_range("CompositeShape index out of range");
  }
  return *arr_forms[index];
}

double CompositeShape::getArea() const
{
  double sum_area = 0;
  for(int i = 0; i < arr_size; i++)
  {
    sum_area += arr_forms[i]->getArea();
  }
  return sum_area;
}
using namespace std;
rectangle_t CompositeShape::getFrameRect() const
{
  rectangle_t f_shape0= arr_forms[0]->getFrameRect();
  double f_left = f_shape0.pos.x -f_shape0.width/2;
  double f_right= f_shape0.pos.x +f_shape0.width/2;
  double f_bottom = f_shape0.pos.y -f_shape0.height/2;
  double f_top = f_shape0.pos.y +f_shape0.height/2;
  for(int i = 0; i < arr_size; i++)
  {
    rectangle_t f_shape_i= arr_forms[i]->getFrameRect();
    f_left = min(f_left,f_shape_i.pos.x -f_shape_i.width/2); 
    f_right= max(f_right,f_shape_i.pos.x +f_shape_i.width/2);
    f_bottom= min(f_bottom,f_shape_i.pos.y -f_shape_i.height/2); 
    f_top = max(f_top,f_shape_i.pos.y +f_shape_i.height/2);
  }
  return {{(f_left+f_right)/2,(f_bottom+f_top)/2},f_right-f_left,f_top-f_bottom};
}
void CompositeShape::scale(const double k)
{
  if (k <=0)
  {
    throw std::invalid_argument("invalid scale coffecient CompositeShape");
  }
  for(int i=0 ;i< arr_size; i++)
  {
    double a= arr_forms[i]->getFrameRect().pos.x;
    double b=arr_forms[i]->getFrameRect().pos.y;
    arr_forms[i]->scale(k);
    arr_forms[i]->move((a -getFrameRect().pos.x)*k,(b -getFrameRect().pos.y)*k);
  }
}
void CompositeShape::move(double dx, double dy)
{
  for(int i = 0; i < arr_size; i++)
  {
    arr_forms[i]->move(dx,dy);
  }
}
void CompositeShape::move(const point_t &new_p)
{
  move(new_p.x -getFrameRect().pos.x,new_p.y -getFrameRect().pos.y);
}
void CompositeShape::print() const
{ 
  std::cout<<"-CompositeShape: "<<std::endl;
  std::cout<<"quantity shapes = "<<arr_size<<std::endl;
  std::cout<<"sum area = "<<getArea()<<std::endl;
  std::cout<<"FrameRectangle for CompositeShape: "<<std::endl;
  std::cout<<"center ("<<getFrameRect().pos.x<<" ,"<<getFrameRect().pos.y<<")";
  std::cout<<std::endl;
  for(int i=0; i< arr_size; i++)
  {
    std::cout<<"**AT THE POSITION "<<i+1<<" : "<<std::endl;
    arr_forms[i]->print();
    std::cout<<std::endl;
  }
}
void CompositeShape::rotate(const double angle)
{ 
  double a=cos(angle);
  double b=sin(angle);
  for(int i=0; i< arr_size; i++)
  {
    arr_forms[i]->rotate(angle);
    const double delta_x = arr_forms[i]->getFrameRect().pos.x -getFrameRect().pos.x;
    const double delta_y = arr_forms[i]->getFrameRect().pos.y -getFrameRect().pos.y;
    arr_forms[i]->move( delta_x*a-delta_y*b, delta_y*a + delta_x*b);
  }
}
