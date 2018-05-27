#include <iostream>
#include <stdexcept>
#include <vector>
#include <random>
#include <ctime>
#include <cmath>
#include <cstring>
#include "detail.hpp"

void fillRandom(double * array, int size)
{
  std::mt19937 rng(std::random_device{}());
  std::uniform_real_distribution<double> distr (-1.0, 1.0);
  for (int i = 0; i < size; ++i)
  {
    array[i] = distr(rng);
  }
}
void lab1_4(const char* array_direction, const char* array_size)
{
  bool (*pt_comp) (double&,double&);
  int size = atoi(array_size);
  if (size == 0)
  {
    throw std::invalid_argument("Incorrect array size.");
  }
  std::vector<double> vector (size);
  if(!vector.empty())
  {
    fillRandom(&vector[0],size);
    if (std::strcmp(array_direction,"ascending")==0)
    {
      pt_comp =detail::accending;
    } 
    else if (std::strcmp(array_direction,"descending")==0)
    {
      pt_comp = detail::descending;
    } 
    else 
    {
      throw std::invalid_argument("Incorrect sorting direction.");
    }
  detail::printCont<std::vector<double> >(vector);
  detail::sort<detail::brackets_sort,std::vector<double> >(vector,pt_comp);
  detail::printCont<std::vector<double> >(vector);
  }
}
