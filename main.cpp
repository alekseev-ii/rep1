#include <cstddef>
#include <iostream>

namespace alekseev {
  struct IntArray {
    int * data;
    size_t size;
    IntArray();
    IntArray(size_t k, int v);
    ~IntArray();
    IntArray & operator=(IntArray const & rhs);
    size_t get_size() const;
    bool empty() const;
    void add_front(int i);
    void add_back(int i);
    void insert(size_t id, int i);
    int get(size_t id) const;
    int get_front() const;
    int get_back() const;
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

alekseev::IntArray::IntArray()
{
  data = nullptr;
  size = 0;
}

alekseev::IntArray::IntArray(size_t k, int v)
{
  size = k;
  data = new int[size];
  for (size_t i = 0ull; i < size; ++i) {
    data[i] = v;
  }
}

alekseev::IntArray::~IntArray()
{
  delete[] data;
}

alekseev::IntArray & alekseev::IntArray::operator=(alekseev::IntArray const & rhs)
{
  size = rhs.size;
  delete[] data;
  data = new int[size];
  for (size_t i = 0ull; i < size; ++i) {
    data[i] = rhs.data[i];
  }
  return *this;
}

size_t alekseev::IntArray::get_size() const
{
  return size;
}

bool alekseev::IntArray::empty() const
{
  return size == 0;
}

void alekseev::IntArray::add_front(int i)
{
  alekseev::IntArray temp = *this;
  delete[] data;
  size++;
  data = new int[size];
  data[0] = i;
  for (size_t j = 1ull; j < size; ++j) {
    data[j] = temp.data[j];
  }

}

void alekseev::IntArray::add_back(int i)
{
  alekseev::IntArray temp = *this;
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
  if (id > size || id < 0) {
    throw std::out_of_range("id out of range");
  }
  alekseev::IntArray temp = *this;
  delete[] data;
  size++;
  data = new int[size];
  for (size_t j = 0ull; j < size; ++j) {
    if (j == id) {
      data[j] = i;
    }
    else {
      size_t true_j = j ? j < id : j + 1;
      data[j] = temp.data[true_j];
    }
  }
}

int alekseev::IntArray::get(size_t id) const
{
  if (id >= size || id < 0) {
    throw std::out_of_range("id out of range");
  }
  return data[id];
}

int alekseev::IntArray::get_front() const
{
  return data[0];
}

int alekseev::IntArray::get_back() const
{
  return data[size - 1];
}

void alekseev::IntArray::set(size_t id, int i)
{
  if (id >= size || id < 0) {
    throw std::out_of_range("id out of range");
  }
  data[id] = i;
}

void alekseev::IntArray::del(size_t id)
{
  alekseev::IntArray temp = *this;
  delete[] data;
  size--;
  data = new int[size];
  for (size_t j = 0ull; j < size; ++j) {
    size_t true_j = j ? j < id : j + 1;
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

void alekseev::IntArray::add(const alekseev::IntArray & a)
{
  alekseev::IntArray temp = *this;
  size += a.size;
  delete[] data;
  data = new int[size];
  for (size_t j = 0ull; j < size; ++j) {
    if (j < temp.size) {
      data[j] = temp.data[j];
    } else {
      data[j] = a.data[j];
    }
  }
}