#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <locale>
#include <stdio.h>
#include "shape.hpp"

std::locale local_sym;

int main(int argc, char *argv[])
{
  local_sym = std::cout.getloc();
  
  size_t lineWidthMax = 0;
  switch (argc)
  {
    case 1:
    {
      lineWidthMax = 40;
    }
    break;
    case 3:
    {
      if (std::string(argv[1]) != "--line-width")
      {
        std::cerr << "Need to: --line-width";
        return 1;
      }
      try
      {
        lineWidthMax = std::stoi(argv[2]);
      }
      catch(std::invalid_argument)
      {
        std::cerr << "Incorrect line width";
        return 1;
      }
    }
    break;
    default:
    {
      std::cerr << "Incorrect arguments";
      return 1;
    }
  }

  if (lineWidthMax<25)
  {
    std::cerr << "Bad line width";
    return 1;
  }

  char decimal_separator = std::use_facet< std::numpunct<char> >(local_sym).decimal_point();
  bool nextIsDigit = false;

  std::vector<char> words;
  std::vector<char> buffer;

  std::cin >> std::ws;

  size_t counter = 0;
  char ch_current = std::cin.get();

  if (ch_current == EOF)
  {
    return 0;
  }

  type prev_type = Symbol_type(ch_current, local_sym);
  if (prev_type != Different)
  {
    words.push_back(ch_current);
    ++counter;
  }
  else
  {
    char ch_next = std::cin.peek();
    if ((ch_current == '-') && (Symbol_type(ch_next, local_sym) == Number) && (ch_next != '+'))
    {
      words.push_back(ch_current);
      ++counter;
      prev_type = Number;
    }
    else
    {
      std::cerr << "First - punctuation prohibited";
      return 1;
    }
  }

  size_t lineStart = 0;
  size_t possibleLineEnd = 0;
  std::vector<size_t> bordArray;

  while ((ch_current = std::cin.get()) != EOF)
  {
    type current_type{ Symbol_type(ch_current, local_sym) };

    if ((current_type == Letter) || (current_type == Number))
    {
      words.push_back(ch_current);
      if (prev_type == current_type)
      {
        ++counter;
      }
      else
      {
        if (prev_type != Different)
        {
          std::cerr << "Bad input";
          return 1;
        }
        prev_type = current_type;
        counter = 1;
      }
    }
    else
    {
      if (((ch_current == decimal_separator) && (prev_type == Number) && (Symbol_type(std::cin.peek(), local_sym) == Number)) || ((ch_current == '-') && (prev_type == Letter) && (std::cin.peek() != '-')))
      {
        words.push_back(ch_current);
        ++counter;
        continue;
      }

      if (prev_type != Different)
      {
        if (counter>20)
        {
          std::cerr << "Too long word/number";
          return 1;
        }
        else
        {
          counter = 0;
        }
        
        buffer.clear();
        buffer.push_back(ch_current);

        while (Symbol_type(std::cin.peek(), local_sym) == Different && (std::cin.peek() != EOF))
        {
          ch_current = std::cin.get();
          buffer.push_back(ch_current);
        }

        char chp = std::cin.peek();
        if ((ch_current == '-') && (buffer[buffer.size() - 2] != '-') && (Symbol_type(chp, local_sym) == Number) && (chp != '+'))
        {
          nextIsDigit = true;
          buffer.pop_back();
        }

        shape(buffer, local_sym);
        if (buffer.empty())
        {
          std::cerr << "Bad input";
          return 1;
        }

        words.insert(words.end(), buffer.begin(), buffer.end());

        size_t currentWidth = words.size() - lineStart;
        if (currentWidth < lineWidthMax)
        {
          possibleLineEnd = words.size() - 1;
        }
        else
        {
          size_t lineEnd = 0;
          if ((currentWidth == lineWidthMax) || (currentWidth == lineWidthMax + 1))
          {
            lineEnd = words.size() - 1;
          }
          else
          {
            lineEnd = possibleLineEnd;
          }
          bordArray.push_back(lineEnd);
          lineStart = lineEnd + 1;
          possibleLineEnd = words.size() - 1;
        }


        if (!nextIsDigit)
        {
          prev_type = Different;
        }
        else
        {
          nextIsDigit = false;
          words.push_back('-');
          counter = 1;
          prev_type = Number;
        }
      }
    }
  }

  if (counter>20)
  {
    std::cerr << "Too long word/number";
    return 1;
  }

  if ((words.size() - lineStart) > lineWidthMax)
  {
    bordArray.push_back(possibleLineEnd);
  }

  std::vector<char*> strVec;
  auto it = words.begin();
  strVec.push_back(&(*it));

  for (size_t i = 0; i != bordArray.size(); i++)
  {
    words[bordArray[i]] = '\0';
    strVec.push_back(&(words[bordArray[i] + 1]));
  }

  if (*(words.end() - 1) == ' ')
  {
    *(words.end() - 1) = '\0';
  }
  else
  {
    words.push_back('\0');
  }

  for (auto it = strVec.begin(); it != strVec.end(); it++)
  {
    std::printf("%s", *it);
    std::cout << std::endl;
  }

  return 0;
}
