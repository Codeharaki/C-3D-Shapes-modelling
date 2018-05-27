#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"

int main()
{
  std::cout << "      Creating Rectangle x=20, y=10, l=15, h=50" << std::endl;
  Rectangle rect ({20,10},15,50);
  Shape *rectp = &rect; 
  rect.print(); 
  std::cout << std::endl;  
 
  std::cout << "       Moving rectangle to point x=-27, y=52" << std::endl;
  rectp -> move ({-27,52});
  rect.print();  
  std::cout << std::endl;
  std::cout << "      Moving rectangle by dx=10, dy=-30" << std::endl;
  rectp -> move (10,-30);
  rect.print();  
  std::cout << std::endl;
  std::cout << "     Scaling rectangle by k=1.2" << std::endl;
  rectp->scale(1.2);
  rect.print();  

  std::cout << std::endl;
  std::cout << "      Creating Circle x=20, y=30, r=13" << std::endl;
  Circle circ ({20,30},13);
  Shape *circp = &circ;
  circ.print();  
  std::cout << std::endl;
  
  std::cout << "Moving circle to point x=32, y=-6" << std::endl;
  circp->move({ 32, -6 });

  circ.print(); 
  std::cout << std::endl;  
  std::cout << "Moving circle by dx=-12, dy=9" << std::endl;
  circp -> move (-12,9);
  circ.print();  
  std::cout<< std::endl;
  std::cout << "Scaling Circle by k=0.9" << std::endl;
  circp->scale(0.9);
  circ.print();  
  std::cout << std::endl;

  std::cout << "         Creating triangle with points A(1,12), B(3,3) ,C(1,23)" << std::endl;
  Triangle tria ({1,12},{3,3},{1,23});
  Shape *triap = &tria;
  tria.print();  
  std::cout << std::endl;
  std::cout << "         Moving triangle to point x=-7, y=4" << std::endl;
  triap->move({ -7, 4 });
  tria.print();
  std::cout << std::endl;
  std::cout << "        Moving triangle by dx=10, dy=20" << std::endl;
  triap -> move (10,20);  
  tria.print();
  std::cout << std::endl;
  std::cout << "Scaling Triangle by k=1.63" << std::endl;
  triap->scale(1.63);
  tria.print();
  return 0;
}
