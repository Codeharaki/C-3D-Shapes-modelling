#include "options.hpp"
#include <map>



bool NotToPrinted(const std::string &word, std::map<std::string, bool> &Map_data)
{
  auto it = Map_data.find(word);
  if(it->second == false)
  {
    it->second = true;
    return true;
  }
  else
  {
    return false;
  }
}
void first(std::istream &input, std::ostream &output)
{
  std::vector<std::string> words;
  std::copy(std::istream_iterator<std::string>(input), std::istream_iterator<std::string>(), std::back_inserter(words));

  std::map<std::string, bool> MapIsPrinted;
  for (auto ite = words.begin(); ite != words.end(); ite++)
  {
    MapIsPrinted.insert(make_pair(*ite,false));
  }

  for (auto ite = words.begin(); ite != words.end(); ite++)
  {
    if (NotToPrinted(*ite,MapIsPrinted))
    {
      output << *ite << "\n";
    }
  }
}
