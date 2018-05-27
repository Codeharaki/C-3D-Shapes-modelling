#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <math.h>
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "CompositeShape.hpp"

const double EPSILON = 0.001;

BOOST_AUTO_TEST_SUITE(simple_shapes)
BOOST_AUTO_TEST_CASE(rectangle_move_dxy)
{
  Rectangle r({ -9, 27 }, 15, 29);
  const double width_before = r.getFrameRect().width;
  const double height_before = r.getFrameRect().height;
  const double area_before = r.getArea();
  r.move(6.66, 32.38);
  BOOST_CHECK_CLOSE(width_before, r.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(height_before, r.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(area_before, r.getArea(), EPSILON);
}
BOOST_AUTO_TEST_CASE(rectangle_move_point)
{
  Rectangle r({ -91, 127.4 }, 15.8, 1.29);
  const double width_before = r.getFrameRect().width;
  const double height_before = r.getFrameRect().height;
  const double area_before = r.getArea();
  r.move({ 1.81, -57.11 });
  BOOST_CHECK_CLOSE(width_before, r.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(height_before, r.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(area_before, r.getArea(), EPSILON);
}
BOOST_AUTO_TEST_CASE(rectangle_scale)
{
  Rectangle r({ 13,18 }, 8, 5);
  const double area_before = r.getArea();
  const double k = 1.8;
  r.scale(k);
  BOOST_CHECK_CLOSE(area_before * k * k, r.getArea(), EPSILON);
}
BOOST_AUTO_TEST_CASE(rectangle_invalid_constructor)
{
  BOOST_CHECK_THROW(Rectangle({ 1, 1 }, -1, 0), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(rectangle_invalid_scale)
{
  Rectangle r({ 1, 5 }, 10, 12);
  BOOST_CHECK_THROW(r.scale(0), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(rectangle_rotate_const_area)
{
  Rectangle r({ 1, 7 }, 5, 41);
  const double area_before = r.getArea();
  r.rotate({ 82 });
  BOOST_CHECK_CLOSE(area_before, r.getArea(), EPSILON);
}
BOOST_AUTO_TEST_CASE(rectangle_rotate_const_center)
{
  Rectangle r({ 1, 7 }, 5, 41);
  const point_t pos_before = r.getFrameRect().pos;
  r.rotate({ -56 });
  const point_t newPos = r.getFrameRect().pos;
  BOOST_CHECK_CLOSE(pos_before.x, newPos.x, EPSILON);
  BOOST_CHECK_CLOSE(pos_before.y, newPos.y, EPSILON);
}
BOOST_AUTO_TEST_CASE(rectangle_rotate_360_const)
{
  Rectangle r({ 1, 7 }, 5, 41);
  const rectangle_t frame_before = r.getFrameRect();
  r.rotate({ 360 });
  rectangle_t newFrame = r.getFrameRect();
  BOOST_CHECK_CLOSE(frame_before.pos.x, newFrame.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(frame_before.pos.y, newFrame.pos.y, EPSILON);
  BOOST_CHECK_CLOSE(frame_before.height, newFrame.height, EPSILON);
  BOOST_CHECK_CLOSE(frame_before.width, newFrame.width, EPSILON);
}
BOOST_AUTO_TEST_CASE(rectangle_rotate_90)
{
  Rectangle r({ 1, 7 }, 5, 41);
  const rectangle_t frame_before = r.getFrameRect();
  r.rotate({ 90 });
  rectangle_t newFrame = r.getFrameRect();
  BOOST_CHECK_CLOSE(frame_before.height, newFrame.height, EPSILON);
  BOOST_CHECK_CLOSE(frame_before.width, newFrame.width, EPSILON);
}
BOOST_AUTO_TEST_CASE(circle_move_dxy)
{
  Circle c({ -9, 27 }, 20);
  const double width_before = c.getFrameRect().width;
  const double height_before = c.getFrameRect().height;
  const double area_before = c.getArea();
  c.move(5.51, 0);
  BOOST_CHECK_CLOSE(width_before, c.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(height_before, c.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(area_before, c.getArea(), EPSILON);
}
BOOST_AUTO_TEST_CASE(circle_move_point)
{
  Circle c({ -91, 127.4 }, 2);
  const double width_before = c.getFrameRect().width;
  const double height_before = c.getFrameRect().height;
  const double area_before = c.getArea();
  c.move({ 1.81, -57.11 });
  BOOST_CHECK_CLOSE(width_before, c.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(height_before, c.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(area_before, c.getArea(), EPSILON);
}

BOOST_AUTO_TEST_CASE(circle_invalid_constructor)
{
  BOOST_CHECK_THROW(Circle({ 1, 1 }, -10), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(circle_invalid_scale)
{
  Circle c({ 1, 5 }, 5);
  BOOST_CHECK_THROW(c.scale(-2), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(triangle_move_dxy)
{
  Triangle t({ -9, 27 }, { 1,-1 }, { 15,81 });
  const double width_before = t.getFrameRect().width;
  const double height_before = t.getFrameRect().height;
  const double area_before = t.getArea();
  t.move(-3.316, 1.257);
  BOOST_CHECK_CLOSE(width_before, t.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(height_before, t.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(area_before, t.getArea(), EPSILON);
}
BOOST_AUTO_TEST_CASE(triangle_move_point)
{
  Triangle t({ -11, 2.7 }, { -5, -21 }, { 8.44, 91.666 });
  const double width_before = t.getFrameRect().width;
  const double height_before = t.getFrameRect().height;
  const double area_before = t.getArea();
  t.move({ 45.8, -3.38 });
  BOOST_CHECK_CLOSE(width_before, t.getFrameRect().width, EPSILON);
  BOOST_CHECK_CLOSE(height_before, t.getFrameRect().height, EPSILON);
  BOOST_CHECK_CLOSE(area_before, t.getArea(), EPSILON);
}
BOOST_AUTO_TEST_CASE(triangle_scale)
{
  Triangle t({ 13,18 }, { 5, 22 }, { 12, 2 });
  const double area_before = t.getArea();
  const double k = 1.82;
  t.scale(k);
  BOOST_CHECK_CLOSE(area_before * k * k, t.getArea(), EPSILON);
}
BOOST_AUTO_TEST_CASE(triangle_invalid_constructor)
{
  BOOST_CHECK_THROW(Triangle({ 1, 1 }, { 1, 1 }, { 5, 0 }), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(triangle_invalid_scale)
{
  Triangle t({1,12},{3,3},{1,23});
  BOOST_CHECK_THROW(t.scale(-15), std::invalid_argument);
}
BOOST_AUTO_TEST_CASE(triangle_rotate_const_area)
{
  Triangle t({1,12},{3,3},{1,23});
  const double area_before = t.getArea();
  t.rotate({ 182 });
  BOOST_CHECK_CLOSE(area_before, t.getArea(), EPSILON);
}
BOOST_AUTO_TEST_CASE(triangle_rotate_const_center)
{
  Triangle t({1,12},{3,3},{1,23});
  const point_t pos_before = t.getFrameRect().pos;
  t.rotate({ -56 });
  const point_t newPos = t.getFrameRect().pos;
  BOOST_CHECK_CLOSE(pos_before.x, newPos.x, EPSILON);
  BOOST_CHECK_CLOSE(pos_before.y, newPos.y, EPSILON);
}
BOOST_AUTO_TEST_CASE(triangle_rotate_360_const)
{
  Triangle t({1,12},{3,3},{1,23});
  const rectangle_t frame_before = t.getFrameRect();
  t.rotate({ 360 });
  rectangle_t newFrame = t.getFrameRect();
  BOOST_CHECK_CLOSE(frame_before.pos.x, newFrame.pos.x, EPSILON);
  BOOST_CHECK_CLOSE(frame_before.pos.y, newFrame.pos.y, EPSILON);
  BOOST_CHECK_CLOSE(frame_before.height, newFrame.height, EPSILON);
  BOOST_CHECK_CLOSE(frame_before.width, newFrame.width, EPSILON);
}
BOOST_AUTO_TEST_CASE(triangle_rotate_90)
{
  Triangle t({1,12},{3,3},{1,23});
  const rectangle_t frame_before = t.getFrameRect();
  t.rotate({ 90 });
  rectangle_t newFrame = t.getFrameRect();
  BOOST_CHECK_CLOSE(frame_before.height, newFrame.width, EPSILON);
  BOOST_CHECK_CLOSE(frame_before.width, newFrame.height, EPSILON);
}

BOOST_AUTO_TEST_SUITE_END()
