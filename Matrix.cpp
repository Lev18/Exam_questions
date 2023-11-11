#include <iostream>

class Matrix {
public:
  Matrix();
  Matrix(int len, int size);
  Matrix(const Matrix& lhs);
  Matrix& operator=(const Matrix& lhs);
  Matrix(Matrix&& rhs) noexcept;
  Matrix& operator=(Matrix&& rhs) noexcept;
  int operator()(int row, int column) const;
  int& operator()(int row, int column);

  int get_elem(int row, int qcolumn) const;
  void set_matrix_val(int row, int column, int num);
  std::ostream& out(std::ostream const& Cout, Matrix const& matrix);  

private:
  int m_row;
  int m_column;
  int** m_arr;
};

Matrix::Matrix() : m_row{0}, m_column{0}, m_arr{nullptr} {}

Matrix::Matrix(int row, int column) : m_row{row}, m_column{column} {
  m_arr = new int*[m_row];
  for(int i = 0; i < m_row; ++i) {
    m_arr[i] = new int[m_column];
  //  for(int j = 0; j < m_column; ++j) {
   //   m_arr[i][j] = 0;
   // }
  }
}

// approach one
Matrix::Matrix(const Matrix& lhs) : m_row{lhs.m_row}, m_column{lhs.m_column}{
 m_arr = new int*[m_row];
  for(int i = 0; i < m_row; ++i) {
    m_arr[i] = new int[m_column];
    for(int j = 0; j < m_column; ++j) {
      m_arr[i][j] = lhs.m_arr[i][j];
    }
  }
}

// approach two
/*
Matrix::Matrix(const Matrix& lhs) : Matrix(lhs.m_row, lhs.m_column) { 

}
*/

void Matrix::set_matrix_val(int row, int column, int num) {
  if (row >= m_row || column >= m_column || row < 0 || column < 0) {
    throw std::runtime_error("index out of bounds");
  }
  
  m_arr[row][column] = num;
}

int Matrix::get_elem(int row, int column) const{
    if (row >= m_row || column >= m_column || row < 0 || column < 0) {
      throw std::runtime_error("index out of bounds");
    }
    return m_arr[row][column];
}

Matrix& Matrix::operator=(const Matrix& rhs)  {
  if (this == &rhs) {

    return *this;
  }

  delete[] m_arr;

  m_row = rhs.m_row;
  m_column = rhs.m_column;

  m_arr = new int*[m_row];
  for(int i = 0; i < m_row; ++i) {
    m_arr[i] = new int[m_column];
    for(int j = 0; j < m_column; ++j) {
      m_arr[i][j] = rhs.m_arr[i][j];
    }
  }

  return *this;
}

Matrix::Matrix(Matrix&& rhs) noexcept : m_row{std::move(rhs.m_row)}, m_column{std::move(rhs.m_column)} {
  m_arr = std::move(rhs.m_arr);
  rhs.m_arr = nullptr;
  rhs.m_row = 0;
  rhs.m_column = 0;
}

Matrix& Matrix::operator=(Matrix&& rhs) noexcept {
  //checking self assignment
  if (this != &rhs) {

  m_row = std::move(rhs.m_row);
  m_column = std::move(rhs.m_column);
  m_arr = std::move(rhs.m_arr);
  rhs.m_arr = nullptr;
  rhs.m_row = 0;
  rhs.m_column = 0;
  }

  return *this;
}

int Matrix::operator()(int row, int col) const {
  if (row >= m_row || col >= m_column || row < 0 || col < 0) {
    throw std::runtime_error("index out of bounds");
  }
  return m_arr[row][col];
}

int& Matrix::operator()(int row, int col)  {
  if (row >= m_row || col >= m_column || row < 0 || col < 0) {
    throw std::runtime_error("index out of bounds");
  }
  return m_arr[row][col];
}

std::ostream& out(std::ostream& Cout, Matrix const& matrix, int row, int column) {
    Cout << matrix(row, column);
    return Cout;
}

std::istream& input(std::istream& Cin, Matrix& matrix, int row, int col, int val) {
  Cin >> matrix(row, col);
  return Cin;
}


int main() {
  Matrix m(3,4);
  m.set_matrix_val(1, 2, 14);
  Matrix m2(m);
  m2.set_matrix_val(1, 3, 15);
  Matrix m3 (std::move(m));
  m3 = std::move(m2);
  std::cin >> m3(1, 1);

  std::cout << m3(1, 2) <<'\n'<< m3(1, 1) << std::endl;
   // std::cout << m3(1, 1) << std::endl; 
  //std::cout << m3.get_elem(1, 2) << std::endl;
 // std::cout << m2.get_elem(1, 3) << std::endl;
  return 0;
}
