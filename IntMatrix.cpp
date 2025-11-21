#include "IntMatrix.h"


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
        data.set(i * c + j, rhs.get(i, j));
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
        data.set(i * c + j, rhs.get(i, j));
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
    r = rhs.r;
    c = rhs.c;
    for (size_t i = 0; i < r; i++) {
      for (size_t j = 0; j < c; j++) {
        data.set(i * c + j, rhs.get(i, j));
      }
    }
  }
  return *this;
}


IntMatrix::IntMatrix() : r(0), c(0), data(IntArray())
{
}

