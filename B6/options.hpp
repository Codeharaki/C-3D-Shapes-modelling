#define OPTION_HPP
#ifdef OPTION_HPP

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <string>
#include <vector>

struct Point
{
  int x, y;
};

using Shape = std::vector< Point >;

class Line : public std::string
{
  friend std::istream& operator>>(std::istream &instr, Line &line)
  {
    while(std::getline(instr, line))
    {
      if(line.empty())
      {
        continue;
      }
      if(std::find_if(line.begin(), line.end(),
        [](char c) {return !std::isspace(c, std::locale()); }) != line.end())
      {
        break;
      }
    }
    return instr;
  }
};

void first(std::istream &input, std::ostream &output);
void second(std::istream &input, std::ostream &output);

#endif // OPTION_HPP
