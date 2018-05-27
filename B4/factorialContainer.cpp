#include "factorialContainer.hpp"

FactorialContainer::Iterator::Iterator() :Iterator(1, 1)
{
}

FactorialContainer::Iterator::Iterator(size_t id, unsigned int value) : index_(id), val_(value)
{
}

const unsigned int * FactorialContainer::Iterator::operator->() const noexcept
{
  return &val_;
}

const unsigned int & FactorialContainer::Iterator::operator*() const noexcept
{
  return val_;
}

FactorialContainer::Iterator & FactorialContainer::Iterator::operator++() noexcept
{
  if (index_ < 11)
  {
    ++index_;
    val_ *= index_;
  }
  return *this;
}

FactorialContainer::Iterator FactorialContainer::Iterator::operator++(int) noexcept
{
  Iterator temp = *this;
  ++(*this);
  return temp;
}

FactorialContainer::Iterator & FactorialContainer::Iterator::operator--() noexcept
{
  if (index_ > 1)
  {
    val_ /= index_;
    --index_;
  }
  return *this;
}

FactorialContainer::Iterator FactorialContainer::Iterator::operator--(int) noexcept
{
  Iterator temp = *this;
  --(*this);
  return temp;
}

bool FactorialContainer::Iterator::operator==(const Iterator & ite) const noexcept
{
  return (index_ == ite.index_);
}

bool FactorialContainer::Iterator::operator!=(const Iterator & ite) const noexcept
{
  return (!(ite == *this));
}

FactorialContainer::Iterator FactorialContainer::begin() noexcept
{
  return FactorialContainer::Iterator(1, 1);
}

FactorialContainer::Iterator FactorialContainer::end() noexcept
{
  return FactorialContainer::Iterator(11, 39916800);
}
