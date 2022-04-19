#include "student.h"
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

Student::Student(const char * const name, int perm) {
  this->name = new char[strlen(name)+1];
  strcpy(this->name, name);
  this->perm = perm;
}

int Student::getPerm() const {
  return perm;
}

const char * const Student::getName() const {
  return name;
}

void Student::setPerm(const int permNumber) {
  perm = permNumber;
}

void Student::setName(const char * const name) {
  delete [] this->name;
  this->name = new char[strlen(name)+1];
  strcpy(this->name, name);
}

Student::Student(const Student &orig) {
  this->name = new char[strlen(orig.name)+1];
  strcpy(this->name, orig.name);
  this->setPerm(orig.perm);
}

Student::~Student() {
  delete [] name;
}

Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...

  // KEEP THE CODE BELOW THIS LINE

  this->setName(right.name);
  this->setPerm(right.perm);

  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 

}

std::string Student::toString() const {
   std::string name_string(name);
   int perm_copy = perm;

  return "[" + name_string + "," + std::to_string(perm_copy) + "]";
}

