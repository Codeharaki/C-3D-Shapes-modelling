#include "algorithm.hpp"
#include <sstream>

DataStruct giveEle(const std::string &input)
{
  DataStruct tmp;
  std::istringstream s_in(input);
  tmp.key1 = 0;
  tmp.key2 = 0;

  s_in >> tmp.key1;
  s_in.ignore(input.length(), ',');
  s_in >> tmp.key2;
  s_in.ignore(input.length(), ',');
  std::getline(s_in, tmp.str);
  if (s_in.fail() || (tmp.key1 > 5) || (tmp.key1 < -5) || (tmp.key2 > 5) || (tmp.key2 < -5) || tmp.str.empty())
  {
    throw std::invalid_argument("Invalid input");
  }
  return tmp;

}
void makeVector(std::vector<DataStruct>& arr)
{
  std::string line;
  while (std::getline(std::cin, line))
  {
    const auto temp = giveEle(line);
    arr.push_back(temp);
  }
}

bool cmp(const DataStruct &data_1, const DataStruct &data_2)
{
  if (data_1.key1 < data_2.key1)
  {
    return true;
  }
  if (data_1.key1 == data_2.key1)
  {
    if (data_1.key2 == data_2.key2)
    {
      if (data_1.str.size() == data_2.str.size())
      {
        return (data_1.str < data_2.str);
      }
      return (data_1.str.size() < data_2.str.size());
    }
    return (data_1.key2 < data_2.key2);
  }
  return false;
}

void sortingVector(std::vector<DataStruct>& arr)
{
  std::sort(arr.begin(), arr.end(), cmp);
}

