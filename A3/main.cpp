#include <iostream>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "CompositeShape.hpp"
#include <stdexcept>
using namespace std;

int main()
{
  std::cout << std::endl;
  std::cout << "----------Creating Shapes--------------" << std::endl;
  std::cout << "Creating Rectangle x=20, y=10, l=15, h=50" << std::endl;
  Rectangle rect ({20,10},15,50); 
  rect.print();
  std::cout << std::endl;
  
  std::cout << "Creating Circle x=20, y=30, r=13" << std::endl;
  Circle circ ({20,30},13);
  circ.print();
  std::cout << std::endl;
  
  std::cout << "Creating triangle with points A(1,12), B(3,3) ,C(1,23)" << std::endl;
  Triangle tria ({1,12},{3,3},{1,23});
  tria.print();
  std::cout << std::endl;
  
  CompositeShape compo_shape;
  std::cout << "Creating CompositeShape1 with Circle" << std::endl;
  compo_shape.addShape(circ);
  compo_shape.print();
  std::cout << "Adding Rectangle to CompositeShape1" << std::endl;
  compo_shape.addShape(rect);
  compo_shape.print();
  std::cout << " Move composite shape to point x= 5, y=7: "<<std::endl;
  compo_shape.move({ 5,7 });
  compo_shape.print();
  std::cout << "Moving CompositeShape1 by dx=4, dy=9" << std::endl;
  compo_shape.move(4,9);
  std::cout << "Creating CompositeShape2 from CompositeShape1" << std::endl;
  CompositeShape compo_(compo_shape);
  compo_.print();
  std::cout << "Scaling CompositeShape2 by k=4.2" << std::endl;
  compo_.scale(4.2);
  compo_.print();
  std::cout << "Adding Triangle to CompositeShape2" << std::endl;
  compo_.addShape(tria);
  compo_.print();
  std::cout << "Assigning CompositeShape2 to CompositeShape1" << std::endl;
  compo_shape = compo_;
  compo_shape.print();

  return 0;
}
