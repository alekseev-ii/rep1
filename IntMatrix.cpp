#include "IntMatrix.h"

#include "../../../../Program Files/JetBrains/CLion 2025.2/bin/mingw/lib/gcc/x86_64-w64-mingw32/13.1.0/include/c++/iosfwd"
#include "../../../../Program Files/JetBrains/CLion 2025.2/bin/mingw/lib/gcc/x86_64-w64-mingw32/13.1.0/include/c++/stdexcept"


IntMatrix::~IntMatrix()
{
  data.~IntArray();
}


IntMatrix::IntMatrix(const IntMatrix & rhs): r(rhs.rows()), c(rhs.cols()),
                                             data(IntArray(rhs.rows(), rhs.cols()))

{
  if (this != &rhs) {
    for (size_t i = 0; i < r; i++) {
      for (size_t j = 0; j < c; j++) {
        set(i, j, rhs.get(i, j));
      }
    }
  }
}


IntMatrix & IntMatrix::operator=(const IntMatrix & rhs)
{
  if (this != &rhs) {
    data = IntArray(rhs.rows(), rhs.cols());
    r = rhs.rows();
    c = rhs.cols();
    for (size_t i = 0; i < r; i++) {
      for (size_t j = 0; j < c; j++) {
        set(i, j, rhs.get(i, j));
      }
    }
  }
  return *this;
}


IntMatrix::IntMatrix(IntMatrix && rhs) noexcept: r(rhs.rows()), c(rhs.cols()),
                                                 data(rhs.data)
{
  rhs.data.data = nullptr;
}


IntMatrix & IntMatrix::operator=(IntMatrix && rhs) noexcept
{
  if (this != &rhs) {
    data = rhs.data;
    r = rhs.rows();
    c = rhs.cols();
    for (size_t i = 0; i < r; i++) {
      for (size_t j = 0; j < c; j++) {
        set(i, j, rhs.get(i, j));
      }
    }
  }
  return *this;
}


IntMatrix::IntMatrix(): r(0), c(0), data(IntArray())
{
}


size_t IntMatrix::rows() const noexcept
{
  return r;
}


size_t IntMatrix::cols() const noexcept
{
  return c;
}


int IntMatrix::get(const size_t i, const size_t j) const noexcept
{
  return data.get(i * cols() + j);
}


void IntMatrix::set(const size_t i, const size_t j, int value) noexcept
{
  data.set(i * cols() + j, value);
}


void IntMatrix::read(std::istream & input)
{
  input >> r >> c;
  data = IntArray(r * c, 0);
  int current = 0;
  for (size_t i = 0; i < rows(); ++i) {
    for (size_t j = 0; j < cols(); ++j) {
      input >> current;
      set(i, j, current);
    }
  }
  if (!input) {
    throw std::invalid_argument("Error reading from file");
  }
}


void IntMatrix::print(std::ostream & output) const noexcept
{
  for (size_t i = 0; i < rows(); ++i) {
    output << get(i, 0);
    for (size_t j = 1; j < cols(); ++j) {
      output << " " << get(i, j);
    }
    output << "\n";
  }
}


void IntMatrix::insert_row(const size_t row, int value)
{
  IntArray temp = IntArray((rows() + 1) * cols(), 0);
  for (size_t i = 0; i < rows() + 1; ++i) {
    for (size_t j = 0; j < cols(); ++j) {
      if (i < row) {
        temp.set(i * cols() + j, get(i, j));
      } else if (i == row) {
        temp.set(i * cols() + j, value);
      } else if (i > row) {
        temp.set(i * cols() + j, get(i - 1, j));
      }
    }
  }
  r++;
  data = temp;
}


void IntMatrix::insert_row(const size_t row)
{
  insert_row(row, 0);
}


void IntMatrix::insert_column(const size_t col, int value)
{
  IntArray temp = IntArray(rows() * (cols() + 1), 0);
  for (size_t i = 0; i < rows(); ++i) {
    for (size_t j = 0; j < cols() + 1; ++j) {
      if (j < col) {
        temp.set(i * (cols() + 1) + j, get(i, j));
      } else if (j == col) {
        temp.set(i * (cols() + 1) + j, value);
      } else if (j > col) {
        temp.set(i * (cols() + 1) + j, get(i, j - 1));
      }
    }
  }
  c++;
  data = temp;
}


void IntMatrix::insert_column(const size_t col)
{
  insert_column(col, 0);
}
