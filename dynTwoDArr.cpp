#include <iostream>
#include <vector>

int main_diag(std::vector<std::vector<int>> arr) {
  int sum {};

  for (auto i = arr.begin(); i != arr.end(); ++i) {
      sum += (*i)[i - arr.begin()];
  }

  return sum;
}

int oth_main_diag(int** arr, int row, int col) {
  int sum {};

  for (int i = 0; i < row; ++i) {
      sum += arr[i][i];
  }

  return sum;
}

int main() {
    int row = 3;
    int col = 3;
    int **arr_1 =  new int*[row];
    for (int i = 0; i < row; ++i) {
      arr_1[i] = new int[col];
      for (int j = 0; j < col; ++j) {
        arr_1[i][j] = j;
      }
    }
    oth_main_diag(arr_1, row, col);
}
