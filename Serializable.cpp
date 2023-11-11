#include <string>
#include <iostream>
#include <sstream>
#include <limits>

class Serializable {
public:
  virtual std::string serialize()  = 0;
  virtual void deserialize(const std::string& message) = 0; 
};

class Person : public Serializable {
public:
  Person(std::string name, int age) : m_name(name) { 
    if(age < 0 || age > 150) {
      throw std::runtime_error("invalid age");
    }
    m_age = age;
  }

  int get_age() const;
  std::string get_name() const;

  std::string serialize() override ;
  void deserialize(const std::string& message ) override;

private:
  int m_age;
  std::string m_name;
};

std::string  Person::serialize() {
  std::stringstream ss;
  ss << "Name:" << m_name << '\n' << "Age:" << m_age;
  return ss.str();
}

void Person::deserialize(const std::string& message) {
  std::istringstream iss(message);
  std::string name;
  int age;

  iss.ignore(std::numeric_limits<std::streamsize>::max(), ':');
  iss >> name;
  iss.ignore(std::numeric_limits<std::streamsize>::max(), ':');
  iss >> age;

  this->m_name = name;
  this->m_age = age;
}

int Person::get_age() const {
  return m_age;
}

std::string Person::get_name() const {
  return m_name;
}

int main() {
  Person p1("Ann", 14);
  std::string message = p1.serialize();
  std::cout << message << std::endl;
  Person p2("Unknown", 0);
  std::cout << "Name: " << p2.get_name() << '\n' << "Age:" << p2.get_age() << std::endl;

  p2.deserialize(message);

  std::cout << "Name: " << p2.get_name() << '\n' << "Age:" << p2.get_age() << std::endl;
  std::cout << "Name: " << p1.get_name() << '\n' << "Age:" << p1.get_age() << std::endl;
}
