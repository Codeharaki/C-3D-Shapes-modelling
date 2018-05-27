#ifndef DETAILS_HPP
#define DETAILS_HPP
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <vector>
#include <forward_list>

void lab1_1(const char* array_direction);
void lab1_2(const char* filename);
void lab1_3();
void lab1_4(const char* array_direction, const char* array_size);

namespace detail
{
  template <typename T>
  bool descending(T a, T b)
  {
    return a<b;
  }
  template <typename T>
  bool accending(T a, T b)
  {
    return a>b;
  }
  template <typename Container>
  struct brackets_sort
  {
    typedef typename Container::size_type indextype;
    static indextype getBegin(const Container& )
    {
      return 0;
    };
    static indextype getEnd(const Container& cont)
    {
      return cont.size();
    };
    static typename Container::reference getNext(Container& cont, indextype i)
    {
      return cont[i];
    };
  };

  template <typename Container>
  struct at_sort
  {
    typedef typename Container::size_type indextype;
    static indextype getBegin(Container& )
    {
      return 0;
    };
    static indextype getEnd(const Container& cont)
    {
      return cont.size();
    };
    static typename Container::reference getNext(Container& cont, indextype i)
    {
      return cont.at(i);
    };
  };

  template <typename Container>
  struct iterator_sort
  {
    typedef typename Container::iterator indextype;
    static indextype getBegin(Container& cont)
    {
      return cont.begin();
    };
    static indextype getEnd(Container& cont)
    {
      return cont.end();
    };
    static typename Container::reference getNext(Container& , indextype i)
    {
      return *i;
    };
  };

  template <template <typename Container> class Traits, typename Container>
  void sort (Container& cont, bool(*compare)(typename Container::value_type&,typename Container::value_type&))
  {
    typedef typename Traits<Container>::indextype index;
    for (index i = Traits<Container>::getBegin(cont); i != Traits<Container>::getEnd(cont); ++i)
    {
      for (index j=i; j != Traits<Container>::getEnd(cont); ++j)
      {
       if(compare(Traits<Container>::getNext(cont,i),Traits<Container>::getNext(cont,j)))
        {
          std::swap (Traits<Container>::getNext(cont,i),Traits<Container>::getNext(cont,j));
        }
      }
    }
  }

  template <typename Container>
  void printCont (const Container& cont)
  {
    for (typename Container::const_iterator it = cont.begin(); it != cont.end(); it++)
    {
      std::cout << *it << " ";
    }
    std::cout << "\n";
  }
}

#endif // DETAILS_HPP
