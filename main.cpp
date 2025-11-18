#include <cstddef>
#include <iostream>

namespace alekseev {
  struct IntArray {
    int * data;
    size_t size;
    IntArray();
    IntArray(size_t k, int v);
    IntArray(const IntArray & rhs);
    ~IntArray();
    IntArray & operator=(IntArray const & rhs);
    size_t get_size() const noexcept;
    bool empty() const noexcept;
    void add_front(int i);
    void add_back(int i);
    void insert(size_t id, int i);
    int get(size_t id) const;
    int get_front() const noexcept;
    int get_back() const noexcept;
    void set(size_t id, int i);
    void del(size_t id);
    int pop_back();
    int pop_front();
    void add(const IntArray & a);
  };
}


int main()
{
}


alekseev::IntArray::IntArray(): data(nullptr),
                                size(0)
{
}


alekseev::IntArray::IntArray(size_t k, int v): size(k),
                                               data(new int[get_size()])
{
  for (size_t i = 0ull; i < size; ++i) {
    data[i] = v;
  }
}


alekseev::IntArray::IntArray(const IntArray & rhs): size(rhs.get_size()),
                                                    data(new int[get_size()])
{
  for (size_t i = 0; i < size; ++i) {
    data[i] = rhs.data[i];
  }
}


alekseev::IntArray::~IntArray()
{
  delete[] data;
}


alekseev::IntArray & alekseev::IntArray::operator=(IntArray const & rhs)
{
  size = rhs.get_size();
  delete[] data;
  data = new int[get_size()];
  for (size_t i = 0ull; i < get_size(); ++i) {
    data[i] = rhs.get(i);
  }
  return *this;
}


// update from here

size_t alekseev::IntArray::get_size() const noexcept
{
  return size;
}


bool alekseev::IntArray::empty() const noexcept
{
  return size == 0;
}


void alekseev::IntArray::add_front(int i)
{
  IntArray temp = *this;
  delete[] data;
  size++;
  data = new int[size];
  data[0] = i;
  for (size_t j = 1ull; j < size; ++j) {
    data[j] = temp.data[j - 1];
  }
}


void alekseev::IntArray::add_back(int i)
{
  IntArray temp = *this;
  delete[] data;
  size++;
  data = new int[size];
  data[size - 1] = i;
  for (size_t j = 0ull; j < size - 1; ++j) {
    data[j] = temp.data[j];
  }
}


void alekseev::IntArray::insert(size_t id, int i)
{
  if (id > size) {
    throw std::out_of_range("id out of range");
  }
  IntArray temp = *this;
  delete[] data;
  size++;
  data = new int[size];
  for (size_t j = 0ull; j < size; ++j) {
    if (j == id) {
      data[j] = i;
    } else {
      size_t true_j = j < id ? j : j - 1;
      data[j] = temp.data[true_j];
    }
  }
}


int alekseev::IntArray::get(size_t id) const
{
  if (id >= size) {
    throw std::out_of_range("id out of range");
  }
  return data[id];
}


int alekseev::IntArray::get_front() const noexcept
{
  return data[0];
}


int alekseev::IntArray::get_back() const noexcept
{
  return data[size - 1];
}


void alekseev::IntArray::set(size_t id, int i)
{
  if (id >= size) {
    throw std::out_of_range("id out of range");
  }
  data[id] = i;
}


void alekseev::IntArray::del(size_t id)
{
  IntArray temp = *this;
  delete[] data;
  size--;
  data = new int[size];
  for (size_t j = 0ull; j < size; ++j) {
    size_t true_j = j < id ? j : j + 1;
    data[j] = temp.data[true_j];
  }
}


int alekseev::IntArray::pop_back()
{
  int res = this->get_back();
  this->del(size - 1);
  return res;
}


int alekseev::IntArray::pop_front()
{
  int res = this->get_front();
  this->del(0);
  return res;
}


void alekseev::IntArray::add(const IntArray & a)
{
  IntArray temp = *this;
  size += a.size;
  delete[] data;
  data = new int[size];
  for (size_t j = 0ull; j < size; ++j) {
    if (j < temp.size) {
      data[j] = temp.data[j];
    } else {
      data[j] = a.data[j - temp.size];
    }
  }
}
