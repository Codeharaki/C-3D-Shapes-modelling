#include <cstring>
#include "options.hpp"
#include <iostream>

int main(int argc, char *argv[]) 
{
  if (argc != 2) 
  {
    std::cerr << "Invalid input";
    return 1;
  }
  else 
  {
    try 
    {
      if (std::strcmp(argv[1], "1") == 0) 
      {
        optionOne();
        return 0;
      }
      else 
        if (std::strcmp(argv[1], "2") == 0) 
        {
        optionTwo();
        return 0;
      }
      else 
      {
        std::cerr << "Invalid input";
        return 1;
      }
    }
    catch (const std::exception &exception) 
    {
      std::cerr << exception.what() << std::endl;
      return 1;
    }
    return 0;
  }
}
