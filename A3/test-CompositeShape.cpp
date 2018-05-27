#include <boost/test/unit_test.hpp>
#include "rectangle.hpp"
#include "circle.hpp"
#include "triangle.hpp"
#include "CompositeShape.hpp"

const double EPSILON= 0.001;

BOOST_AUTO_TEST_SUITE(test_creating)
BOOST_AUTO_TEST_CASE(rectangle)
{
  Rectangle rect({20,10},15,50);
  CompositeShape compo;
  compo.addShape(rect);
  BOOST_CHECK_CLOSE(rect.getArea(),compo.getArea(),EPSILON);
}
BOOST_AUTO_TEST_CASE(creating_circle)
{
  Circle circ({20,30},13);
  CompositeShape compo;
  compo.addShape(circ);
  BOOST_CHECK_CLOSE(circ.getArea(),compo.getArea(),EPSILON);
}
BOOST_AUTO_TEST_CASE(creating_triangle)
{
  Triangle trian({12,-12},{13,5},{1,23});
  CompositeShape compo;
  compo.addShape(trian);
  BOOST_CHECK_CLOSE(trian.getArea(),compo.getArea(),EPSILON);
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(test_addingForms)
BOOST_AUTO_TEST_CASE(circle_to_circle)
{
  Circle circ({20,30},13);
  CompositeShape compo;
  compo.addShape(circ);
  Circle circ2({8,10},4);
  compo.addShape(circ2);
  BOOST_CHECK_CLOSE(compo.getArea(),circ.getArea()+circ2.getArea(),EPSILON);
}
BOOST_AUTO_TEST_CASE(rectangle_to_rectangle)
{
  Rectangle rect({20,10},15,50);
  CompositeShape compo;
  compo.addShape(rect);
  Rectangle rect2({2,3},4,7);
  compo.addShape(rect2);
  BOOST_CHECK_CLOSE(compo.getArea(),rect.getArea()+rect2.getArea(),EPSILON);
}

BOOST_AUTO_TEST_CASE(triangle_to_triangle)
{
  Triangle trian({12,-12},{13,5},{1,23});
  CompositeShape compo;
  compo.addShape(trian);
  Triangle trian_2({15,-13},{14,5},{2,24});
  compo.addShape(trian_2);
  BOOST_CHECK_CLOSE(compo.getArea(),trian.getArea()+trian_2.getArea(),EPSILON);
}
BOOST_AUTO_TEST_CASE(add_shapes)
{
  Rectangle rect({20,10},15,50);
  Circle circ({20,30},13);
  Triangle trian({12,-12},{13,5},{1,23});
  CompositeShape compo;
  compo.addShape(rect);
  compo.addShape(circ);
  compo.addShape(trian);
  BOOST_CHECK_CLOSE(rect.getArea()+circ.getArea()+trian.getArea(),compo.getArea(),EPSILON);
}
BOOST_AUTO_TEST_CASE(circle_to_rectangle)
{
  Circle circ({20,30},13);
  Rectangle rect({20,10},15,50);
  CompositeShape compo;
  compo.addShape(rect);
  compo.addShape(circ);
  BOOST_CHECK_CLOSE(rect.getArea()+circ.getArea(),compo.getArea(),EPSILON);
}
BOOST_AUTO_TEST_CASE(triangle_to_rectangle)
{
  Rectangle rect({20,10},15,50);
  Triangle trian({12,-12},{13,5},{1,23});
  CompositeShape compo;
  compo.addShape(rect);
  compo.addShape(trian);
  BOOST_CHECK_CLOSE(rect.getArea()+trian.getArea(),compo.getArea(),EPSILON);
}
BOOST_AUTO_TEST_CASE(rectangle_to_circle)
{
  Rectangle rect({20,10},15,50);
  Circle circ({20,30},13);
  CompositeShape compo;
  compo.addShape(rect);
  compo.addShape(circ);
  BOOST_CHECK_CLOSE(rect.getArea()+circ.getArea(),compo.getArea(),EPSILON);
}
BOOST_AUTO_TEST_CASE(rectangle_to_triangle)
{
  Rectangle rect({20,10},15,50);
  Triangle trian({12,-12},{13,5},{1,23});
  CompositeShape compo;
  compo.addShape(rect);
  compo.addShape(trian);
  BOOST_CHECK_CLOSE(rect.getArea()+trian.getArea(),compo.getArea(),EPSILON);
}
BOOST_AUTO_TEST_CASE(triangle_to_circle)
{
  Circle circ({20,30},13);
  Triangle trian({12,-12},{13,5},{1,23});
  CompositeShape compo;
  compo.addShape(circ);
  compo.addShape(trian);
  BOOST_CHECK_CLOSE(circ.getArea()+trian.getArea(),compo.getArea(),EPSILON);
}
BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE(test_move_scale)
BOOST_AUTO_TEST_CASE(move_d)
{
  Circle circ({20,30},13);
  Rectangle rect({20,10},15,50);
  Triangle trian({12,-12},{13,5},{1,23});
  CompositeShape compo;
  compo.addShape(trian);
  compo.addShape(rect);
  compo.addShape(circ);
  const double areaOriginal= compo.getArea();
  const rectangle_t frameOriginal= compo.getFrameRect();
  compo.move(2,3.5);
  BOOST_CHECK_CLOSE(compo.getFrameRect().height,frameOriginal.height,EPSILON);
  BOOST_CHECK_CLOSE(compo.getFrameRect().width,frameOriginal.width,EPSILON);
  BOOST_CHECK_CLOSE(compo.getArea(),areaOriginal,EPSILON);

}
BOOST_AUTO_TEST_CASE(move_point)
{
  Circle circ({20,30},13);
  Rectangle rect({20,10},15,50);
  Triangle trian({12,-12},{13,5},{1,23});
  CompositeShape compo;
  compo.addShape(trian);
  compo.addShape(rect);
  compo.addShape(circ);
  const double areaOriginal= compo.getArea();
  const rectangle_t frameOriginal= compo.getFrameRect();
  point_t new_p({9,8});
  compo.move(new_p);
  BOOST_CHECK_CLOSE(compo.getFrameRect().height,frameOriginal.height,EPSILON);
  BOOST_CHECK_CLOSE(compo.getFrameRect().width,frameOriginal.width,EPSILON);
  BOOST_CHECK_CLOSE(compo.getArea(),areaOriginal,EPSILON);
}
BOOST_AUTO_TEST_CASE(scale)
{
  Circle circ({20,30},13);
  Rectangle rect({20,10},15,50);
  Triangle trian({12,-12},{13,5},{1,23});
  CompositeShape compo;
  compo.addShape(trian);
  compo.addShape(rect);
  compo.addShape(circ);
  const double areaOriginal= compo.getArea();
  const double k= 2;
  compo.scale(k);
  BOOST_CHECK_CLOSE(compo.getArea(),areaOriginal*k*k,EPSILON);
}

BOOST_AUTO_TEST_CASE(frame_shapes)
{
  Rectangle rect({20,10},15,50);
  Circle circ({20,30},13);
  CompositeShape compo;
  compo.addShape(rect);
  compo.addShape(circ);

  BOOST_CHECK_CLOSE(compo.getFrameRect().width,26,EPSILON);
  BOOST_CHECK_CLOSE(compo.getFrameRect().height,58,EPSILON);
}
BOOST_AUTO_TEST_CASE(invalid_scale)
{
  Rectangle rect({20,10},15,50);
  Circle circ({20,30},13);
  Triangle trian({12,-12},{13,5},{1,23});
  CompositeShape compo;
  compo.addShape(trian);
  compo.addShape(rect);
  compo.addShape(circ);
  BOOST_CHECK_THROW(compo.scale(-5), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
