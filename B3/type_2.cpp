#include "source.hpp"
#include <list>

void type_2()
{
  std::list<int> data;

  int Value;
  while (std::cin >> Value)
  {
    if ((Value < 1) || (Value > 20))
    {
      throw std::out_of_range("Value should be from 1 to 20");
    }
    data.push_back(Value);
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    throw std::invalid_argument("incorrect input");
  }
  if (data.empty())
  {
    return;
  }
  if (data.size() > 20)
  {
    throw std::invalid_argument("the number of elements must be less than 20");
  }

  auto it_next = data.begin();
  auto it_prev = data.rbegin();

  for (size_t i = 0; i < data.size()/2; ++i)
  {
    std::cout << *it_next << " " << *it_prev << " ";
    it_next++;
    it_prev++;
  }
  if ( data.size()%2 == 1)
  {
    std::cout << *it_next;
  }
  std::cout << std::endl;

}
