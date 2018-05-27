#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <vector>
#include <locale>
enum type
{
  Letter,
  Number,
  Different
};
type Symbol_type(char symbol, std::locale local_sym);
void shape(std::vector<char>& buffer, std::locale local_sym);

#endif // SHAPE_HPP
