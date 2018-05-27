#include <iostream>
#include <stdexcept>
#include "options.hpp"

int main(int argc, char** argv)
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Must be 1 argument" << std::endl;
      return 1;
    }
    switch (atoi(argv[1]))
    {
      case 1:
      {
        Option_1();
        break;
      }
      case 2:
      {
        Option_2();
        break;
      }
      default:
      {
        throw std::invalid_argument("Incorrect argument");
        break;
      }
    }
  }
  catch (std::exception &exc)
  {
    std::cerr << exc.what() << std::endl;
    return 2;
  }
  return 0;
}

