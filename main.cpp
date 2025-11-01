#include <iostream>

void deleting(int** mat, size_t created);

int** createMatrix(size_t rows, size_t columns);

void initMatrix(int** matrix, size_t rows, size_t columns, int init);

void printMatrix(int** matrix, size_t rows, size_t columns);
void printMatrixVarLen(int** matrix, const size_t* lns, size_t rows); //homework

void valueByInput(int** matrix, size_t rows, size_t columns);

int** convert(const int* t, const size_t* lns, size_t rows); //homework
void test_convert(); //homework

int main()
{
  int** matrix = nullptr;
  size_t rows = 0, columns = 0;

  std::cin >> rows >> columns;
  if (!std::cin) {
    std::cerr << "Sudar, vse ploxo\n";
    return 1;
  } else if (!rows || !columns  ){
    std::cerr << "Error of size\n";
    return 1;
  }

  try {
    matrix = createMatrix(rows,columns);
  } catch (const std::exception &e) {
    std::cerr << e.what();
    return 2;
  }

    initMatrix(matrix, rows, columns, 2);
    if (!std::cin) {
      std::cerr << "You are mistake";
      deleting(matrix, rows);
      return 1;
    }

  printMatrix(matrix, rows, columns);
  deleting(matrix, rows);

  test_convert();

  return 0;
}

void test_convert()
{
  int t[] = {5, 5, 5, 5, 6, 6, 7, 7, 7, 7, 7, 8};
  size_t lns[] = {4, 2, 5, 1};
  size_t rows = 4;
  int** matrix = nullptr;
  try {
    matrix = convert(t, lns, rows);
  } catch (const std::bad_alloc &e) {
    std::cerr << e.what();
    throw;
  }

  printMatrixVarLen(matrix, lns, rows);
  deleting(matrix, rows);
}

void deleting(int** mat, size_t created)
{
  for (size_t i = 0; i < created; i++) {
    delete[] mat[i];
  }
  delete[] mat;
}

int** createMatrix(size_t rows, size_t columns)
{
  int** mat = new int*[rows];
  size_t iter = 0;
  try {
    for (; iter < rows; iter++) {
      int* c = new int[columns];
      mat[iter] = c;
    }
  } catch (const std::bad_alloc) {
    deleting(mat, iter);
    throw;
  }
  return mat;
}

void initMatrix(int** matrix, size_t rows, size_t columns, int init)
{
  for (size_t i = 0; i < rows;i++) {
    for (size_t j = 0; j < columns; j++) {
      matrix[i][j] = init;
    }
  }
}

void printMatrix(int** matrix, size_t rows, size_t columns)
{
  for (size_t i = 0; i < rows;i++) {
    std::cout << matrix[i][0];
    for (size_t j = 1; j < columns; j++) {
      std::cout << '\t' << matrix[i][j];
    }
    std::cout << '\n';
  }
}

void printMatrixVarLen(int** matrix, const size_t* lns, size_t rows)
{
  for (size_t i = 0; i < rows;i++) {
    std::cout << matrix[i][0];
    for (size_t j = 1; j < lns[i]; j++) {
      std::cout << '\t' << matrix[i][j];
    }
    std::cout << '\n';
  }
}

void valueByInput(int** matrix, size_t rows, size_t columns)
{
  int t = 0;
  for (size_t i = 0; i < rows;i++) {
    for (size_t j = 0; j < columns; j++) {
      std::cin >> t;
      matrix[i][j] = t;
    }
  }
}

int** convert(const int* t, const size_t* lns, size_t rows) //homework
{
  int** mat = new int*[rows];
  size_t c = 0;
  for (size_t i = 0; i < rows; ++i) {
    try {
      mat[i] = new int[lns[i]];
    } catch (const std::bad_alloc) {
      deleting(mat, i);
      throw;
    }
    for (size_t j = 0; j < lns[i]; ++j) {
      mat[i][j] = t[c];
      ++c;
    }
  }
  return mat;
}