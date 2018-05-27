#ifndef SOURCE_HPP
#define SOURCE_HPP

#include <list>
#include <string>
#include <stdexcept>
#include <iostream>

void type_1();
void type_2();

typedef enum
{
  LOW,
  NORMAL,
  HIGH
} ElementPriority;

typedef struct
{
  std::string name;
} QueueElement;

template<typename T>
class QueueWithPriority
{
  public:
    QueueWithPriority();
    virtual ~QueueWithPriority() = default;

    void PutElementToQueue(const T &element, ElementPriority priority);
    T GetElementFromQueue();
    void Accelerate();

    bool empty() const;
  private:
    std::list<T> queue_;
    typename std::list<T>::iterator highEnd, normalEnd;
};

template<typename T>
QueueWithPriority<T>::QueueWithPriority()
{
  T virEle;
  highEnd = queue_.insert(queue_.end(),virEle);
  normalEnd = queue_.insert(queue_.end(),virEle);
}

template<typename T>
void QueueWithPriority<T>::PutElementToQueue(const T & element, ElementPriority priority)
{
  switch (priority)
  {
    case ElementPriority::HIGH:
      queue_.insert(highEnd, element);
      break;
    case ElementPriority::NORMAL:
      queue_.insert(normalEnd, element);
      break;
    case ElementPriority::LOW:
      queue_.insert(queue_.end(), element);
      break;
  }
}

template<typename T>
T QueueWithPriority<T>::GetElementFromQueue()
{
  if (empty())
  {
    throw std::invalid_argument("Queue is empty!");
  }
  if (queue_.begin() != highEnd)
  {
    T frontElem = queue_.front();
    queue_.pop_front();
    return frontElem;
  }
  else if (std::next(highEnd) != normalEnd)
  {
    T frontElem = *std::next(highEnd);
    queue_.erase(std::next(highEnd));
    return frontElem;
  }
  else
  {
    T frontElem = *std::next(normalEnd);
    queue_.erase(std::next(normalEnd));
    return frontElem;
  }
}

template<typename T>
void QueueWithPriority<T>::Accelerate()
{
  auto it = std::next(normalEnd);
  while (it != queue_.end())
  {
    queue_.insert(highEnd, *it);
    it++;
    queue_.erase(std::prev(it));
  }
}

template<typename T>
bool QueueWithPriority<T>::empty() const
{
  if ((queue_.begin() == highEnd) && (std::next(highEnd) == normalEnd)&& (std::next(normalEnd) == queue_.end()))
  {
    return true;
  }
  else
  {
    return false;
  }
}

#endif

