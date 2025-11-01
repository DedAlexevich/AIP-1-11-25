#include <iostream>



void deleting(int** mat, size_t created) {
  for (size_t i = 0; i < created; i++) {
    delete[] mat[i];

  }
  delete[] mat;

}

int** createMatrix(size_t rows, size_t columns) {
  int ** mat = new int*[rows];
  size_t iter = 0;
  try {
    for (size_t i = 0; i < columns; i++) {
      iter++;
      int* c = new int[columns];
      mat[i] = c;
    }
  } catch (const std::bad_alloc &e) {
    deleting(mat, iter);
  }
  return mat;
}




int main()
{
  int** matrix = nullptr;
  size_t rows = 0, columns = 0;
  std::cin >> rows >> columns;
  try {
    matrix = createMatrix(rows,columns);
  } catch (const std::bad_alloc &e) {
    std::cerr << e.what();
    return 2;
  }
  for (size_t i = 0; i < rows;i++) {
    for (size_t j = 0; j < columns; j++) {
      matrix[i][j] = (j+1) * (i+1);
    }
  }

  for (int i = 0; i < rows;i++) {
    for (int j = 0; j < columns; j++) {
      std::cout << matrix[i][j] << '\t';
    }
    std::cout << '\n';
  }

  deleting(matrix, rows);



  return 0;
}