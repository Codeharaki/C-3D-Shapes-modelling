#include "source.hpp"

#include <string>
#include <sstream>
#include "source.hpp"

void type_1()
{
  QueueWithPriority<std::string> list;

  std::string line;
  while (std::getline(std::cin, line))
  {
    std::stringstream stream(line);
    std::string command;
    stream >> command;

    if (command == "add")
    {
      std::string priority;
      stream >> priority;

      std::string data;
      stream.ignore();
      std::getline(stream, data);

      if (data.empty())
      {
        std::cout << "<INVALID COMMAND>" << std::endl;
      }
      else if (priority == "high")
      {
        list.PutElementToQueue(data, ElementPriority::HIGH);
      }
      else if (priority == "normal")
      {
        list.PutElementToQueue(data, ElementPriority::NORMAL);
      }
      else if (priority == "low")
      {
        list.PutElementToQueue(data, ElementPriority::LOW);
      }
      else
      {
        std::cout << "<INVALID COMMAND>" << std::endl;
      }
    }
    else if (command == "accelerate" && stream.eof())
    {
      list.Accelerate();
    }
    else if (command == "get" && stream.eof())
    {
      if (list.empty())
      {
        std::cout << "<EMPTY>" << std::endl;
      }
      else
      {
        std::cout << list.GetElementFromQueue() << std::endl;
      }
    }
    else
    {
       std::cout << "<INVALID COMMAND>" << std::endl;
    }

    if (std::cin.eof())
    {
       break;
    }
  }
}
