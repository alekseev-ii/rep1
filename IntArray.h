#ifndef INTARRAY_H
#define INTARRAY_H
#include <cstddef>

struct IntArray {
  int * data;
  size_t size;

  ~IntArray();
  IntArray(const IntArray & rhs);
  IntArray & operator=(const IntArray & rhs);
  IntArray(IntArray && rhs) noexcept;
  IntArray & operator=(IntArray && rhs) noexcept;
  IntArray();
  IntArray(size_t k, int v);

  size_t get_size() const noexcept;
  bool empty() const noexcept;
  void add_front(int i);
  void add_back(int i);
  void insert(const size_t id, int i);
  int get(const size_t id) const noexcept;
  int get_front() const noexcept;
  int get_back() const noexcept;
  void set(const size_t id, int i) noexcept;
  void del(const size_t id);
  int pop_front();
  int pop_back();
  void add(const IntArray & a);
};

#endif