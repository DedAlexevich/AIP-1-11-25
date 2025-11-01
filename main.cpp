#include <iostream>
#include <thread>


void deleting(int** mat, size_t created)
{
  for (size_t i = 0; i < created; i++) {
    delete[] mat[i];
  }
  delete[] mat;
}

int** createMatrix(unsigned rows, unsigned columns)
{
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
    throw;
  }
  return mat;
}

void initMatrix(int** matrix, unsigned rows, unsigned columns, int init)
{
  for (size_t i = 0; i < rows;i++) {
    for (size_t j = 0; j < columns; j++) {
      matrix[i][j] = init;
    }
  }
}

void printMatrix(int** matrix, unsigned rows, unsigned columns)
{
  for (int i = 0; i < rows;i++) {
    std::cout << matrix[i][0];
    for (int j = 1; j < columns; j++) {
      std::cout << '\t' << matrix[i][j];
    }
    std::cout << '\n';
  }
}

void valueByInput(int** matrix, unsigned rows, unsigned columns) {
  int t = 0;
  for (size_t i = 0; i < rows;i++) {
    for (size_t j = 0; j < columns; j++) {
      std::cin >> t;
      matrix[i][j] = t;
    }
  }
}

int main()
{
  int** matrix = nullptr;
  unsigned rows = 0, columns = 0;

  std::cin >> rows >> columns;
  if (!std::cin) {
    std::cerr << "Sudar, vse ploxo\n";
    return 1;
  }

  try {
    matrix = createMatrix(rows,columns);
  } catch (const std::exception &e) {
    std::cerr << e.what();
    return 2;
  }

    valueByInput(matrix, rows, columns);
    if (!std::cin) {
      std::cerr << "You are mistake";
      deleting(matrix, rows);
      return 1;
    }

  printMatrix(matrix, rows, columns);
  deleting(matrix, rows);

  return 0;
}