#include <iostream>
#include <string>
#include <stdexcept>
#include "options.hpp"

using namespace std;

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cerr<<"invalid  arguments";
    return 1;
  }
  try
  {
    switch (std::stoi(argv[1]))
    {
      case 1:
      {
        first(std::cin, std::cout);
        break;
      }
      case 2:
      {
        second(std::cin, std::cout);
        break;
      }
      default:
      {
        std::cerr<<"incorrect argument";
        return 2;
      }
    }
  }
  catch(std::invalid_argument &ex)
  {
    std::cerr<<ex.what();
    return 1;
  }
  return 0;
}
