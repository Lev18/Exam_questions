#include <iostream>

class Animal {
public:
  virtual void run() {};
};
class Elephant : public Animal{};
class Monkey : public Animal {};

const char* whichAnimal (Animal* const an) {
  if (dynamic_cast<Elephant*>(an)) {
    return "elephant";
  } else if(dynamic_cast<Monkey*>(an)){
    return "monkey";
  }
  return "";
}

int main() {
  Elephant*  a = new Elephant();
  Monkey* m = new Monkey();
  std::cout << whichAnimal(m);
  return 0;
}
