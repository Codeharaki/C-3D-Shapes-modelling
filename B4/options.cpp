#include "options.hpp"
#include "factorialContainer.hpp"
#include "phonebooks.hpp"
#include "phoneactions.hpp"

void Option_1()
{
  PhoneBook book;
  std::string line;
  while (std::getline(std::cin, line))
  {
    try
    {
      std::stringstream stream(line);
      std::string command;
      stream >> command;
      if (command == "add")
      {
        add(stream, book);
      }
      else if (command == "insert")
      {
        insert(stream, book);
      }
      else if (command == "delete")
      {
        delet(stream, book);
      }
      else if (command == "store")
      {
        store(stream, book);
      }
      else if (command == "move")
      {
        move(stream, book);
      }
      else if (command == "show")
      {
        try
        {
          show(stream, book);
        }
        catch (std::invalid_argument &)
        {
          std::cout << "<INVALID BOOKMARK>" << std::endl;
        }
      }
      else
      {
        throw std::invalid_argument("");
      }
    }
    catch (std::invalid_argument &)
    {
      std::cout << "<INVALID COMMAND>" << std::endl;
    }
  }
}

void Option_2()
{
  FactorialContainer arr;

  std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  std::reverse_copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}

