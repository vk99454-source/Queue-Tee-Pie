#include <iostream>

#include "src/hello.hpp"
using namespace std;

class Puppy : public Cutie {
public:
  Puppy() : Cutie("Puppy", 10) {}
  string get_description() override {
    return "Puppy";
  }
  int get_cuteness_rating() override {
    return 10;
  }
};
class Kitty : public Cutie {
public:
  Kitty() : Cutie("Kitty", 9) {}
  string get_description() override {
    return "Kitty";
  }
  int get_cuteness_rating() override {
    return 9;
  }
};
class PygmyMarmoset : public Cutie {
public:
  PygmyMarmoset() : Cutie("Pygmy Marmoset", 8) {}
  string get_description() override {
    return "Pygmy Marmoset";
  }
  int get_cuteness_rating() override {
    return 8;
  }
};
int main() {
  Puppy puppy;
  Kitty kitty;
  PygmyMarmoset marmoset;
  QueueTees queue;
  cout << "Initial size: " << queue.size() << endl;
  queue.enqueue(&puppy);
  queue.enqueue(&kitty);
  queue.enqueue(&marmoset);
  cout << "Size after enqueue: " << queue.size() << endl;
  Cutie* first = queue.dequeue();
  if (first != nullptr) {
    cout << "First dequeue: " << first->get_description() << endl;
  }
  Cutie* second = queue.dequeue();
  if (second != nullptr) {
    cout << "Second dequeue: " << second->get_description() << endl;
  }
  Cutie* third = queue.dequeue();
  if (third != nullptr) {
    cout << "Third dequeue: " << third->get_description() << endl;
  }
  cout << "Final size: " << queue.size() << endl;
  return 0;
}