#include "phonebooks.hpp"

PhoneBook::PhoneBook()
{
  bookmarks_["current"] = records_.end();
}

PhoneBook::PhoneBook(const PhoneBook & obj)
{
  *this = obj;
}

PhoneBook & PhoneBook::operator=(const PhoneBook & obj)
{
  if (this != &obj)
  {
    records_ = obj.records_;
    bookmarks_.clear();
    for (auto i : obj.bookmarks_)
    {
      std::list<RecordElem>::const_iterator bookmarks = i.second;
      bookmarks_[i.first] = std::next(records_.begin(), std::distance(obj.records_.cbegin(), bookmarks));
    }
  }
  return *this;
}

void PhoneBook::addRecordtoEnd(const PhoneBookRecord & record)
{
  RecordElem new_el;
  new_el.rec = record;
  if (records_.empty())
  {
    new_el.bookmarks.insert("current");
    records_.push_back(new_el);
    bookmarks_["current"] = records_.begin();
  }
  else
  {
    records_.push_back(new_el);
  }
}

void PhoneBook::addBookmark(const std::string & curr_bookmark, const std::string & new_bookmark)
{
  auto iter = getIterator(curr_bookmark);
  bookmarks_[new_bookmark] = iter->second;
  if (iter->second != records_.end())
  {
    iter->second->bookmarks.insert(new_bookmark);
  }
}

void PhoneBook::insertBefore(const std::string & bookmark, const PhoneBookRecord & record)
{
  insert(bookmark, record, false);
}

void PhoneBook::insertAfter(const std::string & bookmark, const PhoneBookRecord & record)
{
  insert(bookmark, record, true);
}

void PhoneBook::insert(const std::string & bookmark, const PhoneBookRecord & record, const bool is_after)
{
  if (records_.empty())
  {
    addRecordtoEnd(record);
    return;
  }
  auto iter = getIterator(bookmark);
  if (iter->second != records_.end())
  {
    if (is_after)
    {
      records_.insert(std::next(iter->second), RecordElem{ record, });
    }
    else
    {
      records_.insert(iter->second, RecordElem{ record, });
    }
  }
  else
  {
    records_.push_back(RecordElem{ record, });
  }
}

void PhoneBook::deleteRecord(const std::string & bookmark)
{
  auto iter = getIterator(bookmark);
  if (iter->second != records_.end())
  {
    auto elem = iter->second;
    for (auto i : elem->bookmarks)
    {
      if ((std::next(elem) == records_.end()) && (records_.size() > 1))
      {
        bookmarks_.at(i) = std::prev(elem);
        std::prev(elem)->bookmarks.insert(i);
      }
      else
      {
        bookmarks_.at(i) = std::next(elem);
        if (std::next(elem) != records_.end())
        {
          std::next(elem)->bookmarks.insert(i);
        }
      }
    }
    records_.erase(elem);
  }
}

void PhoneBook::replaceRecord(const std::string & bookmark, const PhoneBookRecord & record)
{
  auto iter = getIterator(bookmark);
  iter->second->rec = record;
}

void PhoneBook::showCurrent(const std::string & bookmark)
{
  auto iter = getIterator(bookmark);
  if (iter->second == records_.end())
  {
    std::cout << "<EMPTY>" << std::endl;
  }
  else
  {
    std::cout << iter->second->rec.number << " " << iter->second->rec.name << std::endl;
  }
}

void PhoneBook::moveBookmark(const std::string & bookmark, const int pos)
{
  auto iter = getIterator(bookmark);
  if (iter->second != records_.end())
  {
    iter->second->bookmarks.erase(bookmark);
  }
  std::advance(iter->second, pos);

  if (iter->second != records_.end())
  {
    iter->second->bookmarks.insert(bookmark);
  }
}

void PhoneBook::moveBookmark(const std::string & bookmark, const std::string & pos)
{
  auto iter = getIterator(bookmark);
  if (pos == "first" || pos == "last")
  {
    if (iter->second != records_.end())
    {
      iter->second->bookmarks.erase(bookmark);
    }
    if (!records_.empty())
    {
      if (pos == "first")
      {
        iter->second = records_.begin();
      }
      else
      {
        iter->second = std::prev(records_.end());
      }
      iter->second->bookmarks.insert(bookmark);
    }
    else
    {
      iter->second = records_.end();
    }
  }
  else
  {
    std::cout << "<INVALID STEP>" << std::endl;
  }
}

void PhoneBook::moveToNext(const std::string & bookmark)
{
  moveBookmark(bookmark, 1);
}

void PhoneBook::moveToPrev(const std::string & bookmark)
{
  moveBookmark(bookmark, -1);
}

PhoneBook::bookmarkIter PhoneBook::getIterator(const std::string & bookmark)
{
  auto iter = bookmarks_.find(bookmark);
  if (iter == bookmarks_.end())
  {
    throw std::invalid_argument("Not found");
  }
  return iter;
}
