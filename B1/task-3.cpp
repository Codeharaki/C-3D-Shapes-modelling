#include <iostream>
#include <stdexcept>
#include <vector>
#include "detail.hpp"

void lab1_3()
{ 
  std::vector<int> vec;
  int element ;
  while(std::cin >> element)
  {
    vec.push_back(element);
  }
  if(std::cin.fail() && !std::cin.eof())
  {
    throw std::invalid_argument("Incorrect integer type");
  }
  if(!vec.empty())
  {
    if(vec.back() != 0)
    {
      throw std::invalid_argument("expected zero before end of input");
    }
    else
    {
      vec.pop_back();
    }
  }
  
  if(!vec.empty())
  {
    std::vector<int>::iterator it = vec.begin();
    if (vec.back() == 1)
    {
      while (it != vec.end())
      {
        if (*it % 2 == 0)
        {
          it = vec.erase(it);
        } 
        else 
        {
          it++;
        }
      }
    } 
    else if (vec.back() == 2)
    {
      while (it != vec.end())
      {
        if (*it % 3 == 0)
        {
          it = vec.insert(++it,3,1);
          it +=2;
        }
        it++;
      }
    }
  }
  detail::printCont(vec);
}

