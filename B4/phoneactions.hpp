#ifndef PHONEACTIONS_H
#define PHONEACTIONS_H

#include "phonebooks.hpp"

std::string readName(std::stringstream &stream);
std::string readNumber(std::stringstream & stream);
std::string readMarkName(std::stringstream & stream);

void add(std::stringstream& stream, PhoneBook & book);
void delet(std::stringstream& stream, PhoneBook & book);
void show(std::stringstream& stream, PhoneBook & book);
void insert(std::stringstream& stream, PhoneBook & book);
void store(std::stringstream& stream, PhoneBook & book);
void move(std::stringstream& stream, PhoneBook & book);

#endif // PHONEACTIONS_H
