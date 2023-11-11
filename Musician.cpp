#include <iostream> 
#include <vector>

class Musician {
public:
  virtual void play()  = 0;
  void move() { 
    std::cout << "is moving" << std::endl;
  }
};

class Guitarist : public Musician {
  public:
    void play() override {
      std::cout << "Guitarist is playing!" << std::endl;
    }
};

class Pianist : public Musician {
public:
  void play() override {
    std::cout << "Pianist is playing!" << std::endl;
  }
};

int main() {
  Musician* m = new Guitarist();
  Musician* m2 = new Pianist();

  std::vector<Musician*> mus{};

  mus.push_back(m);
  mus.push_back(m2);
  mus[0]->play();
  mus[1]->play();
  mus[0]->move();
  mus[1]->move();
  return 0;
}
