#include <iostream>
#include "Matrix-layer.hpp"
#include "CompositeShape.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "rectangle.hpp"
#include "base-types.hpp"

void print(const Shape &shape)
{
  std::cout << "Area : " << shape.getArea() << std::endl;
  rectangle_t frame = shape.getFrameRect();
  std::cout << "center (X: " << frame.pos.x << "; Y: " << frame.pos.y << " )"<<std::endl;
  std::cout << " Width: " << frame.width;
  std::cout << "; Height: " << frame.height << std::endl;
}

void printMatrixLayer(MatrixLayer &shape)
{
  for(size_t i = 0; i < shape.size(); i++)
  {
    for(size_t j = 0; j < shape[i].size(); j++)
    {
      std::cout << "MatrixLayer[" << i << "][" << j << "] " << std::endl;
      print(shape[i][j]);
    }
  }
  std::cout << "--------------------------" << std::endl << std::endl;
}

int main()
{
  Rectangle r({20,10},15,50);
  std::cout << "Creating Rectangle:" << std::endl;
  print(r);
  
  std::cout << "Rotate Rectangle by 90 degrees" << std::endl;
  r.rotate({ 90 });
  print(r);

  Triangle t({1,12},{3,3},{1,23});
  std::cout << "Creating Triangle: " << std::endl;
  print(t);
 
  CompositeShape cs;
  cs.addShape(r);
  cs.addShape(t);
  std::cout << "Creating CompositeShape with Rectangle and Triangle" << std::endl;
  cs.print();
  
  std::cout << "Rotating CompositeShape by 90 degrees" << std::endl;
  cs.rotate({ 90 });
  cs.print();
   
  std::cout << "Rotating Triangle by 90 degrees: " << std::endl;
  t.rotate({ 90 });
  print(t);

  Circle c({20,30},13);
  std::cout << "Creating Circle: " << std::endl;
  print(c);

  std::cout << "Adding Circle to CompositeShape" << std::endl;
  cs.addShape(c);
  cs.print();

  MatrixLayer sm;
  sm.addCompositeShapeElements(cs);
  std::cout << "Creating MatrixLayer from CompositeShapeElements: " << std::endl;
  printMatrixLayer(sm);

  std::cout << "Adding (the same) Circle to MatrixLayer" << std::endl;
  sm.addShape(c);
  printMatrixLayer(sm);

  std::cout << "Removing the first Circle from MatrixLayer" << std::endl;
  sm.removeShape(0, 1);
  printMatrixLayer(sm);

  std::cout << "Balancing MatrixLayer" << std::endl;
  sm.balance();
  printMatrixLayer(sm);

  return 0;
}
