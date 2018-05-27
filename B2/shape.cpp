#include <locale>
#include "shape.hpp"
void shape(std::vector<char>& buffer, std::locale local_sym)
{
  bool is_comma = false, is_dash = false, otherFlag = false;
  char punc = ' ';
  std::size_t j = 0, end = buffer.size();
  while (j != end)
  {
    if (std::isspace(buffer[j], local_sym))
    {
      j++;
      continue;
    }

    if (is_dash || otherFlag)
    {
      buffer.clear();
      return;
    }

    switch (buffer[j])
    {
      case ',':
      {
        if (is_comma)
        {
          buffer.clear();
          return;
        }
        is_comma = true;
        punc = ',';
      }
      break;
      case '-':
      {
        if (j + 2<end && buffer[j + 2] == '-' && buffer[j + 1] == '-')
        {
          is_dash = true;
          j += 3;
          continue;
        }
        else
        {
          buffer.clear();
          return;
        }
      }
      break;
      default:
      {
        if (is_comma)
        {
          buffer.clear();
          return;
        }
        punc = buffer[j];
        otherFlag = true;
      }
      break;
    }
    j++;
  }

  buffer.clear();

  if (otherFlag || is_comma)
  {
    buffer.push_back(punc);
  }

  if (is_dash)
  {
    buffer.push_back(' ');
    buffer.insert(buffer.end(), 3, '-');
  }

  buffer.push_back(' ');

  return;
}

type Symbol_type(char symb, std::locale local_sym)
{
  if (std::isalpha(symb, local_sym))
  {
    return Letter;
  }
  if (std::isdigit(symb, local_sym) || symb == '+')
  {
    return Number;
  }
  return Different;
}
