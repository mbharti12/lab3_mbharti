#include <string>
#include "studentRoll.h"
#include <iostream>
using namespace std;

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

//THIS FUNCTION DOESN'T WORK - need to look into case for when it's empty
void StudentRoll::insertAtTail(const Student &s) {
  if (!head){
    head = new Node;
    head->s = new Student(s);
    head->next = nullptr;
    tail = head;
    return;
  }
  tail->next = new Node;
  tail->next->s = new Student(s);
  tail = tail->next;
  tail->next = nullptr;
}

std::string StudentRoll::toString() const {
  std::string return_string = "[";

  for (Node *n = head; n != nullptr; n = n->next){
    return_string = return_string + n->s->toString();
    if (n->next != nullptr){
      return_string = return_string + ",";
    }
  }
  return_string = return_string + "]";
  
  return return_string;
}

void StudentRoll::clear(Node* head){
  if (!head)
    return;
  else{
    clear(head->next);
    delete head->s;
    delete head;
  }
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = tail = NULL;

  for (Node *n = orig.head; n != nullptr; n = n->next){
    insertAtTail(*(n->s));
  }
}

StudentRoll::~StudentRoll() {
  if (head){
    clear(head);
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...


  // KEEP THE CODE BELOW THIS LINE

  if (head){
    clear(head);
  }
  head = tail = NULL;

  for (Node *n = right.head; n != nullptr; n = n->next){
    insertAtTail(*(n->s));
  }  

  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}