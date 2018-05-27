#include "options.hpp"
#include <sstream>
#include <numeric>

Shape getShape(const Line &line)
{
  std::stringstream stream(line);

  int n;
  stream >> n;

  Shape shape;

  for(int i = 0; i < n; i++)
  {
    Point point;
    stream.ignore(std::numeric_limits<std::streamsize>::max(), '(');
    stream >> point.x;

    stream.ignore(std::numeric_limits<std::streamsize>::max(), ';');
    stream >> point.y;

    stream.ignore(std::numeric_limits<std::streamsize>::max(), ')');
    shape.push_back(point);
  }

  if(stream.fail())
  {
    throw std::invalid_argument("invalid values");
  }

  std::string remLine;
  std::getline(stream, remLine);
  if(std::find_if(remLine.begin(), remLine.end(),
    [](char c) {return !std::isspace(c, std::locale()); }) != remLine.end())
  {
    throw std::invalid_argument("invalid input");
  }
  return shape;
}
bool isSquare(const Shape& shape)
{
  if (shape.size() != 4)
  {
    return false;
  }
  if (shape[1].x != shape[0].x)
  {
    if (std::abs(shape[1].x - shape[0].x) != std::abs(shape[2].y - shape[1].y))
    {
      return false;
    }
  }
  else
  {
    if (std::abs(shape[2].x - shape[1].x) != std::abs(shape[1].y - shape[0].y))
    {
      return false;
    }
  }
  return true;
}

void printP(const Point &p, std::ostream &output)
{
  output << " (" << p.x << ";" << p.y << ")";
}
void printShape(const Shape &shape, std::ostream &output)
{
  output << shape.size();
  std::for_each(shape.begin(), shape.end(), [&output](const Point &p) {printP(p, output); });
  output << "\n";
}
void second(std::istream &input, std::ostream &output)
{
  std::vector<Shape> shapes;

  std::transform(std::istream_iterator<Line>(input), std::istream_iterator<Line>(),
    std::back_inserter(shapes), getShape);

  int Vertices = std::accumulate(shapes.begin(), shapes.end(), 0,
                                 [](int ver, const Shape &sh){return ver + sh.size(); });
  output << "Vertices: " << Vertices << std::endl;

  int triangles = std::count_if(shapes.begin(), shapes.end(),
                                [](const Shape &sh){return sh.size() == 3; });
  output << "Triangles: " << triangles << std::endl;

  int squares = std::count_if(shapes.begin(), shapes.end(), isSquare);
  output << "Squares: " << squares << std::endl;

  int rectangles = std::count_if(shapes.begin(), shapes.end(),
                                [](const Shape &sh) {return sh.size() == 4; });
  output << "Rectangles: " << rectangles << std::endl;

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(),
    [](const Shape &sh) {return sh.size() == 5; }), shapes.end());

  std::vector<Point> points;
  std::transform(shapes.begin(), shapes.end(),
    std::back_inserter(points), [](const Shape &sh) {return sh.front(); });

  output << "Points:";
  std::for_each(points.begin(), points.end(), [&output](const Point &p) {printP(p, output); });
  output << std::endl;

  auto triangleEnd = std::partition(shapes.begin(), shapes.end(), [](const Shape &sh){return sh.size() == 3; });
  auto squareEnd = std::partition(triangleEnd, shapes.end(), isSquare);
  std::partition(squareEnd, shapes.end(), [](const Shape &sh){return sh.size() == 4; });

  output << "Shapes:" << std::endl;
  std::for_each(shapes.begin(), shapes.end(), [&output](const Shape &sh) {printShape(sh, output); });

}

