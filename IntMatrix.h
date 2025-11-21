#ifndef INTMATRIX_H
#define INTMATRIX_H
#include <cstddef>
#include "IntArray.h"

struct IntMatrix {
  size_t r;
  size_t c;
  IntArray data;


  ~IntMatrix();
  IntMatrix(const IntMatrix & rhs);
  IntMatrix & operator=(const IntMatrix & rhs);
  IntMatrix(IntMatrix && rhs) noexcept;
  IntMatrix & operator=(IntMatrix && rhs) noexcept;
  IntMatrix();


  size_t rows() const noexcept;
  size_t cols() const noexcept;
  int get (size_t i, size_t j) const noexcept;
};

#endif
