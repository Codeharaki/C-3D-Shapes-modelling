#include <iostream>
#include <string>
#include "source.hpp"

int main(int args, char *argv[])
{
  if (args != 2)
  {
    std::cerr << "number of arguments is false";
    return 1;
  }

  try
  {
    switch (std::stoi(argv[1]))
    {
      case 1:
        type_1();
        break;
      case 2:
        type_2();
        break;
      default:
        std::cerr << "Invalid arguments";
        return 1;
    }
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << e.what();
    return 1;
  }
  catch (const std::out_of_range &e)
  {
    std::cerr << e.what();
    return 1;
  }
  return 0;
}


