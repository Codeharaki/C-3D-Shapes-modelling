#include <iostream>
#include <stdexcept>
#include <vector>
#include <fstream>
#include <memory>

void lab1_2(const char* filename)
{
  std::vector<char> vect;
  std::ifstream file(filename);
  if(file.good() == 0)
  {
    throw std::invalid_argument("file Opens");
  }
  if(!file)
  {
    throw std::ios_base::failure("File doesn't exist/Open");
  }

  if (file)
  {
    file.seekg(0, file.end);
    size_t size = file.tellg();
    file.seekg(0, file.beg);
    if (size == 0)
    {
      exit(0);
    }
    std::unique_ptr<char[]> data(new char[size]);
    file.read(data.get(), size);
    file.close();
    std::vector<char>vector (data.get(), data.get() + size);
    for (size_t j = 0; j < vector.size(); j++)
    {
      std::cout << vector[j];
    }
  }
}
