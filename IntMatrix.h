#ifndef INTMATRIX_H
#define INTMATRIX_H
#include <cstddef>
#include "IntArray.h"
#include <iostream>

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
  int get(const size_t i, const size_t j) const noexcept;
  void set(const size_t i, const size_t j, int value) noexcept;
  void read(std::istream & input);
  void print(std::ostream & output) const noexcept;
  void insert_row(const size_t row, int value);
};

#endif
