#include "options.hpp"
#include <cmath>
#include <iterator>
#include <algorithm>
#include <sstream>
#include "Circles.hpp"
#include "Square.hpp"
#include "Triangle.hpp"

void optionOne()
{
  std::vector<double> vector{ std::istream_iterator<double>(std::cin), std::istream_iterator<double>() };
  if (!std::cin.eof()) 
  {
    throw std::invalid_argument("Invalid input");
  }
  if (vector.empty()) 
  {
    return;
  }
  std::transform(vector.begin(), vector.end(), vector.begin(),
    std::bind2nd(std::multiplies<double>(), M_PI));
  std::copy(vector.begin(), vector.end(), std::ostream_iterator<double>(std::cout, "\n"));
}


void optionTwo() 
{
  std::vector<std::shared_ptr<Shapes>> vector = createVector();
  std::cout << "Original:\n";
  std::for_each(vector.begin(), vector.end(),
    [](const std::shared_ptr<Shapes> shape) 
  {
    shape->draw(std::cout);
  });

  std::sort(vector.begin(), vector.end(),
    [](const std::shared_ptr<Shapes> &shape1, const std::shared_ptr<Shapes> &shape2) 
  {
    return shape1->isMoreLeft(*shape2);
  });
  std::cout << "Left-Right:\n";
  std::for_each(vector.begin(), vector.end(),
    [](const std::shared_ptr<Shapes> shape) 
  {
    shape->draw(std::cout);
  });
  std::cout << "Right-Left:\n";
  std::for_each(vector.rbegin(), vector.rend(),
    [](const std::shared_ptr<Shapes> shape) 
  {
    shape->draw(std::cout);
  });
  std::sort(vector.begin(), vector.end(),
    [](const std::shared_ptr<Shapes> shape1, const std::shared_ptr<Shapes> shape2) 
  {
    return (shape1->isUpper(*shape2));
  });
  std::cout << "Top-Bottom:\n";
  std::for_each(vector.begin(), vector.end(),
    [](const std::shared_ptr<Shapes> shape) 
  {
    shape->draw(std::cout);
  });
  std::cout << "Bottom-Top:\n";
  std::for_each(vector.rbegin(), vector.rend(),
    [](const std::shared_ptr<Shapes> shape) 
  {
    shape->draw(std::cout);
  });
}

std::vector<std::shared_ptr<Shapes>> createVector() 
{
  std::vector<std::shared_ptr<Shapes>> vector;
  std::string name;
  while (!(std::cin >> std::ws).eof()) 
  {
    char open_bracket = 0;
    char close_bracket = 0;
    char delimiter = 0;
    int x = 0;
    int y = 0;
    std::getline(std::cin, name);
    auto openBracketPos = name.find('(');
    if (openBracketPos == name.npos) 
    {
      throw std::invalid_argument("invalid input!");
    }
    else 
    {
      name.insert(openBracketPos, " ");
    }
    std::istringstream currentLine(name);
    currentLine.exceptions(std::istringstream::failbit | std::istringstream::badbit);
    currentLine >> std::skipws >> name >> open_bracket >> x
      >> delimiter >> y >> close_bracket;
    if (open_bracket != '(' || delimiter != ';' || close_bracket != ')' || !(currentLine >> std::ws).eof()) 
    {
      throw std::invalid_argument("invalid input");
    }
    if (name == "TRIANGLE") 
    {
      vector.emplace_back(std::make_shared<Triangle>(Triangle(x, y)));
    }
    else if (name == "SQUARE") 
    {
      vector.emplace_back(std::make_shared<Square>(Square(x, y)));
    }
    else if (name == "CIRCLE") 
    {
      vector.emplace_back(std::make_shared<Circles>(Circles(x, y)));
    }
    else 
    {
      throw std::invalid_argument("invalid input");
    }
  }
  return vector;
}
