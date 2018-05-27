#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include <stdexcept>

const double EPSILON= 0.001;
BOOST_AUTO_TEST_SUITE(rectangle)

BOOST_AUTO_TEST_CASE(create_rectangle)
{
  BOOST_CHECK_THROW(Rectangle({ -23, -5 }, 2, -35), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(changing_Scale)
{
  Rectangle rect({ 11, 23 }, 5, 50);
  const double R = -12;
  BOOST_CHECK_THROW(rect.scale(R), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(Moving_by_dx_dy)
{
  Rectangle rect({ -20, 10 }, 15, 50);
  const double width_original_d = rect.getFrameRect().width;
  const double height_original_d = rect.getFrameRect().height;
  const double area_original_d = rect.getArea();
  rect.move(10, -30);
  BOOST_CHECK_EQUAL(width_original_d, rect.getFrameRect().width);
  BOOST_CHECK_EQUAL(height_original_d, rect.getFrameRect().height);
  BOOST_CHECK_CLOSE(area_original_d, rect.getArea() ,EPSILON);
}

BOOST_AUTO_TEST_CASE(Moving_by_point)
{
  Rectangle rect({ 20, 10 }, 15, 50);
  const double width_original = rect.getFrameRect().width;
  const double height_original = rect.getFrameRect().height;
  const double area_original = rect.getArea();
  rect.move({ -27, 52 });
  BOOST_CHECK_EQUAL(width_original, rect.getFrameRect().width);
  BOOST_CHECK_EQUAL(height_original, rect.getFrameRect().height);
  BOOST_CHECK_CLOSE(area_original, rect.getArea(),EPSILON);
}
BOOST_AUTO_TEST_CASE(Scaling)
{
  Rectangle rect({ 20, 10 }, 15, 50);
  const double area_original = rect.getArea();
  const double R = 1.2;
  rect.scale(R);
  BOOST_CHECK_CLOSE(area_original * R * R, rect.getArea(), EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(circle)
BOOST_AUTO_TEST_CASE(invalid_Initialisation)
{
  BOOST_CHECK_THROW(Circle ({ 23, -5 }, -7), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(invalid_Scale)
{
  Circle circ({ 1, 1 }, 5);
  const double C=-15;
  BOOST_CHECK_THROW(circ.scale(C), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(Move_dx_dy)
{
  Circle circ ({20,30},13);
  const double width_original = circ.getFrameRect().width;
  const double height_original = circ.getFrameRect().height;
  const double area_original = circ.getArea();
  circ.move(-12, 9);
  BOOST_CHECK_EQUAL(width_original, circ.getFrameRect().width);
  BOOST_CHECK_EQUAL(height_original, circ.getFrameRect().height);
  BOOST_CHECK_CLOSE(area_original, circ.getArea(),EPSILON);
}
BOOST_AUTO_TEST_CASE(move_point)
{
  Circle circ({ 20, 30 }, 13);
  const double width_original = circ.getFrameRect().width;
  const double height_original = circ.getFrameRect().height;
  const double area_original = circ.getArea();
  circ.move({ 32, -6 });
  BOOST_CHECK_EQUAL(width_original, circ.getFrameRect().width);
  BOOST_CHECK_EQUAL(height_original, circ.getFrameRect().height);
  BOOST_CHECK_CLOSE(area_original, circ.getArea(),EPSILON);
}
BOOST_AUTO_TEST_CASE(Scaling)
{
  Circle circ({ 20, 30 }, 13);
  const double area_original = circ.getArea();
  const double C = 0.9;
  circ.scale(C);
  BOOST_CHECK_CLOSE(area_original * C * C, circ.getArea(),EPSILON);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(triangle)
BOOST_AUTO_TEST_CASE(invalid_Initialisation)
{
  BOOST_CHECK_THROW(Triangle({1,-12},{-13,2},{1,3}), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(invalid_Scale)
{
  Triangle tria ({12,-12},{13,5},{1,23});
  const double T=-19;
  BOOST_CHECK_THROW(tria.scale(T), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(Move_dx_dy)
{
  Triangle tria({ 12, -12 }, { 13, 5 }, { 1, 23 });
  const double width_original = tria.getFrameRect().width;
  const double height_original = tria.getFrameRect().height;
  const double area_original = tria.getArea();
  tria.move(10, 20);
  BOOST_CHECK_EQUAL(width_original, tria.getFrameRect().width);
  BOOST_CHECK_EQUAL(height_original, tria.getFrameRect().height);
  BOOST_CHECK_CLOSE(area_original, tria.getArea(), EPSILON);
  
}

BOOST_AUTO_TEST_CASE(move_point)
{
  Triangle tria ({12,-12},{13,5},{1,23});
  const double width_original = tria.getFrameRect().width;
  const double height_original = tria.getFrameRect().height;
  const double area_original = tria.getArea();
  tria.move({ -7, 4 });
  BOOST_CHECK_EQUAL(width_original, tria.getFrameRect().width);
  BOOST_CHECK_EQUAL(height_original, tria.getFrameRect().height);
  BOOST_CHECK_CLOSE(area_original, tria.getArea(), EPSILON);
}
BOOST_AUTO_TEST_CASE(Scaling)
{
  Triangle tria ({12,-12},{13,5},{1,23});
  const double area_original = tria.getArea();
  const double T = 1.63;
  tria.scale(T);
  BOOST_CHECK_CLOSE(area_original * T * T, tria.getArea(), EPSILON); 
}

BOOST_AUTO_TEST_SUITE_END()
