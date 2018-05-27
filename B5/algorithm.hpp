#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

struct DataStruct
{
  int key1;
  int key2;
  std::string str;
};

DataStruct giveEle(const std::string &input);
void makeVector(std::vector<DataStruct> &arr);
void sortingVector(std::vector<DataStruct> &arr);


#endif // ALGORITHM_H
