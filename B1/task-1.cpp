#include <iostream>
#include <stdexcept>
#include <vector>
#include <forward_list>
#include <stdlib.h>
#include <cstring>
#include "detail.hpp"

void lab1_1 (const char* array_direction)
{
  std::vector<int> first_Vector;
  int element=0;
  while (std::cin >> element)
  {
    first_Vector.push_back(element);
  }
  if (!std::cin.eof() && std::cin.fail())
  {
    throw std::ios_base::failure("Invalid elements input");
  }

  bool (*order) (int&,int&) = 0;
  if (std::strcmp(array_direction,"ascending")==0)
  {
    order =detail::accending;
  }
  else if(std::strcmp(array_direction,"descending")==0)
  {
    order =detail::descending;
  }
  else
  {
    throw std::invalid_argument("Wrong Sorting Order");  
  }
  std::vector<int> second_Vector = first_Vector;
  std::forward_list<int> list1 (first_Vector.begin(),first_Vector.end()); 
  
  detail::sort <detail::brackets_sort,std::vector<int> >(first_Vector,order);
  detail::printCont<std::vector<int> >(first_Vector);
  
  detail::sort <detail::at_sort,std::vector<int> >(second_Vector,order);
  detail::printCont<std::vector<int> >(second_Vector);

  detail::sort <detail::iterator_sort,std::forward_list<int> >(list1,order);
  detail::printCont<std::forward_list<int> >(list1);
}
