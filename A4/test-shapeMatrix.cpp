#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <math.h>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "CompositeShape.hpp"
#include "Matrix-layer.hpp"

const double EPSILON = 0.001;

BOOST_AUTO_TEST_SUITE(MatrixLayer_tests)
BOOST_AUTO_TEST_CASE(MatrixLayer_addShape)
{
  MatrixLayer sm;
  BOOST_CHECK(sm.size() == 0);
  sm.addShape(Circle({ 2,2 }, 4));
  BOOST_CHECK(sm.size() == 1);
  BOOST_CHECK(sm[0].size() == 1);
}
BOOST_AUTO_TEST_CASE(MatrixLayer_matching_shape)
{
  Circle c({ 11,4 }, 8);
  MatrixLayer sm;
  sm.addShape(c);
  BOOST_CHECK_CLOSE(sm[0][0].getArea(), c.getArea(), EPSILON);
}
BOOST_AUTO_TEST_CASE(MatrixLayer_removeShape)
{
  Circle c({ 11,4 }, 8);
  MatrixLayer sm;
  sm.addShape(c);
  sm.removeShape(0, 0);
  BOOST_CHECK(sm.size() == 0);
}
BOOST_AUTO_TEST_CASE(MatrixLayer_layers)
{
  Circle c1({ 1,1 }, 5);
  Circle c2({ 2,2 }, 10); 
  Circle c3({ 15,15 }, 1); 

  MatrixLayer sm;
  sm.addShape(c2);
  sm.addShape(c1);
  sm.addShape(c3);
  sm.addShape(c3);
  sm.addShape(c2);
  BOOST_CHECK_CLOSE(sm[0][0].getArea(), c2.getArea(), EPSILON);
  
}

BOOST_AUTO_TEST_CASE(MatrixLayer_assignment)
{
  Circle c1({ 1,1 }, 14);
  Circle c2({ 4,4 }, 10);
  MatrixLayer sm1;
  sm1.addShape(c1);
  sm1.addShape(c2);
  MatrixLayer sm2;
  sm2 = sm1;
  BOOST_CHECK(sm1.size() == sm2.size());
  BOOST_CHECK_CLOSE(sm1[0][0].getArea(), sm2[0][0].getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(MatrixLayer_self_assignment)
{
  Circle c1({ 1,1 }, 14);
  Circle c2({ 4,4 }, 10);
  MatrixLayer sm1;
  sm1.addShape(c1);
  sm1.addShape(c2); 
  sm1 = sm1;
  BOOST_CHECK_CLOSE(sm1[0][0].getArea(), c1.getArea(), EPSILON);

}
BOOST_AUTO_TEST_CASE(MatrixLayer_multiple_assignment)
{
  Circle c1({ 1,1 }, 14);
  MatrixLayer sm1;
  MatrixLayer sm2;
  MatrixLayer sm3;
  sm3.addShape(c1);

  sm1 = sm2 = sm3;
  BOOST_CHECK(sm1.size() == 1);
  BOOST_CHECK(sm2.size() == 1);
  BOOST_CHECK_CLOSE(sm1[0][0].getArea(), sm3[0][0].getArea(), EPSILON);
  BOOST_CHECK_CLOSE(sm2[0][0].getArea(), sm3[0][0].getArea(), EPSILON);
}
BOOST_AUTO_TEST_CASE(MatrixLayer_copy_constructor)
{
  Circle c1({ 1,1 }, 14);
  MatrixLayer sm1;
  sm1.addShape(c1);
  MatrixLayer sm2(sm1);
  BOOST_CHECK(sm2.size() == 1);
  BOOST_CHECK_CLOSE(sm2[0][0].getArea(), c1.getArea(), EPSILON);
}
BOOST_AUTO_TEST_CASE(MatrixLayer_move_assignment)
{
  Circle c1({ 1,1 }, 14);
  MatrixLayer sm1;
  sm1.addShape(c1);
  MatrixLayer sm2;
  sm2 = std::move(sm1);

  BOOST_CHECK(sm1.size() == 0);
  BOOST_CHECK(sm2.size() == 1);
  BOOST_CHECK_CLOSE(sm2[0][0].getArea(), c1.getArea(), EPSILON);
}
BOOST_AUTO_TEST_CASE(MatrixLayer_move_constructor)
{
  Circle c1({ 1,1 }, 14);
  MatrixLayer sm1;
  sm1.addShape(c1);
  MatrixLayer sm2(std::move(sm1));

  BOOST_CHECK(sm1.size() == 0);
  BOOST_CHECK(sm2.size() == 1);
  BOOST_CHECK_CLOSE(sm2[0][0].getArea(), c1.getArea(), EPSILON);
}
BOOST_AUTO_TEST_CASE(MatrixLayer_operator_out_of_range)
{
  MatrixLayer sm;
  sm.addShape(Circle({ 1,2 }, 3));
  BOOST_CHECK_THROW(sm[5][10], std::out_of_range);
}
BOOST_AUTO_TEST_CASE(MatrixLayer_removeShape_out_of_range)
{
  MatrixLayer sm;
  BOOST_CHECK_THROW(sm.removeShape(0, 0), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(MatrixLayer_compositeShape_decomposition_1)
{
  CompositeShape cs;
  cs.addShape(Circle({ 4,6 }, 4));
  cs.addShape(Rectangle({ 5,8 }, 4, 6));
  cs.addShape(Circle({ 15,15 }, 1));

  MatrixLayer sm;
  sm.addCompositeShapeElements(cs);

  BOOST_CHECK_CLOSE(sm[0][0].getArea(), cs[0].getArea(), EPSILON);
 
}
BOOST_AUTO_TEST_CASE(MatrixLayer_compositeShape_decomposition_2)
{
  CompositeShape cs;
  cs.addShape(Circle({ 0,0 }, 1));
  cs.addShape(Circle({ 0,0 }, 1));
  cs.addShape(Circle({ 5,5 }, 2));
  cs.addShape(Circle({ 5,5 }, 2));
  cs.addShape(Circle({ 10,10 }, 3));
  cs.addShape(Circle({ 10,10 }, 3));

  MatrixLayer sm;
  sm.addCompositeShapeElements(cs);
  BOOST_CHECK_CLOSE(sm[0][0].getArea(), cs[0].getArea(), EPSILON);
 
}

BOOST_AUTO_TEST_SUITE_END()
