#include <iostream>
#include <stdexcept>
#include "detail.hpp"

int main (int argc, char** argv)
{
  if (argc < 2)
  {
    std::cerr << "Incorrect task argument" << std::endl;
    return '1';
  }
  try
  {
    switch (*argv[1])
    {
      case '1':
      if (argc == 3)
      {
        lab1_1(argv[2]);
      }
      else 
      {
        throw std::invalid_argument("Incorrect arguments for task 1");
      }
      break;
      case '2':
      if (argc == 3)
      {
        lab1_2(argv[2]);
      }
      else 
      {
        throw std::invalid_argument("Incorrect arguments for task 1");
      }
      break;
      case '3':
      if (argc == 2)
      {
        lab1_3();
      }
      else 
      {
        throw std::invalid_argument("Incorrect arguments for task 1");
      }
      break;
      case '4':
      if (argc == 4)
      {
        lab1_4(argv[2],argv[3]);
      }
      else 
      {
        throw std::invalid_argument("Incorrect arguments for task 1");
      }
      break;
      default:
      {
        std::cerr << "Invalid task number argument" << std::endl;
        return 1;

      }
    }
  }
  catch (std::exception & err)
  {
    std::cerr << err.what();
    return 1;
  }
  return 0;
}
