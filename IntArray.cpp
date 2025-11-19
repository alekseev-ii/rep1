#include "IntArray.h"

#include <stdexcept>

IntArray::IntArray(size_t k, int v): size(k),
                                     data(new int[k])
{
  for (size_t i = 0ull; i < size; ++i) {
    data[i] = v;
  }
}


IntArray::~IntArray()
{
  delete[] data;
}


IntArray & IntArray::operator=(IntArray const & rhs)
{
  if (this != &rhs) {
    size = rhs.size;
    delete[] data;
    data = new int[size];
    for (size_t i = 0ull; i < size; ++i) {
      data[i] = rhs.data[i];
    }
  }
  return *this;
}

IntArray::IntArray(const IntArray & rhs): size(rhs.get_size()),
                                          data(new int[get_size()])
{
  for (size_t i = 0; i < size; ++i) {
    data[i] = rhs.data[i];
  }
}


IntArray::IntArray(IntArray && rhs) noexcept: data(rhs.data),
                                              size(rhs.get_size())
{
  rhs.data = nullptr;
}

IntArray & IntArray::operator=(IntArray && rhs) noexcept
{
  if (this != &rhs) {
    delete[] data;
    data = rhs.data;
    size = rhs.get_size();
    rhs.data = nullptr;
  }
  return *this;
}

size_t IntArray::get_size() const noexcept
{
  return size;
}


bool IntArray::empty() const noexcept
{
  return size == 0;
}


void IntArray::add_front(int i)
{
  int * temp = new int[size + 1];
  temp[0] = i;
  for (size_t j = 1ull; j < size + 1; ++j) {
    temp[j] = data[j - 1];
  }
  delete[] data;
  data = temp;
  ++size;
}


void IntArray::add_back(int i)
{
  int * temp = new int[size + 1];
  for (size_t j = 0ull; j < size; ++j) {
    temp[j] = data[j];
  }
  temp[size] = i;
  delete[] data;
  data = temp;
  ++size;
}


void IntArray::insert(const size_t id, int i)
{
  int * temp = new int[size + 1];
  for (size_t j = 0ull; j < size; ++j) {
    size_t new_j = j < id ? j : j + 1;
    temp[new_j] = data[j];
  }
  temp[id] = i;
  delete[] data;
  data = temp;
  ++size;
}


int IntArray::get(const size_t id) const noexcept
{
  return data[id];
}


int IntArray::get_front() const noexcept
{
  return data[0];
}


int IntArray::get_back() const noexcept
{
  return data[size - 1];
}


void IntArray::set(const size_t id, int i) noexcept
{
  data[id] = i;
}


void IntArray::del(const size_t id)
{
  int * temp = new int[size - 1];
  for (size_t j = 0ull; j < size; ++j) {
    size_t new_j = j < id ? j : j - 1;
    temp[new_j] = data[j];
  }
  delete[] data;
  data = temp;
  --size;
}

int IntArray::pop_front()
{
  int res = get_front();
  del(0);
  return res;
}


int IntArray::pop_back()
{
  int res = get_back();
  del(size - 1);
  return res;
}


void IntArray::add(const IntArray & a)
{
  int * temp = new int[size + a.get_size()];
  for (size_t j = 0ull; j < size + a.get_size(); ++j) {
    if (j < size) {
      temp[j] = data[j];
    } else {
      temp[j] = a.data[j - size];
    }
  }
  delete[] data;
  data = temp;
  size += a.get_size();
}
