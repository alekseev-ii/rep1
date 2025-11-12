#include <iostream>

struct IntArray {
  size_t size;
  int * data;

  IntArray(int i);
  ~IntArray();
  IntArray & operator=(const IntArray& rhs);
  IntArray(IntArray && rhs) noexcept;
  IntArray & operator=(IntArray && rhs) noexcept;

  void add(int i);
  int get(size_t id) const noexcept;
  int last() const noexcept;
  size_t get_size() const noexcept;
};

int main()
{
  int next = 0;
  std::cin >> next;
  try {
    IntArray a(next);

    while (std::cin >> next) {
      a.add(next);
    }
    if (std::cin.fail() && !std::cin.eof()) {
      return 1;
    }

    size_t count = 1ull;
    if (!a.last()) {
      return 2;
    }
    for (size_t i = 0ull; i < a.get_size() - 1; ++i) {
      int d = a.get(i);
      count += !(d % a.last());
    }
    std::cout << count << "\n";
  } catch (const std::exception & e) {
    return 2;
  }
}

IntArray::~IntArray()
{
  delete[] data;
}

IntArray::IntArray(int i) : data(new int[1]),
                            size(1)
{
  data[0] = i;
}

IntArray & IntArray::operator=(const IntArray& rhs)
{
  if (this != &rhs) {
    int * temp = new int[rhs.get_size()];
    for (size_t i = 0ull; i < rhs.get_size(); ++i) {
      temp[i] = rhs.get(i);
    }
    delete[] data;
    data = temp;
    size = rhs.get_size();
  }
}

IntArray::IntArray(IntArray && rhs) noexcept : data(rhs.data), size(rhs.get_size())
{
  rhs.data = nullptr;
}

IntArray & IntArray::operator=(IntArray && rhs) noexcept
{
  delete[] data;
  data = rhs.data;
  size = rhs.get_size();
  rhs.data = nullptr;
  return *this;
}

int IntArray::get(size_t id) const noexcept
{
  return data[id];
}

size_t IntArray::get_size() const noexcept
{
  return size;
}

int IntArray::last() const noexcept
{
  return get( get_size() - 1);
}

void IntArray::add(int i)
{
  int * temp = new int[get_size() + 1];
  for (size_t j = 0; j < get_size(); ++j) {
    temp[j] = get(j);
  }
  temp[get_size()] = i;
  delete[] data;
  data = temp;
  ++size;
}

