#include <iostream>
#include <thread>


void deleting(int** mat, size_t created) {
  for (size_t i = 0; i < created; i++) {
    delete[] mat[i];

  }
  delete[] mat;
}

int** createMatrix(unsigned rows, unsigned columns) {
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
    throw e;
  }
  return mat;
}

void initMatrix(int** matrix, unsigned rows, unsigned columns) {
  for (size_t i = 0; i < rows;i++) {
    for (size_t j = 0; j < columns; j++) {
      matrix[i][j] = (j+1) * (i+1);
    }
  }
}

void printMatrix(int** matrix, unsigned rows, unsigned columns) {
  for (int i = 0; i < rows;i++) {
    for (int j = 0; j < columns; j++) {
      std::cout << matrix[i][j] << '\t';
    }
    std::cout << '\n';
  }
}

int main()
{
  int** matrix = nullptr;
  unsigned int rows = 0, columns = 0;

  std::cin >> rows >> columns;

  try {
    matrix = createMatrix(rows,columns);
  } catch (const std::exception &e) {
    std::cerr << e.what();
    return 2;
  }

  initMatrix(matrix, rows, columns);
  printMatrix(matrix, rows, columns);
  deleting(matrix, rows);



  return 0;
}