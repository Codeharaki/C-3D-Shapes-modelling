#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

struct PhoneBookRecord
{
  std::string number, name;
};
struct RecordElem
{
  PhoneBookRecord rec;
  std::set<std::string> bookmarks;
};
class PhoneBook
{
public:
  PhoneBook();
  PhoneBook(const PhoneBook &obj);
  PhoneBook(PhoneBook && obj) = default;

  PhoneBook& operator=(const PhoneBook& obj);
  PhoneBook& operator=(PhoneBook &&obj) = default;

  void showCurrent(const std::string &bookmark);
  void moveToNext(const std::string &bookmark);
  void moveToPrev(const std::string &bookmark);
  void addRecordtoEnd(const PhoneBookRecord & record);
  void addBookmark(const std::string & curr_bookmark, const std::string &new_bookmark);
  void insertBefore(const std::string & bookmark, const PhoneBookRecord &record);
  void insertAfter(const std::string & bookmark, const PhoneBookRecord &record);
  void deleteRecord(const std::string &bookmark);
  void replaceRecord(const std::string &bookmark, const PhoneBookRecord &record);
  void moveBookmark(const std::string &bookmark, const int pos);
  void moveBookmark(const std::string &bookmark, const std::string &pos);

private:
  using record_type = std::list<RecordElem>;
  using bookmark_type = std::map<std::string, record_type::iterator>; // DUY NHAT VA DA SAP XEP - CAY NHI PHAN
  using bookmarkIter = bookmark_type::iterator;

  record_type records_;
  bookmark_type bookmarks_;// clock: string + value: information of 1 man

  bookmarkIter getIterator(const std::string &bookmark);
  void insert(const std::string & bookmark, const PhoneBookRecord & record, const bool is_after);
};


#endif // PHONEBOOK_H
