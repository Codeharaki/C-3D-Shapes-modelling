#include "functor.hpp"

#include <iomanip>
#include <cmath>
#include <limits>

Functor::Functor ():
  max_ (std::numeric_limits<int>::min()),
  min_ (std::numeric_limits<int>::max()),
  positive_ (0),
  negative_ (0),
  numElements_ (0),
  first_ (0),
  last_ (0),
  sum_ (0),
  oddSum_ (0),
  evenSum_ (0)
{}

void Functor::operator()(int x)
{
  if (x > max_)
  {
    max_ = x;
  }
  if (x < min_)
  {
    min_ = x;
  }
  if (x > 0)
  {
    positive_++;
  }
  if (x < 0)
  {
    negative_++;
  }
  if (numElements_ == 0)
  {
    first_ = x;
  }
  last_ = x;
  numElements_++;

  sum_ += x;
  if (x % 2 != 0)
  {
    oddSum_ += x;
  }
  else
  {
    evenSum_ += x;
  }
}

void Functor::print() const
{
  if (numElements_ == 0)
  {
    std::cout << "No Data" <<std::endl;
    return;
  }
  std::cout << "Max: " << max_ << std::endl;
  std::cout << "Min: " << min_ << std::endl;

  long double mean = static_cast<long double>(sum_) / static_cast<long double>(numElements_);
  std::cout << "Mean: " << std::setprecision(1) << std::fixed << mean << std::endl;

  std::cout << "Positive: " << positive_ << std::endl;
  std::cout << "Negative: " << negative_ << std::endl;
  std::cout << "Odd Sum: " << oddSum_ << std::endl;
  std::cout << "Even Sum: " << evenSum_ << std::endl;

  if (first_ == last_)
  {
    std::cout << "First/Last Equal: yes" << std::endl;
  }
  else
  {
    std::cout << "First/Last Equal: no" << std::endl;
  }
}
