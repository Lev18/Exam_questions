#include <iostream>

class Stack {
public: 
  Stack();
  void push(int elem);
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
  std::cout << st.top() << std::endl;
}
