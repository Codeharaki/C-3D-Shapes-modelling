#include <iostream>
#include "shape.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"

void printParams(const Shape &s)
{
  rectangle_t outFrRect = s.getFrameRect();
  std::cout << "Its area is " << s.getArea() << std::endl;
  std::cout << "Frame centre position is point (" << outFrRect.pos.x_ << ";" << outFrRect.pos.y_ << ")."<< std::endl;
  std::cout << "Its width is " << outFrRect.width << " and height is " << outFrRect.height << std::endl<< std::endl;
}

int main()
{
  std::cout << "Creating Rectangle x=20, y=10, l=15, h=50" << std::endl;
  Rectangle rect ({20,10},15,50);
  Shape *rectp = &rect;  
  printParams(rect);
  std::cout << "Moving rectangle to point x=-27, y=52" << std::endl;
  rectp -> move ({-27,52});
  printParams(rect);
  std::cout << "Moving rectangle by dx=10, dy=-30" << std::endl;
  rectp -> move (10,-30);
  printParams(rect);

  std::cout << "Creating Circle x=20, y=30, r=13" << std::endl;
  Circle circ ({20,30},13);
  Shape *circp = &circ;
  printParams(circ);
  std::cout << "Moving circle to point x=32, y=-6" << std::endl;
  circp->move({ 32, -6 });
  printParams(circ);
  std::cout << "Moving circle by dx=-12, dy=9" << std::endl;
  circp -> move (-12,9);
  printParams(circ);
  

  std::cout << "Creating triangle with points A(12,-22), B(-13,3) ,C(1,23)" << std::endl;
  Triangle tria ({12,-12},{13,5},{1,23});
  Shape *triap = &tria;
  printParams(tria);
  std::cout << "Moving triangle to point x=-7, y=4" << std::endl;
  triap->move({ -7, 4 });
  printParams(tria);
  std::cout << "Moving triangle by dx=10, dy=20" << std::endl;
  triap -> move (10,20);  
  printParams(tria);
  
  return 0;
}

