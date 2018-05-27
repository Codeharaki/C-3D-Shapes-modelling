#include "algorithm.hpp"

int main()
{
  std::vector<DataStruct> data;
  try
  {
    makeVector(data);
    sortingVector(data);

    for (auto ite :data)
    {
      std::cout<< ite.key1 << "," << ite.key2 << "," << ite.str << std::endl;
    }
  }
  catch (std::exception &exc)
  {
    std::cerr << exc.what();
    return 1;
  }
  return 0;
}

