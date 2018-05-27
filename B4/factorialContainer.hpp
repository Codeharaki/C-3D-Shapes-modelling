#ifndef ITERATORS_H
#define ITERATORS_H

#include <iterator>

class FactorialContainer
{
public:
  class Iterator;
  FactorialContainer() = default;
  Iterator begin() noexcept;
  Iterator end() noexcept;
};

class FactorialContainer::Iterator : public std::iterator<std::bidirectional_iterator_tag, size_t>
  {
  public:
    Iterator();
    Iterator(size_t id, unsigned int value);
    Iterator(const Iterator &other) = default;

    const unsigned int* operator->() const noexcept;
    const unsigned int& operator*() const noexcept;

    Iterator& operator ++() noexcept;
    Iterator operator++(int) noexcept;
    Iterator& operator--() noexcept;
    Iterator operator--(int) noexcept;

    bool operator==(const Iterator& ite) const noexcept;
    bool operator!=(const Iterator& ite) const noexcept;

    Iterator& operator=(const Iterator &obj) = default;

  private:
    size_t index_;
    unsigned int val_;
  };
#endif // ITERATORS_H
