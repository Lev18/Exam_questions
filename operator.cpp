#include <iostream>

#include <iostream>

class Stack {
public:
  Stack();
  void push(int elem);
  int& operator[](const std::string& index);
  int operator[](const std::string& index) const;
  void pop();
  int top();

private:
  int m_size;
  int m_cap;
  int* m_arr;
};

Stack::Stack() : m_size{ 0 }, m_cap{ 0 }, m_arr{ nullptr }{
}

void Stack::push(int elem) {
  if (m_size == m_cap) {
    m_cap = m_cap ?  m_cap *= 2 : m_cap = 1;

    int* tmp = new int[m_cap];

    for (int i = 0; i < m_size; ++i) {
      tmp[i] = m_arr[i];
    }

    if(tmp != nullptr) {
        delete[] m_arr;
    }

    m_arr = tmp;
  }

  m_arr[m_size++] = elem;
}

int& Stack::operator[](const std::string& index) {
  int ind = std::stoi(index);

  if(ind < 0 || ind >= m_size) {
    throw std::runtime_error("index out of bounds");
  }
  return m_arr[ind];
}

int Stack::operator[](const std::string& index) const {
  int ind = std::stoi(index);

  if(ind < 0 || ind >= m_size) {
    throw std::runtime_error("index out of bounds");
  }
  return m_arr[ind];
}

void Stack::pop() {
  if(0 == m_size) {
    return;
  }
  m_arr[m_size--] = 0;
}

int Stack::top() {

  return m_arr[m_size - 1];
}

int main() {

  Stack st;
  st.push(15);
  st.push(14);
  st.push(17);
  st.push(19);
  st.push(12);
  st["4"] = 7; 
  std::cout << st.top() << std::endl;
  std::cout << st["4"] << std::endl;
}

