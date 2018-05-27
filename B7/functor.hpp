#ifndef FUNCTOR_H
#define FUNCTOR_H

#include <iostream>

class Functor
{
public:
  Functor();
  ~Functor () = default;

  void operator ()(int x);
  void print() const;

private:
  int max_, min_, positive_, negative_, numElements_, first_, last_;
  long long int sum_, oddSum_, evenSum_;
};


#endif // FUNCTOR_H
